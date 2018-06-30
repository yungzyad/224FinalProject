//
//  User.hpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include "Student.hpp"
//#include "Teacher.hpp"
//#include "Librarian.hpp"

using namespace std;

class User{
public:
    User(); //parameterized constructor initialization
    string username;
    string password;
    string userType;
    void newUser();
    bool loginUser();
    void searchBook();
    void borrowBook();
    void mainMenu();
    void MyInformation();
    void changeInformation();
    void reserve();
    void returning();
    void cancelReservations();
    void logout();
    int inputTypeInt;
    //Mutator initialization
    void setUsername(string user);
    void setPassword(string pass);
    void setUserType(string userType);
    //Accessor initialization
    string getUsername();
    string getPassword();
    string getUserType();
    
};
#endif /* User_hpp */
