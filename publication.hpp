/**
 * @file publication.hpp
 * @author Carlos Taillefer
 * @brief .hpp file of class Publication
 * @version 0.1
 * @date 2024-05-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Publicacion {
private:
    string title;
    vector<pair<string, pair<int, int>>> ingredient;
    vector<string> comments;
    set<string> likes;

public:

    Publicacion(const string& _title);

    void addingredients(const string& nombre, int calorias, int proteinas);

    void mostrarReceta();

    void addLike(const string& user);

    void addComment(const string& comment);
    
};

#endif // PUBLICACION_H
