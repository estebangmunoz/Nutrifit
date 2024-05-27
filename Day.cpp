/**
 * @file Day.cpp
 * @author Esteban Garcia Munoz
 * @brief .cpp file of the class 'Day' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Day.hpp"

//Constructor
Day::Day(Meal breakfast, Meal launch, Meal dinner, int dayNumber){
    this->breakfast = breakfast;
    this->launch = launch;
    this->dinner = dinner;
    this->dayNumber = dayNumber;
}

//Empty constructor. Sets day number to 1.
Day::Day(){
    this->dayNumber = 1;
}

//Setter of dayNumber
void Day::setDayNumber(int dayNumber){
    this->dayNumber = dayNumber;
}

//Prints Day's attributes
void Day::printDay(){
    cout << endl << "--------------" << endl;
    cout << "Day " << dayNumber << ": " << endl;

    cout << endl << "Breakfast: " << endl;
    this->breakfast.printMeal();

    cout << endl << "Launch: " << endl;
    this->launch.printMeal();

    cout << endl << "Dinner: " << endl;
    this->dinner.printMeal();

    cout << endl << "Total Kcalories of the day: " << this->breakfast.getTotalCalories() +
    this->launch.getTotalCalories() + dinner.getTotalCalories() << endl;
}

//Returns breakfast of the Day
Meal Day::getBreakfast(){
    return this->breakfast;
}

//Returns launch of the Day
Meal Day::getLaunch(){
    return this->launch;
}

//Returns Dinner of the Day
Meal Day::getDinner(){
    return this->dinner;
}

//Returns TRUE if 2 Days hace the same Meals
bool Day::compareDays(Day day){
    bool sameBreakfast = this->breakfast.sameMeal(day.getBreakfast());
    bool sameLaunch = this->launch.sameMeal(day.getLaunch());
    bool sameDinner = this->dinner.sameMeal(day.getDinner());

    return sameBreakfast*sameLaunch*sameDinner;
}