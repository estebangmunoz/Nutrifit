/**
 * @file user.hpp
 * @author Carlos Taillefer
 * @brief 
 * @version 0.1
 * @date 2024-05-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
using namespace std;
class User {
private:
    string name;
    string email;
    string password;
    float weight;
    float height;

public:
    User(const string name, const string email, const string password, const float weight, const float height);
    
    float getWeight() const;
    
    void setWeight(float weight);
    
    float getHeight() const;

    void setHeight(float height);
    
    void registerUser();
    
    static bool userExist(const string& email);
    
    static bool login(const string& email, const string& password);
    
    string getName() const { return name; }
    
    static User getUserByEmail(string email);
    
    static vector<string> getAllUserNames();
    
    void showUserPublications() const;

};


#endif
