//
//  Reader.hpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp

#include "User.hpp"
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

#endif /* Reader_hpp */
class Reader: public User{
private:
    int maxCopies;
    int penalties;
    string copyBorrowed;
    string copyReserved;
public:
    //Accessor Initalization
    int getMaxCopies();
    int getPenalties();
    vector<string> getCopiesBorrowed();
    vector<string> getCopiesReserved();
    //Mutator Initialization
    void setMaxCopies(int max);
    void setPenalties(int pen);
    void setCopiesBorrowed(string copyB);
    void setCopiesReserved(string copyR);
};
