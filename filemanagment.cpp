/**
 * @file filemanagment.cpp
 * @author Jorge Cavero Cañabate
 * @brief File intended for grouping functions related to file management (input/output).
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "filemanagment.hpp"
#include "Exercises.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


/**
 * @brief Generates a vector with exercise-type objects, whose attributes are extracted from the provided .csv.
 * 
 * @param fileName 
 * @return vector<Exercise> 
 */
vector<Exercise> readFile(string fileName) {
    vector<Exercise> exercises;
    ifstream archivo(fileName);
    string line;

    if (archivo.is_open()) {
        while (getline(archivo, line)) {
            stringstream ss(line);
            Exercise e;
            string name, muscle_group, pattern, estimated_minutes_str, sets_str;
            getline(ss, name, ',');
            getline(ss, muscle_group, ',');
            getline(ss, pattern, ',');
            getline(ss, estimated_minutes_str, ',');
            getline(ss, sets_str, ',');
            e.setName(name);
            e.setMucleGroup(muscle_group);
            e.setPattern(pattern);

            //`Try-catch` structure since we are trying to convert a string to an integer.
            try {
                int estimated_minutes = stoi(estimated_minutes_str);
                int sets = stoi(sets_str);
                e.setMinutes(estimated_minutes);
                e.setSets(sets);
            } catch (const std::invalid_argument& e) {
                continue;
            }

            // Add all exercises to the vector.
            exercises.push_back(e);
        }
    } else {
        cout << "\n No se ha podido abrir el archivo.\n";
    }

    return exercises;
}

/**
 * @brief Function intended for writing full-body style routine to a .txt file. 
 * 
 * @param fileName 
 * @param routine 
 * @param day 
 */
void writeRoutineFB(string fileName, string routine, int day){
    ofstream file;
    file.open(fileName, ios_base::out | ios_base::app);
    if(file.is_open()){
        file << "DAY " << day + 1  << "\n";
        file << "EJERCICIO\tSERIES\tGRUPO MUSCULAR\tPATRÓN DE MOVIMIENTO\n";
        file << routine;
        file << "-------------------------------------------------------------------------\n";
    }else{
        cout <<"No se ha podido abrir el archivo";
    }
}

/**
 * @brief Function intended for writing push-pull-legs style routine to a .txt file. 
 * 
 * @param fileName 
 * @param routine 
 * @param day 
 * @param split 
 */
void writeRoutinePPL(string fileName, string routine, string day, string split){
    ofstream file;
    file.open(fileName, ios_base::out |ios_base::app);
    if(file.is_open()){
        file << split;
        if(day == "PULLA"){
            file << "PULL A\n ";
            file << "EJERCICIO\tSERIES\tGRUPO MUSCULAR\tPATRÓN DE MOVIMIENTO\n";
            file << routine;
        }
        if(day == "PULLB"){
            file << "PULL B\n";
            file << "EJERCICIO\tSERIES\tGRUPO MUSCULAR\tPATRÓN DE MOVIMIENTO\n";
            file << routine;
        }
        if(day == "PUSHA"){
            file << "PUSH A\n";
            file << "EJERCICIO\tSERIES\tGRUPO MUSCULAR\tPATRÓN DE MOVIMIENTO\n";
            file << routine;
        }
        if(day == "PUSHB"){
            file << "PUSH B\n";
            file << "EJERCICIO\tSERIES\tGRUPO MUSCULAR\tPATRÓN DE MOVIMIENTO\n";
            file << routine;
        }
        if(day == "LEGA"){
            file << "LEG A\n";
            file << "EJERCICIO\tSERIES\tGRUPO MUSCULAR\tPATRÓN DE MOVIMIENTO\n";
            file << routine;
        }
        if(day == "LEGB"){
            file << "LEG B\n";
            file << "EJERCICIO\tSERIES\tGRUPO MUSCULAR\tPATRÓN DE MOVIMIENTO\n";
            file << routine;
        }
        file << "-------------------------------------------------------------------------\n";
    }
}