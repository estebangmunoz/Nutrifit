/**
 * @file Meal.hpp
 * @author Esteban Garcia Munoz
 * @brief .hpp file of the class 'Meal' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MEAL_HPP
#define MEAL_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Food.hpp"
#include "FoodList.hpp"
#include "AuxiliarMethods.hpp"

class Meal{
    private:
        Food food1;
        Food food2;
        Food food3;
        vector <string> breakfast;
        vector <string> launch;
        vector <string> dinner;

    public:
        Meal(Food firstFood, Food secondFood, Food thirdFood);
        
        Meal();

        void reCookMeal(Food food1, Food food2, Food food3);

        string getFood1category();

        string getFood2category();

        string getFood3category();

        vector <string> getBreakfast();

        float getTotalCalories();

        Food getFood1();

        Food getFood2();

        Food getFood3();

        void printMeal();

        vector <string> wordChooser(vector <string> wordList);

        FoodList possibleFoodSelector(vector <string> categories, FoodList foodList);

        Food operator[](int i);

        bool compareMeal(Meal meal);

        bool sameMeal(Meal meal);

        void makeBreakfast(FoodList list, float Kcals);

        void makeLaunch(FoodList list, float Kcals);

        void makeDinner(FoodList list, float Kcals);

        void writeMeal(ofstream& file);
};

#endif