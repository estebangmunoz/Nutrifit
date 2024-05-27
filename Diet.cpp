/**
 * @file Diet.cpp
 * @author Esteban Garcia Munoz
 * @brief .cpp file of the class 'Diet' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Diet.hpp"

//Constructor
Diet::Diet(int numberOfDays, float Kcals){
    this->numberOfDays = numberOfDays;
    this->KcalsPerDay = Kcals;
}

//Empty constructor. Default days are 15
Diet::Diet(){
    this->numberOfDays = 15;
}

//Makes the diet
void Diet::makeDiet(){
    //FoodList that contains all the food
    FoodList allFoods;
    allFoods.importData("foodData.csv");

    //Divides the Kcals of a day. 2/5 for launch and dinner. 1/5 for breakfast
    float breakfastKcals = this->KcalsPerDay/5;
    float launchKcals = this->KcalsPerDay/5*2;
    float dinnerKcals = this->KcalsPerDay/5*2;

    for(int i = 0;i<this->numberOfDays;i++){
        //Make breakfast with the needed Kcals
        Meal breakfast;
        breakfast.makeBreakfast(allFoods,breakfastKcals);

        Meal launch;
        launch.makeLaunch(allFoods,launchKcals);

        Meal dinner;
        dinner.makeDinner(allFoods,dinnerKcals);

        //We check that there is not a repeated food in launch and dinner
        while(launch.compareMeal(dinner)){
            dinner.makeDinner(allFoods,dinnerKcals);
        }

        Day day(breakfast,launch,dinner,i+1);

        if(i==0){
            this->planning.push_back(day);

            cout << "Day " << i+1 << " prepared. " << endl; 
        }
                
        else{
        //We check if two days are the same
        if(!day.compareDays(planning[i-1])){
            this->planning.push_back(day);

            cout << "Day " << i+1 << " prepared. " << endl; 
        }
        else i--;
        }
    }

    cout << "Diet is ready!" << endl;
}

//Prints the diet
void Diet::printDiet(){
    for(int i = 0;i<planning.size();i++){
        planning[i].printDay();
    }
}

//Writes the diet in a .txt file
void Diet::writeDiet(string fileName){
    fileName = fileName + ".txt";
    ofstream file(fileName);
    file << "                                            DIET PLANNING                                             " << endl;
    file << "------------------------------------------------------------------------------------------------------" << endl;
            
    for(int i = 0;i<planning.size();i++){
        file << "------------------------------------------------------------------------------------------------------" << endl;
        file << "Day " << i+1 << ":" << endl; 
                
        file << endl << "                                              Breakfast" << endl;
        file << "                                              ---------" << endl;
        this->planning[i].getBreakfast().writeMeal(file);

        file << endl << "                                               Launch" << endl;
        file << "                                              ---------" << endl;
        this->planning[i].getLaunch().writeMeal(file);

        file << endl << "                                               Dinner" << endl;
        file << "                                              ---------" << endl;
        this->planning[i].getDinner().writeMeal(file);

        file << endl << "Total Kcalories of the day: " << planning[i].getBreakfast().getTotalCalories()
        + planning[i].getLaunch().getTotalCalories() + planning[i].getDinner().getTotalCalories() <<
        " Kcals." << endl;

    }

    file.close();
}