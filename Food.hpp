/**
 * @file Food.hpp
 * @author Esteban Garcia Munoz
 * @brief .hpp file of the class 'Food' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef FOOD_HPP
#define FOOD_HPP

#include <string>  
using namespace std;

class Food{
    private:
        string category;
        string name;
        float calories;
        float proteins;
        float carbohydrates;
        float fats;
        float sugar;
        float price;
    
    public:
        Food();

        Food(string cat, string foodname, float cals, float prots, float carbs, float foodfats, float foodsugar, 
        float foodprice);
        
        string getCategory();

        string getName();

        float getCalories();

        float getProteins();

        float getCarbohydrates();

        float getFats();

        float getSugar();
        
        float getPrice();

        void replaceFood(Food food);
};

#endif