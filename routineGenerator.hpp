/**
 * @file routineGenerator.hpp
 * @author Jorge Cavero Cañabate
 * @brief Provides the function declarations of the respective .cpp, in this case "routineGenerator.cpp"
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef ROUTINEGENERATOR_HPP
#define ROUTINEGENERATOR_HPP
#include "Exercises.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;



string dailyRoutineGenerator(int day, int time, vector<Exercise> ex);

string pull(int day, int time, vector<Exercise> p);

string push(int day, int time, vector<Exercise> p);

string legs(int day, int time, vector<Exercise> l);

vector<Exercise> selectExercise(vector<Exercise> ex, int mins, int amount, string muscle);

string stringConverter(vector<Exercise> exercises);

string generatePPLSplit();


#endif