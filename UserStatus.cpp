/**
 * @file UserStatus.cpp
 * @author Esteban Garcia Munoz
 * @brief .cpp file of the class 'UserStatus' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "UserStatus.hpp"

//Empty constructor
UserStatus::UserStatus(){
    this->weight = 0;
    float activityFactor = 0;
    float actualKcals = 0;
    float goalKcals = 0;
}

//Constructor. Only recieves weight
UserStatus::UserStatus(float weight){
    this->weight = weight;
}

//Calculates and sets the actualKcals needed
void UserStatus::setActualKcals(){
    this->actualKcals = this->weight*22*this->activityFactor;
}

//Sets the activity factor
void UserStatus::setActivityFactor(){
    cout << endl << "How much sport do you make? Choose a number 1 to 4: " << endl;
    cout << "1) Very few or none." << endl;
    cout << "2) 1-3 days per week." << endl;
    cout << "3) 4-5 days per week." << endl;
    cout << "4) 6-7 days per week." << endl;

    int activity; 
    cin >> activity;

    while(activity<1 || activity>4){
        cout << "Please introduce a number from 1 to 4: ";
        cin >> activity;
    }

    switch(activity){
        case 1:
            this->activityFactor = 1.2;
            break;
        case 2:
            this->activityFactor = 1.4;
            break;
        case 3:
            this->activityFactor = 1.6;
            break;
        case 4:
            this->activityFactor = 1.8;
            break;
        }
}

//Sets the goalKcals to the ones needed by the user
void UserStatus::looseWeight(){
    cout << endl << "How fast would you like to loose weight? Choose from 1 to 3:" << endl;
    cout << "1) Slow. (10% less of Kcals eaten per day than you should now)" << endl;
    cout << "2) Medium. (20% less of Kcals eaten per day than you should now)" << endl;
    cout << "3) Fast. (30% less of Kcals eaten per day than you should now)" << endl;

    int speed; 
    cin >> speed;

    while(speed<1 || speed>4){
        cout << "Please introduce a number from 1 to 3: ";
        cin >> speed;
    }

    switch(speed){
        case 1:
            this->goalKcals = this->actualKcals*0.9;
            break;
        case 2:
            this->goalKcals = this->actualKcals*0.8;
            break;
        case 3:
            this->goalKcals = this->actualKcals*0.7;
            break;
    }
}  

//Sets the goalKcals to the ones needed by the user
void UserStatus::gainWeight(){
    cout << endl << "How fast would you like to gain weight? Choose from 1 to 3:" << endl;
    cout << "1) Slow. (10% more of Kcals eaten per day than you should now)" << endl;
    cout << "2) Medium. (20% more of Kcals eaten per day than you should now)" << endl;
    cout << "3) Fast. (30% more of Kcals eaten per day than you should now)" << endl;

    int speed; 
    cin >> speed;

    while(speed<1 || speed>4){
        cout << "Please introduce a number from 1 to 3: ";
        cin >> speed;
    }

    switch(speed){
        case 1:
            this->goalKcals = this->actualKcals*1.1;
            break;
        case 2:
            this->goalKcals = this->actualKcals*1.2;
            break;
        case 3:
            this->goalKcals = this->actualKcals*1.3;
            break;
    }
}

//Calculates and sets the actualKcals a user should have per day
float UserStatus::kCalsCalculator(){
    /*
    cout << "How much do you weight? ";
    float userWeight;
    cin >> userWeight;

    this -> weight = userWeight;

    */

    setActivityFactor();
    setActualKcals();
    float actualConsumedKcals = this->weight*22*activityFactor;
    int weightAnswer;

    cout << endl << "What would you like to do? Choose betweeen 1 or 2:" << endl;
    cout << "1) Gain weight." << endl;
    cout << "2) Loose weight." << endl;
    cin >> weightAnswer;

    while(weightAnswer<1 || weightAnswer>4){
        cout << "Please introduce a number from 1 to 2: ";
        cin >> weightAnswer;
    }

    switch(weightAnswer){
        case 1:
            gainWeight();
            break;
        case 2:
            looseWeight();
            break;
    }

    cout << endl << "Great! From now on, you will need to consume " << goalKcals << " Kcals per day." << endl;
    return this->goalKcals;
}

