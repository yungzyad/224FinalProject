//
//  main.cpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#include <iostream>
#include <string>
#include "User.hpp"
#include "Book.hpp"
#include "Librarian.hpp"
using namespace std;

int main() {
    int userSetup(0);
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                 Welcome Back, To My Library             -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl<<endl;
    cout<<"New User...........1\n";
    cout<<"Returning User.....2"<<endl;
    cin>>userSetup;
    User a;
    Librarian b;
    switch(userSetup){
        case 1: //Initialize new user/pass/type
            a.newUser();
        case 2: //Get login info
            a.loginUser();
        break;
    }
    return 0;
}
