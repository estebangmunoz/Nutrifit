/**
 * @file routineGenerator.cpp
 * @author Jorge Cavero Cañabate
 * @brief This is the most important part of the module, 
 *        since it is responsible for generating personalized routines based on the time available to the user. 
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "routineGenerator.hpp"
#include "Exercises.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

/**
 * @brief This function is destinated for the Full body rutine, it selects exercises for the main parts of the body (Chest, back, arms, legs...)
 *        It returns a string so that the "filemanagment" file, writtes what the string provides to the .txt
 * 
 * @param day 
 * @param time 
 * @param ex 
 * @return string 
 */
string dailyRoutineGenerator(int day, int time, vector<Exercise> ex){
    string daily;
    float percentaje_Push, percentaje_Pull, percentaje_Legs, percentaje_Arms;
    
    if (day == 1){
        percentaje_Arms = percentaje_Pull = percentaje_Legs = percentaje_Arms = 0.25;
        vector<Exercise> chest = selectExercise(ex, time*percentaje_Push, 2, " Chest");
        vector<Exercise> back = selectExercise(ex, time*percentaje_Pull, 2, " Back");
        vector<Exercise> quads = selectExercise(ex, time*percentaje_Legs, 2," Quadriceps");
        vector<Exercise> triceps = selectExercise(ex, (time*percentaje_Arms)/2, 1, " Triceps");
        vector<Exercise> biceps = selectExercise(ex, (time*percentaje_Arms)/2, 1, " Biceps");
        daily = stringConverter(chest) + stringConverter(back) + stringConverter(quads) + stringConverter(triceps) + stringConverter(biceps);
    }
    if (day == 2){
        percentaje_Push = 0.4;
        percentaje_Pull = 0.2;
        percentaje_Legs = 0.2;
        percentaje_Arms = 0.2;
        vector<Exercise> chest = selectExercise(ex, time*percentaje_Push, 2, " Chest");
        vector<Exercise> shoulder = selectExercise(ex, time*percentaje_Push, 1, " Shoulders");
        vector<Exercise> back = selectExercise(ex, time*percentaje_Pull, 1," Back");
        vector<Exercise> triceps = selectExercise(ex, (time*percentaje_Arms)/2, 1, " Triceps");
        vector<Exercise> biceps = selectExercise(ex, (time*percentaje_Arms)/2, 1," Biceps");
        vector<Exercise> quads = selectExercise(ex,time*percentaje_Legs, 1, " Quadriceps");
        daily = stringConverter(chest) + stringConverter(back) + stringConverter(quads) + stringConverter(triceps) + stringConverter(biceps) + stringConverter(shoulder);
    
    }
    if(day == 3){
        percentaje_Push = 0.2;
        percentaje_Pull = 0.4;
        percentaje_Legs = 0.1;
        percentaje_Arms = 0.3;
        vector<Exercise> chest = selectExercise(ex, time*percentaje_Push, 1, " Chest");
        vector<Exercise> back = selectExercise(ex, time*percentaje_Pull, 2," Back");
        vector<Exercise> triceps = selectExercise(ex, (time*percentaje_Arms)/2, 1, " Triceps");
        vector<Exercise> biceps = selectExercise(ex, (time*percentaje_Arms)/2, 2, " Biceps");
        vector<Exercise> quads = selectExercise(ex,time*percentaje_Legs, 1, " Quadriceps");
        daily = stringConverter(chest) + stringConverter(back) + stringConverter(quads) + stringConverter(triceps) + stringConverter(biceps);
    
    }
    if(day == 4){
        percentaje_Pull = 0.15;
        percentaje_Legs = 0.5;
        percentaje_Push = 0.15;
        percentaje_Arms = 0.2;
        vector<Exercise> chest = selectExercise(ex, time*percentaje_Push, 1, " Chest");
        vector<Exercise> back = selectExercise(ex, time*percentaje_Pull,1," Back");
        vector<Exercise> triceps = selectExercise(ex, (time*percentaje_Arms)/2, 1, " Triceps");
        vector<Exercise> biceps = selectExercise(ex, (time*percentaje_Arms)/2, 1, " Biceps");
        vector<Exercise> quads = selectExercise(ex,time*percentaje_Legs*0.4, 2, " Quadriceps");
        vector<Exercise> adductor = selectExercise(ex, (time*percentaje_Legs*0.2), 1, " Adductors");
        vector<Exercise> hamstrings = selectExercise(ex, (time*percentaje_Legs*0.4), 2, " Hamstrings");
        daily = stringConverter(chest) + stringConverter(back) + stringConverter(quads) + stringConverter(triceps) + stringConverter(biceps);
    }
    if(day == 5){
        percentaje_Arms = 0.3;
        percentaje_Legs = 0.3;
        percentaje_Pull = 0.2;
        percentaje_Push = 0.2;
        vector<Exercise> chest = selectExercise(ex, time*percentaje_Push, 2, " Chest");
        vector<Exercise> back = selectExercise(ex, time*percentaje_Pull,2," Back");
        vector<Exercise> triceps = selectExercise(ex, (time*percentaje_Arms)/2, 2, " Triceps");
        vector<Exercise> biceps = selectExercise(ex, (time*percentaje_Arms)/2, 2, " Biceps");
        vector<Exercise> quads = selectExercise(ex,time*percentaje_Legs*0.4, 1, " Quadriceps");
        vector<Exercise> adductor = selectExercise(ex, (time*percentaje_Legs*0.2), 1, " Adductors");
        vector<Exercise> hamstrings = selectExercise(ex, (time*percentaje_Legs*0.4), 1, " Hamstrings");
        daily = stringConverter(chest) + stringConverter(back) + stringConverter(quads) + stringConverter(triceps) + stringConverter(biceps);
    }

    return daily;
}

/**
 * @brief Part one of the routine 'Push pull legs', it selects exercises based on the percentaje of time they have. 
 *        This percentage is defined based on the random split that is generated for each person. 
 * 
 * @param day 
 * @param time 
 * @param p 
 * @return string 
 */
string pull(int day, int time, vector<Exercise> p){
    string pull;
    float percentaje_biceps;
    float percentaje_back;
    float percentaje_lats;
    float percentaje_lback;
    if(day == 1){
        percentaje_biceps = 0.2;
        percentaje_lats = 0.4;
        percentaje_back = 0.4;
        vector<Exercise> biceps = selectExercise(p, (time*percentaje_biceps)/2, 1, " Biceps");
        vector<Exercise> brachialis = selectExercise(p, (time*percentaje_biceps)/2, 1, " Biceps (Brachialis)");
        vector<Exercise> lats = selectExercise(p, time*percentaje_lats,3, " Lats");
        vector<Exercise> back = selectExercise(p, time*percentaje_back, 3, " Back");
        pull = stringConverter(lats) + stringConverter(back) + stringConverter(biceps) + stringConverter(brachialis);
    }
    if(day == 2){
        percentaje_lback = 0.3;
        percentaje_back = 0.3;
        percentaje_lats = 0.2;
        percentaje_biceps = 0.2;
        vector<Exercise> biceps = selectExercise(p, (time*percentaje_biceps)/2, 1, " Biceps");
        vector<Exercise> brachialis = selectExercise(p, (time*percentaje_biceps)/2, 1, " Biceps (Brachialis)");
        vector<Exercise> lats = selectExercise(p, time*percentaje_lats,2, " Lats");
        vector<Exercise> back = selectExercise(p, time*percentaje_back, 2, " Back");
        vector<Exercise> lower = selectExercise(p, time*percentaje_lback, 1, " Lower Back");
        pull = stringConverter(lower) + stringConverter(back) + stringConverter(lats) + stringConverter(biceps) + stringConverter(brachialis);
    }
    return pull;
}

/**
 * @brief Part two of the routine 'Push pull legs', it selects exercises based on the percentaje of time they have. 
 *        This percentage is defined based on the random split that is generated for each person. 
 * @param day 
 * @param time 
 * @param p 
 * @return string 
 */
string push(int day, int time, vector<Exercise> p){
    string push;
    float percentaje_chest;
    float percentaje_triceps;
    float percentaje_shoulder;
    if(day == 1){
        percentaje_chest = 0.5;
        percentaje_shoulder = 0.3;
        percentaje_triceps = 0.2;
        vector<Exercise> triceps = selectExercise(p, time*percentaje_triceps,2, " Triceps");
        vector<Exercise> chest = selectExercise(p, time*percentaje_chest, 4, " Chest");
        vector<Exercise> shoulders = selectExercise(p,time*percentaje_shoulder, 3, " Shoulder");
        push = stringConverter(chest) + stringConverter(shoulders) + stringConverter(triceps);
    }
    if(day == 2){
        percentaje_chest = 0.3;
        percentaje_shoulder = 0.4;
        percentaje_triceps = 0.3;
        vector<Exercise> chest = selectExercise(p, time*percentaje_chest, 3, " Chest");
        vector<Exercise> shoulders = selectExercise(p,time*percentaje_shoulder, 3, " Shoulder");
        vector<Exercise> triceps = selectExercise(p, time*percentaje_triceps,3, " Triceps");
        push = stringConverter(chest) + stringConverter(shoulders) + stringConverter(triceps);
    }
    return push;
}

/**
 * @brief Last part of the routine 'Push pull legs', it selects exercises based on the percentaje of time they have. 
 *        This percentage is defined based on the random split that is generated for each person. 
 * @param day 
 * @param time 
 * @param l 
 * @return string 
 */
string legs(int day, int time, vector<Exercise> l){
    string legs;
    float percentaje_quadriceps;
    float percentaje_hamstrings;
    float percentaje_calves;
    float percentaje_adductors;
    float percentaje_glutes;

    if(day == 1){
        percentaje_calves = 0.1;
        percentaje_adductors = 0.2;
        percentaje_hamstrings = 0.3;
        percentaje_quadriceps = 0.4;
        vector<Exercise> calves = selectExercise(l, time*percentaje_calves, 1, " Calves");
        vector<Exercise> adductors = selectExercise(l, time*percentaje_adductors, 1, " Adductors");
        vector<Exercise> quads = selectExercise(l, time*percentaje_quadriceps, 3, " Quadriceps");
        vector<Exercise> hamstrngs = selectExercise(l, time*percentaje_hamstrings, 2, " Hamstrings");
        legs = stringConverter(calves) + stringConverter(adductors) + stringConverter(quads) + stringConverter(hamstrngs);
    }
    if(day == 2){
        percentaje_glutes = 0.2;
        percentaje_adductors = 0.2;
        percentaje_hamstrings = 0.2;
        percentaje_quadriceps = 0.4;
        vector<Exercise> glutes = selectExercise(l, time*percentaje_glutes, 1, " Glutes");
        vector<Exercise> adductors = selectExercise(l, time*percentaje_adductors, 1, " Adductors");
        vector<Exercise> quads = selectExercise(l, time*percentaje_quadriceps, 3, " Quadriceps");
        vector<Exercise> hamstrngs = selectExercise(l, time*percentaje_hamstrings, 2, " Hamstrings");
        legs = stringConverter(glutes) + stringConverter(adductors) + stringConverter(quads) + stringConverter(hamstrngs);
    }
    return legs;
}

/**
 * @brief   Exercise selector, based on the time available, 
 *          and always trying to obtain the greatest number of muscle groups involved in the specified muscle.
 * @param ex 
 * @param mins 
 * @param amount 
 * @param muscle 
 * @return vector<Exercise> 
 */
vector<Exercise> selectExercise(vector<Exercise> ex, int mins, int amount, string muscle){
    vector<Exercise> selectedExercises;
    int totalTime = 0;
    for(int i = 0; i < ex.size(); i++){
        if(totalTime + ex[i].getMinutes() <= mins && (selectedExercises.size()<amount) && (ex[i].getMuscleGroup() == muscle)){
            selectedExercises.push_back(ex[i]);
            totalTime += ex[i].getMinutes();
        }
        if(selectedExercises.size() > amount){
            break;
        }
    }
    return selectedExercises;
}

/**
 * @brief Transforms exercise type objects into objects. Whitout this it wouldn't be possible to writte on the .txt file.
 * 
 * @param exercises 
 * @return string 
 */
string stringConverter(vector<Exercise> exercises){
    string a = "";
    for(auto exercise : exercises){
        a = a + exercise.getName() + "\t" + to_string(exercise.getSets()) +"\t" + exercise.getMuscleGroup() + "\t" + exercise.getPattern()+"\n";
    }
    return a;
}

/**
 * @brief Randomn generator for PPL split.
 * 
 * @return string 
 */
string generatePPLSplit(){
    srand(time(0));
    int number = 1 + rand() % 2;
    string a = "";
    if(number == 1){
        a = "PUSH~A - PULL~A - REST - LEGS~A - PUSH~B - REST - PULL~B - LEGS~B";
    }
    if(number == 2){
        a = "PULL~A - PUSH~A - LEGS~A - REST - PULL~B - PUSH~B - REST - LEGS~B";
    }
    return a;
}
