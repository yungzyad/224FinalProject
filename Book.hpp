//
//  Book.hpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

#endif /* Book_hpp */
class Book{
private:
    int ISBN;
    string title;
    string author;
    string category;
    queue<string> reserverList;
public:
    //Initalize accessors
    int getISBN();
    string getTitle();
    string getAuthor();
    string getCategory();
    string getNextReserver();
    //Initalize mutators
    void setISBN(int newISBN);
    void setTitle(string newTitle);
    void setAuthor(string newAuthor);
    void setCategory(string newCategory);
    void setReserver(string newReserver);
};
