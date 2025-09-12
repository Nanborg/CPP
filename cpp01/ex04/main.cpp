/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolsan <nicolsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:20:23 by nicolsan          #+#    #+#             */
/*   Updated: 2025/09/09 17:47:32 by nicolsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static void replace_all(std::string &s, const std::string &to_find, const std::string &to_replace)
{
    if (to_find.empty())
        return;

    std::string::size_type pos = 0;
    while ((pos = s.find(to_find, pos)) != std::string::npos)
    {
        s.erase(pos, to_find.length());
        s.insert(pos, to_replace);
        pos += to_replace.length();
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./replace <filename> <string_to_find> <string_to_replace>" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        return 1;
    }
    std::string content;
    std::string line;
    while (std::getline(inputFile, line))
    {
        content += line;
        if (!inputFile.eof())
            content += '\n';
    }
    inputFile.close();
    replace_all(content, s1, s2);
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Could not create output file: " << filename + ".replace" << std::endl;
        return 1;
    }
    outputFile << content;
    outputFile.close();
    return 0;
}

/*
replace_all(s, s1, s2) :
- Remplace toutes les occurrences de s1 par s2 dans s.
- Ignore si s1 est vide.
- Utilise erase/insert (pas std::string::replace).
- Avance pos de s2.size() pour éviter les boucles si s2 contient s1.

main :
- Attend 3 arguments : <fichier> <à_trouver> <remplacement>.
- Lit le fichier en mémoire en conservant les '\n'.
- Appelle replace_all puis écrit <fichier>.replace.
- Gère les erreurs d’ouverture/écriture de fichiers.
*/

/*
Tests à faire :
1. Remplacement simple (mot existant).
2. Plusieurs occurrences remplacées.
3. Sensible à la Maj/Min ("The" ≠ "the").
4. Remplacer par chaîne vide (suppression).
5. Cas piégeux : s2 contient s1 (évite boucle infinie).
6. Remplacement dans une sous-chaîne.
7. Chaîne absente (copie identique).
8. Erreurs : mauvais arguments, fichier inexistant, sortie impossible.
*/
