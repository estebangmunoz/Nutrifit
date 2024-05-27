/**
 * @file FoodList.hpp
 * @author Esteban Garcia Munoz
 * @brief .hpp file of the class 'FoodList' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef FOODLIST_HPP
#define FOODLIST_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Food.hpp"

using namespace std;

class FoodList{
    private:
        vector<Food> list;

    public:
        void addFood(Food food);

        int size();

        vector<Food> getList();

        void printList();

        Food operator[](size_t index);

        void importData(string fileName);

        vector <FoodList> categoryDivider();

        Food randomFood();

        void foodReplacer(int index, Food food);

        FoodList mealMaker(FoodList cat2, FoodList cat3, float GoalKcals);
};

#endif