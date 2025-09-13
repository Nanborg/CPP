#!/bin/bash
set -euo pipefail
IFS=$'\n\t'
LC_ALL=C

NAME=phonebook

# Helpers
fail(){ echo "❌ $1"; exit 1; }
pass(){ echo "✅ $1"; }
LAST_OUT=""
run(){ # run "Label" $'input\n...'
  local label="$1"; shift
  LAST_OUT="out_${label// /_}.txt"
  echo "=== $label ==="
  printf "%s" "$1" | ./"$NAME" | tee "$LAST_OUT"
}
must_contain(){ grep -E -q "$2" "$1" || fail "Manque: $2 dans $1"; }
must_not_contain(){ ! grep -E -q "$2" "$1" || fail "Ne doit pas contenir: $2 dans $1"; }
must_contain_fixed(){ grep -F -q "$2" "$1" || fail "Manque: $2 dans $1"; }
must_have_at_least_lit(){ # file literal min_count
  local c
  c=$(grep -oF "$2" "$1" | wc -l | tr -d ' ')
  [[ "$c" -ge "$3" ]] || fail "Moins de $3 occurrences de: $2 dans $1 (=$c)"
}

# Build fresh
make -s re

echo "=== Lancement des tests automatiques ==="

# T1 : commande inconnue -> ignorée (re-prompt)
run "Test 1 : Commande inconnue" $'BLA\nEXIT\n'
must_have_at_least_lit "$LAST_OUT" 'PhoneBook> ' 2
pass "T1 inconnu OK"

# T2 : SEARCH vide -> juste l’entête, pas de demande d’index
run "Test 2 : SEARCH vide" $'SEARCH\nEXIT\n'
must_contain_fixed "$LAST_OUT" 'INDEX|FIRST NAME| LAST NAME|  NICKNAME'
must_not_contain "$LAST_OUT" 'Enter an index to see details'
pass "T2 SEARCH vide OK"

# T3 : ADD avec champs vides -> re-prompt jusqu’à non-vide ; puis SEARCH détail
run "Test 3 : ADD non vides + détail" $'ADD\n\n\ns\n\nasd\nsad\n12345\n   \n\nX\nSEARCH\n1\nEXIT\n'
must_have_at_least_lit "$LAST_OUT" 'Enter First Name: ' 3
must_have_at_least_lit "$LAST_OUT" 'Enter Last Name: ' 2
must_have_at_least_lit "$LAST_OUT" 'Enter Nickname: ' 1
must_have_at_least_lit "$LAST_OUT" 'Enter Phone Number: ' 1
must_have_at_least_lit "$LAST_OUT" 'Enter Darkest Secret: ' 3
must_contain "$LAST_OUT" '^\s*1\|\s*s\|\s*asd\|\s*sad$'
must_contain "$LAST_OUT" 'First Name:[[:space:]]+s'
must_contain "$LAST_OUT" 'Darkest Secret:[[:space:]]+X'
pass "T3 non-vide + détail OK"


# T4 : Index invalide (non numérique)
run "Test 4 : Index alpha invalide" $'ADD\nA\nB\nC\n111\nS\nSEARCH\nabc\nEXIT\n'
must_contain_fixed "$LAST_OUT" 'Invalid index.'
pass "T4 index alpha invalide OK"

# T5 : Index invalide (hors bornes)
run "Test 5 : Index hors bornes" $'ADD\nFoo\nBar\nNick\n000\nsec\nSEARCH\n999\nEXIT\n'
must_contain_fixed "$LAST_OUT" 'Invalid index.'
pass "T5 index hors bornes OK"


# T6 : Troncature 10 colonnes (chaînes >10 -> point final)
run "Test 6 : Troncature colonnes" $'ADD\nVeryLongName\nLooooooooooong\nNickOverTen++\n000\nsec\nSEARCH\nEXIT\n'
must_contain "$LAST_OUT" '\|VeryLongN\.\|'     # first name
must_contain "$LAST_OUT" '\|Loooooooo\.\|'     # last name
must_contain "$LAST_OUT" '\|NickOverT\.\s*$'   # nickname
pass "T6 troncature OK"

# T7 : Tableau circulaire (9 ajouts -> le plus ancien remplacé)
run "Test 7 : Tableau circulaire" $'ADD\nc1\nl1\nn1\np1\ns1\nADD\nc2\nl2\nn2\np2\ns2\nADD\nc3\nl3\nn3\np3\ns3\nADD\nc4\nl4\nn4\np4\ns4\nADD\nc5\nl5\nn5\np5\ns5\nADD\nc6\nl6\nn6\np6\ns6\nADD\nc7\nl7\nn7\np7\ns7\nADD\nc8\nl8\nn8\np8\ns8\nADD\nc9\nl9\nn9\np9\ns9\nSEARCH\nEXIT\n'
must_contain "$LAST_OUT" '^\s*1\|\s*c9\|\s*l9\|\s*n9$'
pass "T7 ring buffer OK"

echo "=== Tests terminés ==="
