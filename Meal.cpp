/**
 * @file Meal.cpp
 * @author Esteban Garcia Munoz
 * @brief .cpp file of the class 'Meal' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Meal.hpp"

//Constructor
Meal::Meal(Food firstFood,Food secondFood,Food thirdFood){
    this -> food1 = firstFood;
    this -> food2 = secondFood;
    this -> food3 = thirdFood;
    breakfast = {"Fresh_fruits","Dairy","Cold_cuts","Pastries","Breakfast_cereals","Bread","Eggs",
    "Chocolates","Cookies","Oils","Butters","Juices"};
    launch = {"Legumes","Fresh_vegetables","Frozen_vegetables","Poultry","White_fish","Frozen_seafood",
    "Shellfish_and_derivatives","Prepared_meals","Grains_and_flour", "Pasta", "Tubers_and_roots",
    "Mushrooms","Beef","Pork","Lamb","Blue_fish","Eggs"};
    dinner = {"Fresh_vegetables","Frozen_vegetables","White_fish","Frozen_seafood",
    "Shellfish_and_derivates","Tubers_and_roots","Mushrooms","Beef","Pork","Lamb","Blue_fish",
    "Canned_fish"};
}

//Empty constructor
Meal::Meal(){
    breakfast = {"Fresh_fruits","Dairy","Cold_cuts","Pastries","Breakfast_cereals","Bread","Eggs",
    "Chocolates","Cookies","Oils","Butters","Juices"};
    launch = {"Legumes","Fresh_vegetables","Frozen_vegetables","Poultry","White_fish","Frozen_seafood",
    "Shellfish_and_derivatives","Prepared_meals","Grains_and_flour", "Pasta", "Tubers_and_roots",
    "Mushrooms","Beef","Pork","Lamb","Blue_fish","Eggs"};
    dinner = {"Fresh_vegetables","Frozen_vegetables","White_fish","Frozen_seafood",
    "Shellfish_and_derivates","Tubers_and_roots","Mushrooms","Beef","Pork","Lamb","Blue_fish",
    "Canned_fish"};
}

//CREO QUE NO SE USA
void Meal::reCookMeal(Food food1, Food food2, Food food3){
    this -> food1 = food1;
    this -> food2 = food2;
    this -> food3 = food3;
}

//Returns the category of Food1
string Meal::getFood1category(){
    return food1.getCategory();
}

//Returns the category of Food2
string Meal::getFood2category(){
    return food2.getCategory();
}

//Returns the category of Food3
string Meal::getFood3category(){
    return food3.getCategory();
}

//Returns breakfast attribute
vector <string> Meal::getBreakfast(){
    return this->breakfast;
}

//Returns the total Kcals of the Meal
float Meal::getTotalCalories(){
    return this->food1.getCalories()+this->food2.getCalories()+this->food3.getCalories();
}

//Returns food1 of the Meal
Food Meal::getFood1(){
    return this->food1;
}

//Returns food2 of the Meal
Food Meal::getFood2(){
    return this->food2;
}

//Returns food3 of the Meal
Food Meal::getFood3(){
    return this->food3;
}

//Prints the Meal
void Meal::printMeal(){
    cout << this->food1.getName() << ", " << food1.getCalories() << " Kcal" << endl;
    cout << this->food2.getName() << ", " << food2.getCalories() << " Kcal" << endl;
    cout << this->food3.getName() << ", " << food3.getCalories() << " Kcal" << endl;
    cout << "Total Kcalories: " << food1.getCalories() + food2.getCalories() + food3.getCalories() << endl;
}

//Chooses 3 random words from a vector of string
vector <string> Meal::wordChooser(vector<string> wordList){
    srand(time(0));
    vector <string> chosenWords;
    vector <string> remainingWords = wordList;
    for(int i = 0;i<3;i++){
        int index = rand() % remainingWords.size();
        chosenWords.push_back(remainingWords[index]);
        remainingWords.erase(remainingWords.begin()+index);
    }
    return chosenWords;
}

//Returns a FoodList containing all the foods belonging to the 3 categories introduced
FoodList Meal::possibleFoodSelector(vector <string> categories, FoodList foodList){
    FoodList possibleFood;
    for(int i =0;i<categories.size();i++){
        string category = categories[i];

        //Adds the foods that belong to the category in 'categories[i]' to possibleFood
        for(int j = 0;j<foodList.size();j++){
            if(foodList[j].getCategory()==category){
                possibleFood.addFood(foodList[j]);
            }
        }
    }
    return possibleFood;
}

//Override. Meal[i] returns the food in 'i' position. i can only be 1,2 or 3.
Food Meal::operator[](int i){
    if (i==1) return this->food1;
    else if (i==2) return this->food2;
    else if (i==3) return this->food3;
    else throw out_of_range("Indice fuera de rango");
}

//Returns true if a food is repeated in both meals
bool Meal::compareMeal(Meal meal){
    bool answer = false;
            
    for(int i = 1;i<4;i++){
        if(this->food1.getName() == meal[i].getName() || this->food2.getName() == meal[i].getName()
        || this->food3.getName() == meal[i].getName()){
            return true;
        } 
    }

    return answer;
}

//Checks if two meals are the same
bool Meal::sameMeal(Meal meal){
    bool sameFood1 = false;
    bool sameFood2 = false;
    bool sameFood3 = false;

    for(int i = 1;i<4;i++){
        if(this->food1.getName()==meal[i].getName()){
            sameFood1 = true;
        }
        if(this->food2.getName()==meal[i].getName()){
            sameFood2 = true;
        }
        if(this->food3.getName()==meal[i].getName()){
            sameFood3 = true;
        }
    }

    return(sameFood1*sameFood2*sameFood3);
}

//Makes breakfast with three foods that belong to breakfast categories.
//First argument is the foodList containing all the food.
//Second argument is the goal Kcals.
void Meal::makeBreakfast(FoodList list, float Kcals){
    float totalKcals;
    float difference = 300;

    //If the Kcals needed are more than 600, we change the foodList for one containing food 
    //with more Kcals
    if(Kcals > 600){
        FoodList moreCalories;
        moreCalories.importData("moreCalories.csv");
        list = moreCalories;
    }

    //Loop to check that there is not a big difference between the goal and total Kcals
    while(difference>150){

        //Vector with 3 categories chosen randomly from the breakfast categories.
        vector <string> categories = wordChooser(this->breakfast);

        //Goes through the complete food list and selects all the food that belong to the  
        //categories chosen
        FoodList breakfastFood = possibleFoodSelector(categories,list);

        //Divide all the possible food in 3 vectors, one of each category
        vector <FoodList> dividedByCategory = breakfastFood.categoryDivider();

        FoodList category1 = dividedByCategory[0];
        FoodList category2 = dividedByCategory[1];
        FoodList category3 = dividedByCategory[2];

        //FoodList that contains the 3 final foods
        FoodList finalBreakfast = category1.mealMaker(category2,category3,Kcals);

        this->food1 = finalBreakfast[0];
        this->food2 = finalBreakfast[1];
        this->food3 = finalBreakfast[2];

        totalKcals = this->food1.getCalories()+this->food2.getCalories()+this->food3.getCalories();
        difference = abs(totalKcals-Kcals);
    }
}

//Makes launch with three foods that belong to launch categories.
//First argument is the foodList containing all the food.
//Second argument is the goal Kcals.
void Meal::makeLaunch(FoodList list, float Kcals){
    float totalKcals = 0;
    float difference = 300;

    if(Kcals > 1200){
        FoodList moreCalories;
        moreCalories.importData("moreCalories.csv");
        list = moreCalories;
    }

    //Loop to check that there is not a big difference between the goal and total Kcals
    while(difference>160){

        //Vector with 3 categories chosen randomly from the breakfast categories.
        vector <string> categories = wordChooser(this->launch);

        //Goes through the complete food list and selects all the food that belong to the  
        //categories chosen
        FoodList launchFood = possibleFoodSelector(categories,list);

        //Divide all the possible food in 3 vectors, one of each category
        vector <FoodList> dividedByCategory = launchFood.categoryDivider();

        FoodList category1 = dividedByCategory[0];
        FoodList category2 = dividedByCategory[1];
        FoodList category3 = dividedByCategory[2];

        //FoodList that contains the 3 final foods
        FoodList finalLaunch = category1.mealMaker(category2,category3,Kcals);

        this->food1 = finalLaunch[0];
        this->food2 = finalLaunch[1];
        this->food3 = finalLaunch[2];

        totalKcals = this->food1.getCalories()+this->food2.getCalories()+this->food3.getCalories();
        difference = abs(totalKcals-Kcals);
    }
}

//Makes dinner with three foods that belong to dinner categories.
//First argument is the foodList containing all the food.
//Second argument is the goal Kcals.
void Meal::makeDinner(FoodList list, float Kcals){
    float totalKcals = 0;
    float difference = 301;

    if(Kcals > 1200){
        FoodList moreCalories;
        moreCalories.importData("moreCalories.csv");
        list = moreCalories;
    }

    //Loop to check that there is not a big difference between the goal and total Kcals
    while(difference>250){

        //Vector with 3 categories chosen randomly from the breakfast categories.
        vector <string> categories = wordChooser(this->dinner);

        //Goes through the complete food list and selects all the food that belong to the  
        //categories chosen
        FoodList dinnerFood = possibleFoodSelector(categories,list);

        //Divides all the possible food in 3 vectors, one of each category
        vector <FoodList> dividedByCategory = dinnerFood.categoryDivider();

        FoodList category1 = dividedByCategory[0];
        FoodList category2 = dividedByCategory[1];
        FoodList category3 = dividedByCategory[2];

        //FoodList that contains the 3 final foods
        FoodList finalDinner = category1.mealMaker(category2,category3,Kcals);

        this->food1 = finalDinner[0];
        this->food2 = finalDinner[1];
        this->food3 = finalDinner[2];

        totalKcals = this->food1.getCalories()+this->food2.getCalories()+this->food3.getCalories();
        difference = abs(totalKcals-Kcals);
    }
}

//Writes the Meal in the introduced file. This file has been previously opened in another function.
void Meal::writeMeal(ofstream& file){
    //Writing of the first food and its macronutrients
    string f1Name = food1.getName();
    int numSpaces = spacesArrows(f1Name.length());
    string spaces = spaceCreator(numSpaces);
    float f1Calories = food1.getCalories();
    float f1Proteins = food1.getProteins();
    float f1Carbs = food1.getCarbohydrates();
    float f1Fats = food1.getFats();
    float f1Sugar = food1.getSugar();
    float f1Price = food1.getPrice();

    file << f1Name << spaces << "==> " <<  f1Calories << spaceCreator(spacesN(f1Calories)) << "Kcals | " 
    << f1Proteins << spaceCreator(spacesN(f1Proteins)) << "Prots | " << f1Carbs << 
    spaceCreator(spacesN(f1Carbs)) << "Carbs | " << f1Fats << spaceCreator(spacesN(f1Fats)) << "Fats  | " <<
    f1Sugar << spaceCreator(spacesN(f1Sugar)) << "Sugar | " << f1Price << spaceCreator(spacesN(f1Price))
    << " €/kg  |" << endl;

    //Writing of the second food and its macronutrients
    string f2Name = food2.getName();
    int numSpaces2 = spacesArrows(f2Name.length());
    string spaces2 = spaceCreator(numSpaces2);
    float f2Calories = food2.getCalories();
    float f2Proteins = food2.getProteins();
    float f2Carbs = food2.getCarbohydrates();
    float f2Fats = food2.getFats();
    float f2Sugar = food2.getSugar();
    float f2Price = food2.getPrice();

    file << f2Name << spaces2 << "==> " <<  f2Calories << spaceCreator(spacesN(f2Calories)) << "Kcals | " 
    << f2Proteins << spaceCreator(spacesN(f2Proteins)) << "Prots | " << f2Carbs << 
    spaceCreator(spacesN(f2Carbs)) << "Carbs | " << f2Fats << spaceCreator(spacesN(f2Fats)) << "Fats  | " <<
    f2Sugar << spaceCreator(spacesN(f2Sugar)) << "Sugar | " << f2Price << spaceCreator(spacesN(f2Price))
    << " €/kg  |" << endl;

    //Writing of the third food and its macronutrients
    string f3Name = food3.getName();
    int numSpaces3 = spacesArrows(f3Name.length());
    string spaces3 = spaceCreator(numSpaces3);
    float f3Calories = food3.getCalories();
    float f3Proteins = food3.getProteins();
    float f3Carbs = food3.getCarbohydrates();
    float f3Fats = food3.getFats();
    float f3Sugar = food3.getSugar();
    float f3Price = food3.getPrice();

    file << f3Name << spaces3 << "==> " <<  f3Calories << spaceCreator(spacesN(f3Calories)) << "Kcals | " 
    << f3Proteins << spaceCreator(spacesN(f3Proteins)) << "Prots | " << f3Carbs << 
    spaceCreator(spacesN(f3Carbs)) << "Carbs | " << f3Fats << spaceCreator(spacesN(f3Fats)) << "Fats  | " <<
    f3Sugar << spaceCreator(spacesN(f3Sugar)) << "Sugar | " << f3Price << spaceCreator(spacesN(f3Price))
    << " €/kg  |" << endl;

    //Writing of the total Kcals
    float totalKcals = f1Calories + f2Calories + f3Calories;
    string spaces4 = spaceCreator(5);
    file << "Total Kcalories" << spaces4 << "==> " << totalKcals << endl;
}
