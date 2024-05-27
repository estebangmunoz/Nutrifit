/**
 * @file Exercises.hpp
 * @author your name (you@domain.com)
 * @brief Provides the function declarations of the respective .cpp, in this case "Exercises.cpp.cpp"
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EXERCISES_HPP
#define EXERCISES_HPP
#include <string>
using namespace std;

class Exercise{
    private:   
        string name;
        string muscle_group;
        string pattern;
        int estimated_minutes;
        //The number of sets and the range of reps will be generated based on the weight and goal of the user.
        int sets;
    public:
        void setName(string Name);    
        void setMucleGroup(string muscleGroup);
        void setPattern(string pattern_);
        void setMinutes(int minutes);
        void setSets(int number);
        string getName();
        string getMuscleGroup();
        string getPattern();
        int getMinutes();
        int getSets();
};

#endif