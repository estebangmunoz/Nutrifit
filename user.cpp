/**
 * @file user.cpp
 * @author Carlos Taillefer
 * @brief .cpp file of class User
 * @version 0.1
 * @date 2024-05-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "user.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

User::User(const string name, const string email, const string password, const float weight, const float height) :
name(name), email(email), password(password), weight(weight), height(height){}

float User::getWeight() const{
    return weight;
}

float User::getHeight() const{
    return height;
}

void User::setWeight(float newWeight){
    weight=newWeight;
}

void User::setHeight(float newHeight){
    height=newHeight;
}

void User::registerUser() {
    ofstream archivo("usuarios.txt", ios::app);
    if (!archivo.is_open()){
        throw runtime_error("Error al abrir el archivo de registro");
    }
    if (archivo.is_open()) {
        archivo << name << "," << email << "," << password << "," << weight << "," << height << "\n";
        archivo.close();
        cout << endl << "Your user has been registered correctly!\n";
    } else {
        cout << "could not be open ERROR.\n";
    }
}

bool User::userExist(const string& email) {
    ifstream archivo("usuarios.txt");
    
    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(email);
        if (pos != string::npos) {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

bool User::login(const string& email, const string& password) {
    ifstream archivo("usuarios.txt");
    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(email);
        if (pos != string::npos) {
            size_t passPos = linea.find(password, pos + email.length() + 1);
            if (passPos != string::npos) {
                archivo.close();
                return true;
            }
        }
    }
    archivo.close();
    return false;
}

User User::getUserByEmail(string email){
    ifstream file("usuarios.txt");
    string line;

    while(getline(file,line)){
        stringstream ss(line);
        string name;
        string fileEmail;
        string password;
        float weight;
        float height;

        getline(ss, name, ',');
        getline(ss, fileEmail, ',');
        getline(ss, password, ',');
        ss >> weight;
        ss.ignore(1);
        ss>>height;

        if (fileEmail == email){
            file.close();
            return User(name,fileEmail,password,weight,height);
        }
    }

    file.close();
    throw runtime_error("User not found");
}

vector<string> User::getAllUserNames() {
    ifstream archivo("usuarios.txt");
    vector<string> nombres;

    if (!archivo.is_open()) {
        cout << "could not be open ERROR.\n";
        return nombres;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos_comma = linea.find(',');
        if (pos_comma != string::npos) {
            string name = linea.substr(0, pos_comma);
            nombres.push_back(name);
        }
    }

    archivo.close();
    return nombres;
}

void User::showUserPublications() const {
    ifstream archivo(name + "_publicaciones.txt");

    if (!archivo.is_open()) {
        cout << "There are no posts for " << name << ".\n";
        return;
    }

    string linea;
    cout << "Post of " << name << ":\n";
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

