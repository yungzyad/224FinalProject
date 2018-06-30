//
//  Copy.cpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#include "Copy.hpp"
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

//Accessors
string Copy::getReader(){
    return reader;
}
string Copy::getBorrowDate(){
    return borrowDate;
}
string Copy::getReservationDate(){
    return reservationDate;
}
string Copy::getExpirationDate(){
    return expirationDate;
}
//Mutators
void Copy::setID(int newID){
    ID=newID;
}
void Copy::setReader(string newReader){
    reader=newReader;
}
void Copy::setBorrowDate(string newBorrowDate){
    borrowDate=newBorrowDate;
}
void Copy::setReservationDate(string newReservationDate){
    reservationDate=newReservationDate;
}
void Copy::setExpirationDate(string newExpirationDate){
    expirationDate=newExpirationDate;
}
