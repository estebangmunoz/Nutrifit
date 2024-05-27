/**
 * @file AuxiliarMethods.cpp
 * @author Esteban Garcia Munoz
 * @brief .cpp file of the auxiliar methods used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "AuxiliarMethods.hpp"

//Calculates the spaces needed between the food name and the arrows to be written in the file
int spacesArrows(int wordLength){
    return 20 - wordLength;
}

//Creates a string with the wanted spaces
string spaceCreator(int number){
    string spaces = "";
    for(int i = 0;i<number;i++){
        spaces = spaces + " ";
    }
    return spaces;
}

//When file is going to be written, calculates the number of spaces needed between a number and the nutrient label
int spacesN(float number){
    //Variable that contains the integer parto of the number
    int intPart = (int) number;

    //Variable that contains the first decimal of the number
    int decimal = abs((number-intPart))*10;

    //Variable that is going to contain the number of spaces needed
    int spaces = 5 - to_string(intPart).length();

    //We check the decimals
    if(decimal>0){
        spaces = spaces-2;
    }

    return spaces;
}

