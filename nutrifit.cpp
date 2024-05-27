!/**
 * @file nutrifit.cpp
 * @author Jorge Cavero Cañabate
 * @brief Main file, implementing all hpp needed.
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Exercises.hpp"
#include "routineGenerator.hpp"
#include "filemanagment.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;


//Para comprobar que el usuario ha consumido lo programado, y en caso contrario pueda introducir manualmente la cantidad consumida.

void workOutTable(vector<Exercise> ph, vector<Exercise> pl, vector<Exercise> l, vector<Exercise> eL);

int main(){
    vector<Exercise> push = readFile("Empujes.csv");
    vector<Exercise> pull = readFile("Tracciones.csv");
    vector<Exercise> legs = readFile("Leg.csv");
    vector<Exercise> list = readFile("ListaEjercicios.csv");
    workOutTable(push, pull, legs, list);
}

/**
 * @brief Main function that offers a menu for the user, for a easyer navigation through the exercise options.
 * 
 * @param push vector
 * @param pull vector
 * @param legs vecto 
 * @param FullExercisesList 
 */
void workOutTable(vector<Exercise> ph, vector<Exercise> pl, vector<Exercise> l, vector<Exercise> eL){
    int goal;
    int minutes;
    int days;
    //We ask the user for their goal in order to later select the exercises with an appropriate intensity for that goal.
    //For example, a person aiming to gain muscle mass should reach muscle failure (maximum intensity), while someone aiming to lose fat should have lower intensity.

    cout << "Please specify your goal in order to provide an appropriate table: \n";
    cout << "1- GAIN MUSCLE MASS\n";
    cout << "2- LOSE FAT\n";
    cout << "3- TONING/MAINTENANCE\n";
    cout << "0- EXIT\n";
    cout << "(Enter the number)\n";
    cin >> goal;
    while(goal < 0 || goal > 3){
        cout << "Invalid choice, choose again: ";
        cin >> goal;
        cout << "\n";
    }
    
    while(goal != 0){
        //We ask the user for the time they can dedicate to training daily to discard certain exercises and reduce sets and repetitions.
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Next, enter the maximum daily time in minutes you could dedicate to your training for a more personalized routine:\n";
        cin >> minutes;
        cout << "Finally please let us know the amount of days per week you are willing to train! (MAX: 5)\n Days: ";
        cin >> days;
        while(days > 5|| days <= 0){
            cout << "The amount selected is not valid, select a new one: "; 
            cin >> days;
            cout << "\n";
        }
         
        string fileName;
        if(minutes <= 60 || goal == 3){
            cout << "               YOUR MOST OPTIMAL SPLIT IS THE FULL BODY ROUTINE!\n";
            srand(time(0));
            int valor = 1 + rand() % (days -1 + 1);
            cout << "Insert a name for your rutine: ";
            cin >> fileName;
            for(int i = 0; i < days; i++){  
                writeRoutineFB(fileName + ".txt" , dailyRoutineGenerator(valor, minutes, eL),i);
            }
            cout << "Your routine has been succesfully generated!\n";
        }
        if(minutes > 60){
            cout << "               YOUR MOST OPTIMAL SPLIT IS THE PUSH-PULL-LEGS ROUTINE!\n";
            string split = generatePPLSplit();
            // generatePPLSplit();
            cout <<"Insert a name for your routine: ";
            cin >> fileName;
            cout <<"\n";
            if(split == "PUSH~A - PULL~A - REST - LEGS~A - PUSH~B - REST - PULL~B - LEGS~B"){
                writeRoutinePPL(fileName + ".txt", push(1, minutes, ph), "PUSHA", split);
                writeRoutinePPL(fileName + ".txt", pull(1, minutes, pl), "PULLA", "");
                writeRoutinePPL(fileName + ".txt", legs(1, minutes, l), "LEGA", "");
                writeRoutinePPL(fileName + ".txt", push(2, minutes, ph), "PUSHB", "");
                writeRoutinePPL(fileName + ".txt", pull(2, minutes, pl), "PULLB", "");
                writeRoutinePPL(fileName + ".txt", legs(2, minutes, l), "LEGB", "");
            }
            if(split == "PULL~A - PUSH~A - LEGS~A - REST - PULL~B - PUSH~B - REST - LEGS~B"){
                writeRoutinePPL(fileName + ".txt", pull(1, minutes, pl), "PULLA", "");
                writeRoutinePPL(fileName + ".txt", push(1, minutes, ph), "PUSHA", "");
                writeRoutinePPL(fileName + ".txt", legs(1, minutes, l), "LEGA", "");
                writeRoutinePPL(fileName + ".txt", push(2, minutes, ph), "PUSHB", "");
                writeRoutinePPL(fileName + ".txt", pull(2, minutes, pl), "PULLB", "");
                writeRoutinePPL(fileName + ".txt", legs(2, minutes, l), "LEGB", "");
            }
            if(goal == 2){
                cout << "Walk between 10-15k steps each day!\n";
            }
            cout << "Your routine has been succesfully generated!\n";
        }
        cout << "Do you want to continue? (y/n): ";
        string keepgoing;
        cin >> keepgoing;
        if(keepgoing == "n" || keepgoing == "N"){
            break;   b 
        }
        cout << "Please specify your goal in order to provide an appropriate table: \n";
        cout << "1- GAIN MUSCLE MASS\n";
        cout << "2- LOSE FAT\n";
        cout << "3- TONING/MAINTENANCE\n";
        cout << "0- EXIT\n";
        cout << "(Enter the number)\n";
        cin >> goal;   
        
    }
    cout << "Exiting...\n";
}
