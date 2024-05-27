/**
 * @file publication.cpp
 * @author Carlos Taillefer
 * @brief .cpp file of class Publication
 * @version 0.1
 * @date 2024-05-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "publication.hpp"

Publicacion::Publicacion(const string& _title) : title(_title) {}

void Publicacion::addingredients(const string& nombre, int calorias, int proteinas) {
    ingredient.push_back(make_pair(nombre, make_pair(calorias, proteinas)));
}

void Publicacion::mostrarReceta() {
    cout << "Recipes : " << title << endl;
    cout << "ingredient : " << endl;
    for (const auto& ingrediente : ingredient) {
        cout << " - " << ingrediente.first << " : " << ingrediente.second.first << " calorías, "
                  << ingrediente.second.second << " proteínas" << endl;
    }
    cout << "Likes: " << likes.size() << endl;
    cout << "Comments:" << endl;
    for (const auto& comment : comments) {
        cout << "- " << comment << endl;
    }
}

void Publicacion::addLike(const string& user) {
    likes.insert(user);
}

void Publicacion::addComment(const string& comment) {
    comments.push_back(comment);
}

