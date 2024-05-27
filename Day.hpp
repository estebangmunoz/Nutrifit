/**
 * @file Day.hpp
 * @author Esteban Garcia Munoz
 * @brief .hpp file of the class 'Day' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef DAY_HPP
#define DAY_HPP

#include <iostream>
#include "Meal.hpp"

using namespace std;

class Day{
    private:
        Meal breakfast;
        Meal launch;
        Meal dinner;
        int dayNumber;

    public:
        Day(Meal breakfast, Meal launch, Meal dinner, int dayNumber);

        Day();

        void setDayNumber(int dayNumber);

        void printDay();

        Meal getBreakfast();

        Meal getLaunch();
        
        Meal getDinner();

        bool compareDays(Day day);
};

#endif