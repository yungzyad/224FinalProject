//
//  Librarian.hpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#ifndef Librarian_hpp
#define Librarian_hpp

#include "User.hpp"
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

class Librarian: public User{
private:
    
public:
    Librarian();
    void librarianMain();
    void newBook();
    void removeUser();
    void deleteBooks();
    void borrowBook();
    void searchUsers();
    void addUsers();
    void myInformation();
    void changePassword();
};
#endif /* Librarian_hpp */
