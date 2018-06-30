//
//  Book.cpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#include "Book.hpp"
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;


//Accessors
int Book::getISBN(){
    return ISBN;
}
string Book::getTitle(){
    return title;
}
string Book::getAuthor(){
    return author;
}
string Book::getCategory(){
    return author;
}
string Book::getNextReserver(){
    return reserverList.front();
}

//Mutators
void Book::setISBN(int newISBN){
    ISBN=newISBN;
}
void Book::setTitle(string newTitle){
    title=newTitle;
}
void Book::setAuthor(string newAuthor){
    author=newAuthor;
}
void Book::setCategory(string newCategory){
    category=newCategory;
}
void Book::setReserver(string newReserver){
    reserverList.push(newReserver);
}
