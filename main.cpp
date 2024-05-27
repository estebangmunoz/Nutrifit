/**
 * @file main.cpp
 * @author Carlos Taillefer
 * @brief main file of the project Nutrifit
 * @version 0.1
 * @date 2024-05-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Exercises.hpp"
#include "filemanagment.hpp"
#include "routineGenerator.hpp"
#include "WorkoutTable.hpp"
#include "Food.hpp"
#include "FoodList.hpp"
#include "Meal.hpp"
#include "AuxiliarMethods.hpp"
#include "UserStatus.hpp"
#include "Day.hpp"
#include "Diet.hpp"
#include "publication.hpp"
#include "user.hpp"

using namespace std;

int main() {
    try {
        User newUser("", "", "", 0.0, 0.0);
        string opcion;
        string name, email, password;
        float weight, height;
        bool option = false;

        cout << "Welcome to Nutrifit!\n";
        cout << "Choose an option:\n";
        cout << "1. Check in\n";
        cout << "2. Log in\n";
        cout << "Option: ";
        cin >> opcion;
        cin.ignore();

        while (!option) {
            
            if (opcion == "1") {
                cout << endl << "What's your Name?: ";
                getline(cin,name);
                cout << endl << "What's your email?: ";
                cin >> email;
                cout << endl << "Choose a password: ";
                cin >> password;
                cout << endl << "How much do you weight?: ";
                cin >> weight;
                cout << endl << "What's your height?: ";
                cin >> height;

                User newUser(name, email, password, weight, height);
                newUser.registerUser();
                option = true;
            } else if (opcion == "2") {
                string email, password;
                cout << endl << "Please enter your email: ";
                cin >> email;
                cout << endl << "Password: ";
                cin >> password;

                if (User::login(email, password)) {
                    cout << "Login successful!\n";

                    newUser = User::getUserByEmail(email);
                    weight = newUser.getWeight();

                    option = true;

                } else {
                    cout << "Entered user does not exist." << endl;
                    cout << "Do you want to register? (y/n)" << endl;
                    string option1;
                    cin >> option1;

                    if (option1 == "n") {
                        option = true;
                        return 0;
                    } else if (option1 == "y") {
                        opcion = "1";
                    } else {
                        cout << "Error";
                        return 0;
                    }
                }
            } else {
                cout << "Invalid option";
                return 0;
            }
        }
        
        int opMenu;

        while(opMenu!=5){
            cout << endl << "###############################" << endl;
            cout << "            MENU             " << endl;
            cout << "###############################" << endl;
            cout << "Hi " << name << "!" << endl;
            cout << "What do you want to do?" << endl;
            cout << "1. Make diet planning" << endl;
            cout << "2. Make routine" << endl;
            cout << "3. Look other users" << endl;
            cout << "4. Make a publication" << endl;
            cout << "5. Log out" << endl;
            cout << "Option: ";
            cin >> opMenu;
            

            while(opMenu<1 || opMenu>5){
            cout << "Please introduce a valid number: ";
            cin >> opMenu;
            }

            switch (opMenu) {
                case 1:{
                    FoodList foodList;

                    foodList.importData("foodData1.csv");

                    UserStatus user(weight);
                    float goalKcals = user.kCalsCalculator();

                    cout << endl << "How many days long do you want the planning of your diet to be? ";
                    int numberOfDays;
                    cin >> numberOfDays;

                    cout << endl << "Preparing your diet. This may take a few minutes..." << endl << endl;

                    Diet diet(numberOfDays,goalKcals);
                    diet.makeDiet();

                    cout << endl << "How would you like the file to be named? It will be saved in the same file as the executable: ";
                    string fileName;
                    cin >> fileName;

                    diet.writeDiet(fileName);
                    break;
                }
                case 2:{
                    vector<Exercise> push = readFile("Empujes.csv");
                    vector<Exercise> pull = readFile("Tracciones.csv");
                    vector<Exercise> legs = readFile("Leg.csv");
                    vector<Exercise> list = readFile("ListaEjercicios.csv");
                    workOutTable(push, pull, legs, list);
                    break;
                }
                case 3: {
                    vector<string> usuarios = User::getAllUserNames();
                    if (usuarios.empty()) {
                        cout << "There are no registered users." << endl;
                    } else {
                        cout << "Registered users:" << endl;
                        for (size_t i = 0; i < usuarios.size(); ++i) {
                            cout << i + 1 << ". " << usuarios[i] << endl;
                        }
                        cout << "Select a user with the number: ";
                        size_t seleccion;
                        cin >> seleccion;

                        if (seleccion > 0 && seleccion <= usuarios.size()) {
                            User seleccionado(usuarios[seleccion - 1], "", "", 0.0, 0.0);
                            seleccionado.showUserPublications();
                        } else {
                            cout << "Error." << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    string title, ingredientName;
                    int calories, proteins;
                    cout << "Enter the title of the publication: ";
                    cin >> title;
                    Publicacion newPublication(title);
                    cout << "Enter the ingredients (name, calories, proteins), enter 'done' when finished:" << endl;
                    while (true) {
                        cout << "Ingredient name: ";
                        cin >> ingredientName;
                        if (ingredientName == "done") break;
                        cout << "Calories: ";
                        cin >> calories;
                        cout << "Proteins: ";
                        cin >> proteins;
                        newPublication.addingredients(ingredientName, calories, proteins);
                    }
                
                    ofstream publicationFile("publications.txt", ios::app);
                    if (!publicationFile.is_open()) {
                        throw runtime_error("Error opening publication file");
                    }
                    publicationFile << title << endl;
                    publicationFile.close();
                    cout << "Publication created successfully." << endl;
                    break;
                }
                case 5:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "Invalid option" << endl;
                    break;
            }
        }


    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}



