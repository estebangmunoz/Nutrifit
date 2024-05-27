/**
 * @file UserStatus.hpp
 * @author Esteban Garcia Munoz
 * @brief .hpp file of the class 'UserStatus' used in the Diet Planning module
 * @version 0.1
 * @date 2024-05-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef USERSTATUS_HPP
#define USERSTATUS_HPP

#include <iostream>
using namespace std;

class UserStatus{
    private:
        float weight;
        float activityFactor;
        float actualKcals;
        float goalKcals;
    
    public:
        UserStatus();
        UserStatus(float weight);

        void setActualKcals();
        void setActivityFactor();
        void looseWeight();
        void gainWeight();
        float kCalsCalculator();
};

#endif 