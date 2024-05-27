/**
 * @file Diet.hpp
 * @author Esteban Garcia Munoz
 * @brief .hpp file of the class 'Diet' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef DIET_HPP
#define DIET_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Day.hpp"
#include "FoodList.hpp"

using namespace std;

class Diet{
    private:
        vector <Day> planning;
        int numberOfDays;
        float KcalsPerDay;
    
    public:
        Diet(int numberOfDays, float Kcals);

        Diet();

        void makeDiet();

        void printDiet();

        void writeDiet(string fileName);
};

#endif