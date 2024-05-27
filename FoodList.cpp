/**
 * @file FoodList.cpp
 * @author Esteban Garcia Munoz
 * @brief .cpp file of the class 'FoodList' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "FoodList.hpp"

// Adds a food to the FoodList
void FoodList::addFood(Food food){
    this->list.push_back(food);
}

//Returns the size of the FoodList
int FoodList::size(){
    return this->list.size();
}

//Returns a vector <Food> with the elements of the FoodList
vector <Food> FoodList::getList(){
    return this->list;
}

//Prints the FoodList
void FoodList::printList(){
    int counter = 0;
    cout << "Alimentos cargados: " <<endl;
    cout << "---------------------------------------------"<<endl;
    for(vector<Food>::size_type i =0; i<list.size();i++){
        cout << list[i].getName() << endl;
        counter++;
    }
}

//Override. FoodList[i] will return the food in 'i' position
Food FoodList::operator[](size_t index){
    if (index>= list.size()){
        throw out_of_range("Indice fuera de rango");
    }
    return list[index];
}

//Imports data from a csv file to the FoodList
void FoodList::importData(string fileName){
    ifstream file(fileName);
    if(!file.is_open()){
        cout << "No se puede abir el archivo" <<endl;
        return;
    }

    string line;

    while(getline(file,line)){
        stringstream ss(line);
        string category, name;
        float proteins, carbohydrates, fats, sugar, calories, price;

        //Reading of all the attributes
        getline(ss, category, ',');
        getline(ss, name, ',');  

        ss>>proteins;
        ss.ignore();

        ss>>carbohydrates;
        ss.ignore();

        ss>>fats;
        ss.ignore();

        ss>>sugar;
        ss.ignore();

        ss>>calories;
        ss.ignore();

        ss>>price;

        //Create a food with these attributes and adds them to the FoodList
        Food food(category, name, proteins, carbohydrates, fats, sugar, calories, price);
        list.push_back(food);
    }

    file.close();
}


//Divides the food of the FoodList in three categories
//The MAXIMUM categories of food that the FoodList can contain is 3.
vector <FoodList> FoodList::categoryDivider(){
    //We divide the food in the three categories
    FoodList cat1;
    FoodList cat2;
    FoodList cat3;

    //We create the vector that we are going to return
    vector <FoodList> dividedFood;

    int size = this->list.size();

    //We add all the food of the first category to "cat1"
    int j = 0;
    cat1.addFood(this->list[j]);
    int i = 1;
    while(this->list[i].getCategory()==cat1[0].getCategory()&&i<this->list.size()){
        cat1.addFood(this->list[i]);
        i++;
    }

    //Add cat1 to dividedFood
    dividedFood.push_back(cat1);

    //j: index of the first element of the next category
    //We add the food of the second category to "cat2"
    j = i;
    cat2.addFood(this->list[j]);
    i++;
    while(i<this->list.size()&&this->list[i].getCategory()==cat2[0].getCategory()){
        cat2.addFood(this->list[i]);
        i++;
    }

    //Add cat2 to dividedFood
    dividedFood.push_back(cat2);

    //We update j and add the food of the third category to "cat3"
    j = i;
    cat3.addFood(this->list[j]);
    i++;
    while(i<this->list.size()&&this->list[i].getCategory()==cat3[0].getCategory()){
        cat3.addFood(this->list[i]);
        i++;
    }

    //Add cat3 to dividedFood
    dividedFood.push_back(cat3);

    return dividedFood;
}

Food FoodList::randomFood(){
    srand(time(0));
    int size = this->list.size()-1;
    int randomNum = rand() % size;

    return this->list[randomNum];
}

//Replaces a position of the FoodList with the introduced food
void FoodList::foodReplacer(int index, Food food){
    this->list[index].replaceFood(food);
}

//Picks up from each category the food that suits best to reach the goal Kcals
//Returns FoodList containing the 3 chosen food
FoodList FoodList::mealMaker(FoodList cat2, FoodList cat3, float GoalKcals){
    //float for the first iteration of the condition in the loop
    float HighestKcals = 3000;

    //FoodList bestMeal will contain the final 3 food
    //Initialization of the FoodList with 3 random food
    FoodList bestMeal;
    bestMeal.addFood(cat2[0]);
    bestMeal.addFood(cat2[1]);
    bestMeal.addFood(cat2[2]);

    //Makes every combination of food from each category and picks up the one that is closer to GoalKcals
    for(int i =0; i<this->list.size();i++){
        for(int j = 0;j<cat2.size();j++){
            for(int k = 0; k<cat3.size();k++){
                float totalKcals = this->list[i].getCalories()+cat2[j].getCalories()+cat3[k].getCalories();
                float difference = abs(GoalKcals - totalKcals);

                if(difference<abs(HighestKcals-GoalKcals)){
                    HighestKcals = totalKcals;
                    bestMeal.foodReplacer(0,this->list[i]);
                    bestMeal.foodReplacer(1,cat2[j]);
                    bestMeal.foodReplacer(2,cat3[k]);
                }
            }
        }
    }

    return bestMeal;
}
