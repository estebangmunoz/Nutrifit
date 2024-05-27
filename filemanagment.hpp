/**
 * @file filemanagment.hpp
 * @author Jorge Cavero Cañabate
 * @brief Provides the function declarations of the respective .cpp, in this case "filemanagment.cpp"
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef FILEMANAGMENT_HPP
#define FILEMANAGMENT_HPP
#include <vector>
#include <string>
#include "Exercises.hpp"
vector<Exercise> readFile(string nombre_Archivo);
void writeRoutineFB(string fileName, string routine, int day);
void writeRoutinePPL(string fileName, string routine, string day, string split);

#endif