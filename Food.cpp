/**
 * @file Food.cpp
 * @author Esteban Garcia Munoz
 * @brief .cpp file of the class 'Food' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Food.hpp"

//Empty constructor. Sets all values to 0.
Food::Food(){
    this -> category = "0";
    this -> name = "0";
    this -> calories = 0;
    this -> proteins = 0;
    this -> carbohydrates = 0;
    this -> fats = 0;
    this -> sugar = 0;
    this -> price = 0;
}

//Constructor
Food::Food(string cat, string foodname, float cals, float prots, float carbs, float foodfats, 
float foodsugar, float foodprice){
    this -> category = cat;
    this -> name = foodname;
    this -> calories = cals;
    this -> proteins = prots;
    this -> carbohydrates = carbs;
    this -> fats = foodfats;
    this -> sugar = foodsugar;
    this -> price = foodprice;
}

//Returns category of the food
string Food::getCategory(){
    return this-> category;
}

//Returns name of the food
string Food::getName(){
    return this-> name;
}

//Returns Kcals of the food
float Food::getCalories(){
    return this->calories;
}

//Returns proteins of the food
float Food::getProteins(){
    return this->proteins;
}

//Returns carbohydrates of the food
float Food::getCarbohydrates(){
    return this->carbohydrates;
}

//Returns fats of the food
float Food::getFats(){
    return this->fats;
}

//Returns sugar of the food
float Food::getSugar(){
    return this->sugar;
}

//Returns price of the food
float Food::getPrice(){
    return this->price;
}

//Replaces the attributes of a food with the ones of the introduced food
void Food::replaceFood(Food food){
    this -> category = food.getCategory();
    this -> name = food.getName();
    this -> calories = food.getCalories();
    this -> proteins = food.getProteins();
    this -> carbohydrates = food.getCarbohydrates();
    this -> fats = food.getFats();
    this -> sugar = food.getSugar();
    this -> price = food.getPrice();
}
