//
//  Reader.cpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#include "Reader.hpp"
#include <vector>
using namespace std;

//Accessors
int Reader::getMaxCopies(){
    return maxCopies;
}
int Reader::getPenalties(){
    return penalties;
}
//Mutators
void Reader::setMaxCopies(int max){
    maxCopies=max;
}
void Reader::setPenalties(int pen){
    penalties=pen;
}
void Reader::setCopiesBorrowed(string copyB){
    copyBorrowed=copyB;
}
void borrowCopy(){
    
}
