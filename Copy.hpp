//
//  Copy.hpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#ifndef Copy_hpp
#define Copy_hpp

#include "Book.hpp"
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

class Copy: public Book{
private:
    int ID;
    string reader;
    string borrowDate; //not sure if correct type for dates
    string reservationDate;
    string expirationDate;
public:
    //Initialize Accessors
    int getID();
    string getReader();
    string getBorrowDate();
    string getReservationDate();
    string getExpirationDate();
    //Initialize Mutators
    void setID(int newID);
    void setReader(string newReader);
    void setBorrowDate(string newBorrowDate);
    void setReservationDate(string newReservationDate);
    void setExpirationDate(string newExpirationDate);
};
#endif /* Copy_hpp */
