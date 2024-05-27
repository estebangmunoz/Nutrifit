/**
 * @file Exercises.cpp
 * @author Jorge Cavero Cañabate
 * @brief File containing Exercise class
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Exercises.hpp"
#include<string>


void Exercise::setName(string Name) {
    this->name = Name;
}

void Exercise::setMucleGroup(string muscleGroup) {
    this->muscle_group = muscleGroup;
}

void Exercise::setPattern(string pattern_) {
    this->pattern = pattern_;
}

void Exercise::setMinutes(int minutes) {
    this->estimated_minutes = minutes;
}

void Exercise::setSets(int number) {
    this->sets = number;
}

string Exercise::getName() {
    return this->name;
}

string Exercise::getMuscleGroup() {
    return this->muscle_group;
}

string Exercise::getPattern() {
    return this->pattern;
}

int Exercise::getMinutes() {
    return this->estimated_minutes;
}

int Exercise::getSets() {
    return this->sets;
}
