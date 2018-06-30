//
//  User.cpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//
#include "User.hpp"
#include "Librarian.hpp"
#include <iostream>
#include <fstream>  //Data Files
#include <string>
#include <time.h>
using namespace std;

User::User(){
}

void User::mainMenu(){
    int loginChoice1;   //Prompting User tp Pick What they Want to do in our program
    int loginChoice;    //Prompting User tp Pick What they Want to do in our program
    ifstream Reader;            //Finds Current USER To branch to approporaite Interface
    Reader.open("Reader.txt");
    string holdStatus1;
    vector<vector<string>> readerData;
    while (!Reader.eof()) {
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect;
            string tmpString;
            for (int j = 0; j < 5; j++){
                Reader  >> tmpString;
                tmpVect.push_back(tmpString);
            }
            readerData.push_back(tmpVect);
        }
    }
    for(int i=0; i<100; i++){
        if(readerData[i][0]=="1"){
            holdStatus1=readerData[i][3];
            break;
        }
    }
    if(holdStatus1=="Student" || holdStatus1=="Teacher") {
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"-                 Welcome To My Library                   -"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"Welcome Back, "<<userType<<endl;
        cout<<endl;
        cout<<"Please Choose: "<<endl;
        cout<<"1----Search Books"<<endl;
        cout<<"2----Borrow Books"<<endl;
        cout<<"3----Return Books"<<endl;
        cout<<"4----Reserve Books"<<endl;
        cout<<"5----Cancel Reservations"<<endl;
        cout<<"6----My Information"<<endl;
        cout<<"7----Change Information"<<endl;
        cout<<"0----Log Out"<<endl;
        cin>>loginChoice;
        User a;
        switch(loginChoice){
            case 1:
                a.searchBook();
                mainMenu();
                break;
            case 2:
                a.borrowBook();
                mainMenu();
                break;
            case 3:
                a.returning();
                mainMenu();
                break;
            case 4:
                a.borrowBook();
                mainMenu();
                break;
            case 5:
                a.cancelReservations();
                mainMenu();
                break;
            case 6:
                a.MyInformation();
                mainMenu();
                break;
            case 7:
                a.changeInformation();
                mainMenu();
                break;
            case 0:
                logout();
                exit(1);
                break;
            default:
                cout<<"Not An Option!"<<endl;
                mainMenu();
                break;
        }
    }
    if(holdStatus1=="Librarian"){
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"-                 Welcome To My Library                   -"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"Welcome Back, "<<userType<<endl;
        cout<<endl;
        cout<<"Please Choose: "<<endl;
        cout<<"1----Search Books"<<endl;
        cout<<"2----Add Books"<<endl;
        cout<<"3----Delete Books"<<endl;
        cout<<"4----Search Users"<<endl;
        cout<<"5----Add Users"<<endl;
        cout<<"6----Delete Users"<<endl;
        cout<<"7----My Information"<<endl;
        cout<<"8----Change Password"<<endl;
        cout<<"0----Log Out"<<endl;
        cin>>loginChoice1;
        User a;
        Librarian b;
        switch(loginChoice1){
            case 1:
                a.searchBook();
                mainMenu();
                break;
            case 2:
                b.newBook();
                mainMenu();
                break;
            case 3:
                b.deleteBooks();
                mainMenu();
                break;
            case 4:
                b.searchUsers();
                mainMenu();
                break;
            case 5:
                b.addUsers();
                mainMenu();
                break;
            case 6:
                b.removeUser();
                mainMenu();
                break;
            case 7:
                b.myInformation();
                mainMenu();
                break;
            case 8:
                b.changePassword();
                mainMenu();
                break;
            case 0:                     
                a.logout();
                break;
        }
        cout<<"Not An Option!"<<endl;
        mainMenu();
    }
}

void User::newUser(){ 
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                   Welcome New User                      -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string user, pass, type, borrow1, penality1;      //VARS taken from  Reader.txt
    string newUsername, newPassword, newUserType; int penality=0; int borrow=0; //User Data Going into Reader.txt
    bool continues=true; bool trigger=true; //Truth condiiton statements
    vector<vector<string>> readerData;      //Holds data in Reader.txt
    int userTypeInt(0);
    ifstream userDatain;                    //Input Reader.txt File Setup
    userDatain.open("Reader.txt");
    while (!userDatain.eof()) {             //Reader.txt data is held in readerData[][]
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect;
            string tmpString;
            for (int j = 0; j < 5; j++){
                userDatain  >> tmpString;
                tmpVect.push_back(tmpString);
            }
            readerData.push_back(tmpVect);
        }
    }
    for(int i=0; i<100; i++){                //If User ENDS Program checks to see if still "LOGGED IN"
        if(readerData[i][0]=="1")
            for(int j=0; j<5; j++){
                readerData[i][j].erase();    //LOGS out user if still logged in
            }
    }
    ofstream userDataout;
    userDataout.open("Reader.txt");
    for(int i=0; i<100; i++) {              //Sending Fixed readerData to Reader.txt
        userDataout<<readerData[i][0]<<"\t"<<readerData[i][1]<<"\t"<<readerData[i][2]<<"\t"<<readerData[i][3]<<"\t"<<readerData[i][4]<<endl;
    }
    userDatain.close();
    userDataout.close();
    ofstream userData;                      //Output Reader.txt file setup
    while(continues){                       //While Loop continues as long as newUsername and newPasswor are unique
        cout<<"Enter a unique username"<<endl;
        cin>>newUsername;
        cout<<"Enter a password"<<endl;
        cin>>newPassword;
        cout<<"What type of user are you?\n"
        <<"Student.....1\n"
        <<"Teacher.....2\n"
        <<"Librarian...3\n"<<endl;
        cin>>userTypeInt;
        switch(userTypeInt){ //set user type string from integer input
            case 1:
                newUserType="Student";
                break;
            case 2:
                newUserType="Teacher";
                break;
            case 3:
                newUserType="Librarian";
                break;
            default:
                cout<<"Thats Not An Option!"<<endl;
                exit(1);
        }
        userDatain.open("Reader.txt");
        while(!userDatain.eof()){   //Checks to see if new username and passwords are unique
            userDatain>>user>>pass>>type>>borrow1>>penality1;
            if(newUsername==user){
                cout<<"Username Already Exists. Pick A New Username!"<<endl;
                userDatain.close();
                trigger=false;
                break;
            }
            if(newPassword==pass){
                cout<<"Password Already Exists. Pick A New Password!"<<endl;
                userDatain.close();
                trigger=false;
                break;
            }
        }
        if(trigger){    //Breaks if the username and password are unique
            break;
        }
    }
    cout<<"\nProfile Successfully Created! \n\nYour Username is: "<<newUsername
    <<"\nYour Password is: "<<newPassword
    <<"\nYour User Type is: "<<newUserType
    <<endl<<endl;
    userDataout.open("Reader.txt", ios::app);
    userDataout<<newUsername<<"\t"<<newPassword<<"\t"<<newUserType<<"\t"<<penality<<"\t"<<borrow<<endl;
    userDataout.close();
}

bool User::loginUser(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                           Log In                        -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    int newUserChoice;
    int inputTypeInt;
    string inputUser, inputPass, inputType, line, userAndPass;
    string user, pass, type;
    bool found=false;
    
    vector<vector<string>> readerData;  //Holds data in Reader.txt
    ifstream userDatain;                //Input Reader.txt file setup
    userDatain.open("Reader.txt");
    while (!userDatain.eof()) {         //Reader.txt data is held in readerData[][]
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect;
            string tmpString;
            for (int j = 0; j < 5; j++){
                userDatain  >> tmpString;
                tmpVect.push_back(tmpString);
            }
            readerData.push_back(tmpVect);
        }
    }
    for(int i=0; i<100; i++){                //If User ENDS Program checks to see if still "LOGGED IN"
        if(readerData[i][0]=="1")
            for(int j=0; j<5; j++){
                readerData[i][j].erase();    //LOGS out user if still logged in
            }
    }
    ofstream userDataout;
    userDataout.open("Reader.txt");
    for(int i=0; i<100; i++) {              //Sending Fixed readerData to Reader.txt
        userDataout<<readerData[i][0]<<"\t"<<readerData[i][1]<<"\t"<<readerData[i][2]<<"\t"<<readerData[i][3]<<"\t"<<readerData[i][4]<<endl;
    }
    userDataout.close();
    cout<<"Enter Username(Case Sensitive)"<<endl;     //return true if login info is correct
    cin>>inputUser;
    cout<<"Enter Password(Case Sensitive)"<<endl;
    cin>>inputPass;
    cout<<"What type of user are you?\n"
    <<"Student.....1\n"
    <<"Teacher.....2\n"
    <<"Librarian...3"<<endl;
    cin>>inputTypeInt;
    switch(inputTypeInt){   //set user type string from integer input
        case 1:
            inputType="Student";
            break;
        case 2:
            inputType="Teacher";
            break;
        case 3:
            inputType="Librarian";
            break;
        default:
            cout<<"Thats Not An Option"<<endl;
            loginUser();
            break;
    }
    for(int i=0; i<100; i++){
        if((readerData[i][0]==inputUser) && (readerData[i][1]==inputPass) && (readerData[i][2]==inputType)){
            username=user;password=pass;userType=type;
            found=true; // found is true => break loop
            break;
        }
    }
    if(found) {       //If username and password are found in Reader.txt
        username=inputUser;
        password=inputPass;
        ofstream current;   //Output Reader.txt file setup
        current.open("Reader.txt", ios::app);
        current<<"1"<<"\t"<<inputUser<<"\t"<<inputPass<<"\t"<<inputType<<"\t"<<"0"<<endl;  //Appends Reader.txt with currently LOGGED IN user
        current.close();
        mainMenu();
        return true;
    } //Ends if(found)
    else {
        cout<<"\nUsername and/or password incorrect.Try Again!"<<endl;
        cout<<"What Would You Like To Do"<<endl;
        cout<<"Make a New Account......1"<<endl;
        cout<<"Retry Username and Password.......2"<<endl;
        cin>>newUserChoice;
        if(newUserChoice==1){
            newUser();
        }
        loginUser(); //Restart Login Sequence
    }
    return false;
}

void User::searchBook(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                Search A Book In Our Library             -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string bookName, authorsName, ISBN, category, copyNumber;    //User specified search data
    vector<vector<string>> bookData;       //Holds data in Copy.txt
    fstream Library;                       //Input Copy.txt File Setup
    Library.open("Copy.txt");
    if(Library.fail()) {
        cerr<<"Library Can't be accessed at this moment"<<endl;
        exit(1);
    }
    while (!Library.eof()) {    //Inputs data from Copy.txt into bookData
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect;
            string tmpString;
            
            for (int j = 0; j < 5; j++){
                Library  >> tmpString;
                tmpVect.push_back(tmpString);
            }
            bookData.push_back(tmpVect);
        }
    }
    bool noBook=false;   //Condititon for no book
    Library.close();     //Always Start By Restarting Lib.txt to Ensure We Start From Top
    Library.open("book.txt");
    int searchOption, continueSearch;
    cout<<"How Would you like to Search for the book?"<<endl;   //prompting user search option
    cout<<"Book Name........1"<<endl;
    cout<<"Author's Name....2"<<endl;
    cout<<"ISBN Number......3"<<endl;
    cout<<"Category.........4"<<endl;
    cout<<endl;
    cin>>searchOption;
    switch (searchOption) {   //Switch Statement for "How user wants to Search"
        case 1:               //Case 1: Book Name Search
            cout<<"Please Enter Book Name: "<<endl;
            cin.ignore();
            getline (cin,bookName);
            bookName.erase(remove(bookName.begin(),bookName.end(),' '),bookName.end()); //Lets User use spaces
            transform(bookName.begin(), bookName.end(), bookName.begin(), ::toupper);   //Lets User use lower/upper case
            cout<<endl;
            for(int i=0; i<100; i++){
                if(bookName==bookData[i][1]){                   //Compares user specified book name to data in bookData
                    cout<<"Book Has Been Found"<<endl<<endl;   //Displays information of the book found
                    cout<<"Book Name: "<<bookData[i][1]<<endl;
                    cout<<"Author: "<<bookData[i][2]<<endl;
                    cout<<"ISBN: "<<bookData[i][3]<<endl;
                    cout<<"Category: "<<bookData[i][4]<<endl<<endl;
                    noBook=true;
                    break;      //Breaks so that only 1 copy of the book is displasy(don't need all copies)
                }
            }
            if(noBook==false){  //Book not found in Copy.txt or bookData
                cout<<"Our Library Doesn't Have That book!"<<endl<<endl;
                cout<<"Would You Like to Continue Search"<<endl;
                cout<<"Yes......1"<<endl;
                cout<<"No.......2"<<endl;
                cin>>continueSearch;
                if(continueSearch==1)
                    searchBook();
                if(continueSearch==2) {  //Program Ends if User Doesnt Want to Search Anymore
                    cout<<"Going Back To Main Menu!"<<endl;
                    mainMenu();
                    break;
                }
            }
            break;
        case 2: //Same as bookName search option but with Author's name
            cout<<"Please Enter Author Name: "<<endl;
            cin.ignore();
            getline (cin,authorsName);
            authorsName.erase(remove(authorsName.begin(),authorsName.end(),' '),authorsName.end()); //Lets User use spaces
            transform(authorsName.begin(), authorsName.end(), authorsName.begin(), ::toupper);   //Lets User use lower/upper case
            cout<<endl;
            for(int i=0; i<100; i++){
                if(authorsName==bookData[i][2]){                   //Compares user specified book name to data in bookData
                    cout<<"Book Has Been Found"<<endl<<endl;   //Displays information of the book found
                    cout<<"Book Name: "<<bookData[i][1]<<endl;
                    cout<<"Author: "<<bookData[i][2]<<endl;
                    cout<<"ISBN: "<<bookData[i][3]<<endl;
                    cout<<"Category: "<<bookData[i][4]<<endl<<endl;
                    noBook=true;
                    break;      //Breaks so that only 1 copy of the book is displasy(don't need all copies)
                }
            }
            if(noBook==false){
                cout<<"Our Library Doesn't Have That book!"<<endl<<endl;
                cout<<"Would You Like to Continue Search"<<endl;
                cout<<"Yes......1"<<endl;
                cout<<"No.......2"<<endl;
                cin>>continueSearch;
                if(continueSearch==1)
                    searchBook();
                if(continueSearch==2) {               //Program Ends if User Doesnt Want to Search Anymore
                    cout<<"Going Back To Main Menu!"<<endl;
                    mainMenu();
                break;
                }
            }
            break;
        case 3: //Same as bookName search option but with ISBN
            cout<<"Please Type The ISBN Number Including Dashes (ex. 123-4-56-789012-3): "<<endl;
            cin>>ISBN;
            for(int i=0; i<100; i++){
                if(ISBN==bookData[i][3]){                   //Compares user specified book name to data in bookData
                    cout<<"Book Has Been Found"<<endl<<endl;   //Displays information of the book found
                    cout<<"Book Name: "<<bookData[i][1]<<endl;
                    cout<<"Author: "<<bookData[i][2]<<endl;
                    cout<<"ISBN: "<<bookData[i][3]<<endl;
                    cout<<"Category: "<<bookData[i][4]<<endl<<endl;
                    noBook=true;
                    break;      //Breaks so that only 1 copy of the book is displasy(don't need all copies)
                }
            }
            if(noBook==false){
                cout<<"Our Library Doesn't Have That book!"<<endl<<endl;
                cout<<"Would You Like to Continue Search"<<endl;
                cout<<"Yes......1"<<endl;
                cout<<"No.......2"<<endl;
                cin>>continueSearch;
                if(continueSearch==1)
                    searchBook();
                if(continueSearch==2) {               //Program Ends if User Doesnt Want to Search Anymore
                    cout<<"Going Back To Main Menu!"<<endl;
                    mainMenu();
                    break;
                }
            }
            break;
        case 4: //Same as bookName search option but with Category
            cout<<"Please Enter The Category You Want To Search: "<<endl;
            cin.ignore();
            getline (cin,category);
            category.erase(remove(category.begin(),category.end(),' '),category.end());
            transform(category.begin(), category.end(), category.begin(), ::toupper);
            cout<<endl;
            for(int i=0; i<100; i++){
                if(category==bookData[i][4]){                   //Compares user specified book name to data in bookData
                    cout<<"Book Has Been Found"<<endl<<endl;   //Displays information of the book found
                    cout<<"Book Name: "<<bookData[i][1]<<endl;
                    cout<<"Author: "<<bookData[i][2]<<endl;
                    cout<<"ISBN: "<<bookData[i][3]<<endl;
                    cout<<"Category: "<<bookData[i][4]<<endl<<endl;
                    noBook=true;
                    break;      //Breaks so that only 1 copy of the book is displasy(don't need all copies)
                }
            }
            if(noBook==false){
                cout<<"Our Library Doesn't Have That book!"<<endl<<endl;
                cout<<"Would You Like to Continue Search"<<endl;
                cout<<"Yes......1"<<endl;
                cout<<"No.......2"<<endl;
                cin>>continueSearch;
                if(continueSearch==1)
                    searchBook();
                if(continueSearch==2) {               //Program Ends if User Doesnt Want to Search Anymore
                    cout<<"Going Back To Main Menu!"<<endl;
                    mainMenu();
                    break;
                }
            }
            break;
        default:
            cout<<"Thats Not An Option. Going to Main Menu"<<endl;
            mainMenu();
    }
    int r;  //prompting to main menu
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
    mainMenu();
}


void User::borrowBook() {
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-          Borrow/Reserve A Book From Our Library         -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string borrowOption, reserveOption;                                        //User Options for Borrow
    string bookName;    //Book Name specified by user
    string cCopy, cName, cAuthor, cISBN, cCategory;                           //Search Data for Copy.txt
    string bCopy, bName, bAuthor, bISBN, bCategory, bUsername, bTime;         //Search Data for Borrow.txt
    string holdUser, holdPass, holdStatus; int holdBorrow, holdPenalities;    //Stores info from Reader.txt of the person LOGGED IN
    string value, user, pass, status, zero;                                   //Data taken from Reader.txt
    string username, password, usertype; int borrow, penalities;              //Formatted Data taken from Reader.txt
    string startTime;   //Timing
    bool bookExist=false;
    vector<vector<string>> bookData;    //Vector holds data in Book.txt
    vector<vector<string>> copyData;    //Vector holds data in Copy.txt
    vector<vector<string>> readerData;  //Vector holds data in Reader.txt
    vector<vector<string>> reserveData; //Vectors holds data in Reserve.txt
    ifstream Reader;                                                //Input Reader.txt File Setup
    Reader.open("Reader.txt");
    if(Reader.fail()){
        cerr<<"Data Can't be accessed at this moment"<<endl;
        exit(1);
    }
    ifstream borrows;                                               //Input Book.txt File Setup
    borrows.open("Book.txt");
    if(borrows.fail()) {
        cerr<<"Data Can't be accessed at this moment"<<endl;
        exit(1);
    }
    ifstream copies;                                                //Input Copy.txt File Setup
    copies.open("Copy.txt");
    if(copies.fail()) {
        cerr<<"Data Can't be accessed at this moment"<<endl;
        exit(1);
    }
    ifstream Reserve;                                               //Input Librarian.txt file setup
    Reserve.open("Librarian.txt");
    if(Reserve.fail()) {
        cerr<<"Data Can't be accessed at this moment"<<endl;
        exit(1);
    }
    while (!Reader.eof()) {     //Data from Reader.txt goes into readerData
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect2;
            string tmpString2;
            for (int j = 0; j < 5; j++){
                Reader>>tmpString2;
                tmpVect2.push_back(tmpString2);
            }
            readerData.push_back(tmpVect2);
        }
    }
    while (!copies.eof()) {     //Data from Copy.txt goes into copyData
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect2;
            string tmpString2;
            for (int j = 0; j < 5; j++){
                copies>>tmpString2;
                tmpVect2.push_back(tmpString2);
            }
            copyData.push_back(tmpVect2);
        }
    }
    while (!Reserve.eof()) {     //Data from Reserve.txt goes into reserveData
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect2;
            string tmpString2;
            for (int j = 0; j < 5; j++){
                Reserve>>tmpString2;
                tmpVect2.push_back(tmpString2);
            }
            reserveData.push_back(tmpVect2);
        }
    }
    while (!borrows.eof()) {     //Data from Book.txt goes into bookData
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect2;
            string tmpString2;
            for (int j = 0; j < 7; j++){
                borrows>>tmpString2;
                tmpVect2.push_back(tmpString2);
            }
            bookData.push_back(tmpVect2);
        }
    }
    borrows.close();
    borrows.open("Book.txt");
    copies.close();
    copies.open("Copy.txt");
    Reader.close();
    Reader.open("Reader.txt");
    Reserve.close();
    Reserve.open("Librarian.txt");
    copies.close();
    copies.open("Copy.txt");
    Reader.close();
    Reader.open("Reader.txt");
    Reserve.close();
    Reserve.open("Librarian.txt");
    while(!Reader.eof()){
        Reader>>value>>user>>pass>>status>>zero;    //searching for username, password, status of the person CURRENTLY LOGGED IN
        if(value=="1"){
            holdUser=user;
            holdPass=pass;
            holdStatus=status;
            break;  //breaking from loop once data is obtained
        }
    }
    time_t timer;                    //Checking to make sure Borrows/Reserves are not exceeding their time
    struct tm y2k = {0};
    double seconds3;
    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    time(&timer);  /* get current time; same as: timer = time(NULL)  */
    seconds3 = difftime(timer,mktime(&y2k));
    seconds3=seconds3-566188000;
    double times;
    double timing;
    int penality1, penality2;
    for(int i=0; i<100; i++) {
        timing = atoi(bookData[i][6].c_str());
        times=((seconds3-timing)/5);
        if((times>30) && (holdStatus=="Student") && (holdUser==readerData[i][0])){
             if(readerData[i][3]!="0"){
                 cout<<"student active"<<endl;
                 penality1 = atoi(readerData[i][4].c_str());
                 penality1=penality1+1;
                 std::string s = std::to_string(penality1);
                 readerData[i][4]=s;
                 bookData[i][6]="10000000000000000";
             }
        }
        if((times>50) && (holdStatus=="Teacher") && (holdUser==readerData[i][0])){
            if(readerData[i][3]!="0"){
                penality2 = atoi(readerData[i][4].c_str());
                penality2=penality2+1;
                std::string s = std::to_string(penality2);
                readerData[i][4]=s;
                bookData[i][6]="10000000000000000";
            }
        }
    }
    ofstream borrowing;
    borrowing.open("Book.txt");
    for(int i=0; i<100; i++){
        borrowing<<bookData[i][0]<<" "<<bookData[i][1]<<" "<<bookData[i][2]<<" "<<bookData[i][3]<<" "<<bookData[i][4]<<" "<<bookData[i][5]<<" "<<bookData[i][6]<<endl;
    }
    borrowing.close();
    Reader.close();
    Reader.open("Reader.txt");
    while(!Reader.eof()){      //searching for the borrow count and penality total of the account associated with the person above
        Reader>>username>>password>>usertype>>borrow>>penalities;
        if(holdUser==username){
            holdBorrow=borrow;
            holdPenalities=penalities;
            break;  //breaking from loop once data is obtained
        }
    }
    //Borrowing Starts Here
    cout<<"Please Enter the Name of the Book You Would like To Borrow: "<<endl; //prompting user to enter Book Name
    cin.ignore();
    getline (cin,bookName);
    bookName.erase(remove(bookName.begin(),bookName.end(),' '),bookName.end()); //Lets User use spaces
    transform(bookName.begin(), bookName.end(), bookName.begin(), ::toupper);   //Lets User use lower/upper case
    cout<<endl;
    
    while(!copies.eof()){
        copies>>cCopy>>cName>>cAuthor>>cISBN>>cCategory;
        if(bookName==cName) {         //Checking if User-Requested Book is in Copy.txt
            bookExist=true;
            cout<<"Book Has Been Found:"<<endl<<endl;;
            cout<<"Copy Number: "<<cCopy<<endl;
            cout<<"Book Name: "<<cName<<endl;
            cout<<"Author: "<<cAuthor<<endl;
            cout<<"ISBN: "<<cISBN<<endl;
            cout<<"Category: "<<cCategory<<endl<<endl;
            cout<<"Would You Like To Borrow this Book?"<<endl;
            cout<<"Yes......1"<<endl;
            cout<<"No.......2"<<endl;
            cin>>borrowOption;
            if(borrowOption=="1"){
                if(holdBorrow>=5 && holdStatus=="Student"){
                    cout<<"Students Can't borrow more than 5 books Sorry. Return Some books first!"<<endl;
                    break;
                }
                if(holdBorrow>=10 && holdStatus=="Teacher"){
                    cout<<"Teachers Can't borrow more than 10 books Sorry. Return Some books first!"<<endl;
                    break;
                }
                time_t timer;       //Beginning of the Time Algorithm
                struct tm y2k = {0};
                double seconds;
                y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
                y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
                time(&timer);  /* get current time; same as: timer = time(NULL)  */
                seconds = difftime(timer,mktime(&y2k));
                //We will use this time from jan 1, 2000 to compare to when the individual first borrowed the book and when he returns it (difference)
                seconds=seconds-566188000;
                ofstream borrowing;
                borrowing.open("Book.txt", ios::app);
                borrowing<<cCopy<<" "<<cName<<" "<<cAuthor<<" "<<cISBN<<" "<<cCategory<<" "<<holdUser<<" "<<seconds<<endl;
                borrowing.close();
                for(int i=0; i<100; i++) {      //Comparing copyData to user input for bookName
                    if(cName==copyData[i][1] && cCopy==copyData[i][0]){
                        for(int j=0; j<5; j++) {
                            copyData[i][j].erase(); //Deletes book in Copy.txt
                        }
                    }
                }
                ofstream copying;
                copying.open("Copy.txt");
                for(int i=0; i<100; i++){   //Send copyData with the borrow book now deleted
                    copying<<copyData[i][0]<<" "<<copyData[i][1]<<" "<<copyData[i][2]<<" "<<copyData[i][3]<<" "<<copyData[i][4]<<endl;
                }
                copying.close();
                holdBorrow=holdBorrow+1; //Increment the amount of borrows;
                ofstream Reading;    //output Reader.txt file setup
                Reading.open("Reader.txt");
                for(int i=0; i<100; i++){   //Send increase borrow count in readerData file to Reader.txt
                    if(readerData[i][0]==holdUser){
                        std::string s = std::to_string(holdBorrow);
                        readerData[i][3]=s;
                    }
                    if(readerData[i][2]=="Librarian"){
                        readerData[i][4]="0";
                    }
                    Reading<<readerData[i][0]<<"\t"<<readerData[i][1]<<"\t"<<readerData[i][2]<<"\t"<<readerData[i][3]<<"\t"<<readerData[i][4]<<endl;
                }
                Reading.close();
                break;
            }
            if(borrowOption=="2"){    //If User doesnt want to Borrow, we go back to main menu
                break;
            }
                break;  //Once one copy of the book is taken, exit the while loop
            }
    }
    bool library=false;
    string testCopy, testName, testAuthor, testISBN, testCategory, testUsername; double seconds;
    if(bookExist==false){
        while(!borrows.eof()){
            borrows>>testCopy>>testName>>testAuthor>>testISBN>>testCategory>>testUsername>>seconds;
            if(bookName==testName){
                library=true;
                cout<<"All Copies of that Book are Taken Out. Would You Like to Reserve it?"<<endl;
                cout<<"Yes......1"<<endl;
                cout<<"No.......2"<<endl;
                cin>>reserveOption;
                ofstream reserving;
                reserving.open("Librarian.txt");
                if(reserveOption=="1"){
                    reserving<<holdUser<<" "<<bookName<<endl;
                    break;
                }
                if(reserveOption=="2"){
                    break;
                }
            }
        }
        if(library==false){
            cout<<"We don't own that book in our Library. Sorry!"<<endl;
        }
    }
    Reader.close();
    string r; //prompting to main menu
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
}

void User::returning(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                Return A Book From Our Library           -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string bookName, copyNumber;         //Name of Book User wants to return
    vector<vector<string>> readerData;  //holds data from Reader.txt
    vector<vector<string>> borrowData;  //holds data from Book.txt
    string user, pass, status; int borrow, penality; //Data from Reader.txt
    cout<<"Please Enter the Name of the Book You Want to Return"<<endl;     //Gets book name
    cin.ignore();
    getline (cin,bookName);
    cout<<"Please Enter the Copy Number ID"<<endl;          //Gets ID of the book
    cin>>copyNumber;
    bookName.erase(remove(bookName.begin(),bookName.end(),' '),bookName.end()); //Lets User use spaces
    transform(bookName.begin(), bookName.end(), bookName.begin(), ::toupper);   //Lets User use lower/upper case
    cout<<endl;
    ifstream Reader;                //input Reader.txt file setup
    Reader.open("Reader.txt");
    if(Reader.fail()){
        cerr<<"Files Can't Be accessed!"<<endl;
        exit(1);
    }
    while (!Reader.eof()) {     //Data from Reader.txt goes into readerData
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect2;
            string tmpString2;
            for (int j = 0; j < 5; j++){
                Reader>>tmpString2;
                tmpVect2.push_back(tmpString2);
            }
            readerData.push_back(tmpVect2);
        }
    }
    Reader.close();
    Reader.open("Reader.txt");
    string userHold;
    for(int i=0; i<100; i++){                       //step 1: Finds LOGGED IN User
        if(readerData[i][0]=="1"){
            userHold=readerData[i][1];
            break;
        }
    }
    int holdBorrows;                                   //step 2: Holds borrows of person
    string username, password, usertype; int borrows, penalities;
    while(!Reader.eof()){
        Reader>>username>>password>>usertype>>borrows>>penalities;
        if(userHold==username){
            holdBorrows=borrows;
            break;                                  //breaking from loop once data is obtained
        }
    }
    Reader.close();
    holdBorrows=holdBorrows-1;                      //step 3: Decrement Borrow
    for(int i=0; i<100; i++){
        if(readerData[i][0]==userHold){
            std::string s = std::to_string(holdBorrows);
            readerData[i][3]=s;
        }
    }
    ofstream Reading;                           //step 4: Sending fixed data back to Reader
    Reading.open("Reader.txt");
    for(int i=0; i<100; i++){
        Reading<<readerData[i][0]<<"\t"<<readerData[i][1]<<"\t"<<readerData[i][2]<<"\t"<<readerData[i][3]<<"\t"<<readerData[i][4]<<endl;
    }
    Reading.close();
    Reader.close();
    ifstream Book;                              //input Book.txt file setup
    Book.open("Book.txt");
    if(Book.fail()){
        cerr<<"Files Can't Be accessed!"<<endl;
        exit(1);
    }
    while (!Book.eof()) {                       //Data from Reader.txt goes into readerData
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect2;
            string tmpString2;
            for (int j = 0; j < 7; j++){
                Book>>tmpString2;
                tmpVect2.push_back(tmpString2);
            }
            borrowData.push_back(tmpVect2);
        }
    }
    Book.close();
    string copy, title, author, ISBN, Category;         //step 1: Stores Value of book to send to Copy.txt
    bool trigger=true;      //Trigger the fact that we dont have the book
    for(int i=0; i<100; i++){
        if((borrowData[i][1]==bookName) && (borrowData[i][0]==copyNumber)) {
            trigger=false;
            copy=borrowData[i][0];
            title=borrowData[i][1];
            author=borrowData[i][2];
            ISBN=borrowData[i][3];
            Category=borrowData[i][4];
            for(int j=0; j<7; j++){
                borrowData[i][j].erase();           //step 2: Erase the returned book
            }
        }
    }
    if(trigger==true){
        cout<<"You Don't Have this book borroed!"<<endl;
    }
    ofstream borrowing;                               //step 3: Sending fixed data back to Book.txt
    borrowing.open("Book.txt");
    for(int i=0; i<100; i++){
        borrowing<<borrowData[i][0]<<" "<<borrowData[i][1]<<" "<<borrowData[i][2]<<" "<<borrowData[i][3]<<" "<<borrowData[i][4]<<" "<<borrowData[i][5]<<" "<<borrowData[i][6]<<endl;
    }
    borrowing.close();
    ofstream Copy;                      //input Copy.txt file setup
    Copy.open("Copy.txt", ios::app);    //Step 1: send book back to copy to be available for borrowing
    Copy<<copy<<" "<<title<<" "<<author<<" "<<ISBN<<" "<<Category<<endl;
    Copy.close();
    string r;                                   //prompting user to main meny
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
    
}

void User:: cancelReservations(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                    Cancel Reservations                  -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string bookName;
    string user, pass, status; int borrow, penality;    //VARS from Reader.txt
    string username, bookTitle;                         //VARS from Librarian.txt
    string holdUser;                                    //Holds User of currently LOGGED IN
    vector<vector<string>> Reserve;                     //Holds Data in Reader.txt
    cout<<"What is the Name of the Book You want to Cancel your Reservation For?"<<endl;
    cin>>bookName;
    ifstream Reader;                                    //Input Reader.txt File Setup
    Reader.open("Reader.txt");
    while(!Reader.eof()){
        Reader>>user>>pass>>status>>borrow>>penality;
        if(user=="1"){
            holdUser=pass;
            break;
        }
    }
    ifstream reserve;
    reserve.open("Librarian.txt");
    while (!reserve.eof()) {                //Data from Librarian.txt goes into Reserve
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect2;
            string tmpString2;
            for (int j = 0; j < 3; j++){
                reserve>>tmpString2;
                tmpVect2.push_back(tmpString2);
            }
            Reserve.push_back(tmpVect2);
        }
    }
    for(int i=0; i<100; i++){               //Erasing That Resrvation
        if(Reserve[i][0]==holdUser)
            for(int j=0; j<3; j++){
                Reserve[i][j].erase();
            }
    }
    ofstream reserving;                     //Sending the Erased Data back To Librarian.txt
    reserving.open("Librarian.txt");
    for(int i=0; i<100; i++){
        reserving<<Reserve[i][0]<<" "<<Reserve[i][1]<<" "<<Reserve[i][2];
    }
    cout<<"Reservation Canceled"<<endl;
    string r;                                   //prompting user to main meny
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
  
}

void User::MyInformation() {
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                        My Information                   -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string username, password, usertype; int borrow, penalities;   //VARS representing all accounts in Reader.txt
    string value, user, pass, status; int zero;     //VARS representin currently LOGGED IN user in Reader.txt
    int holdBorrow, holdPenalities; string holdUser, holdPass, holdStatus; //Holds data when cycling through Reader.txt
    ifstream Reader;    //Input Reader.txt file setup
    Reader.open("Reader.txt");
    while(!Reader.eof()){
        Reader>>value>>user>>pass>>status>>zero;    //searching for username, password, status of the person CURRENTLY LOGGED IN
        if(value=="1"){
            holdUser=user;
            holdPass=pass;
            holdStatus=status;
            break;  //breaking from loop once data is obtained
        }
    }
    Reader.close();
    Reader.open("Reader.txt");
    while(!Reader.eof()){      //searching for the borrow count and penality total of the account associated with the person above
        Reader>>username>>password>>usertype>>borrow>>penalities;
        if(holdUser==username){
            holdBorrow=borrow;
            holdPenalities=penalities;
            break;  //breaking from loop once data is obtained
        }
    }
    cout<<"Your Username is: "<<holdUser<<endl;
    cout<<"Your Password is: "<<holdPass<<endl;
    cout<<"Your Status is: "<<holdStatus<<endl;
    cout<<"Number of Copies Borrowed: "<<holdBorrow<<endl;
    cout<<"Number of Penalities: "<<holdPenalities<<endl;
    Reader.close();
    string r;  //prompting user to main meny
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
}

void User:: changeInformation() {
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                      Change Information                 -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string password1, password2, username1;       //User specified new passwords
    string user, pass, type;
    
    vector<vector<string>> readerData;  //readerData holds information in Reader.txt
    ifstream Reader;                    //Input file setup for Reader.txt
    Reader.open("Reader.txt");
    for(int i = 0; i < 100; i++){   //Inputs data from Reader.txt into readerData
        vector<string> tmpVect;
        string tmpString;
        for (int j = 0; j < 5; j++){
            Reader  >> tmpString;
            tmpVect.push_back(tmpString);
        }
        readerData.push_back(tmpVect);
    }
    while(1) {  //Prompts user to input new passwords
        cout<<"Enter Your New Username (Case Sensitive)"<<endl;
        cin>>username1;
        cout<<"Enter Your New Password (Case Sensitive)"<<endl;
        cin>>password1;
        cout<<"Enter Your New Password Again(Case Sensitive)"<<endl;
        cin>>password2;
        if(password1!=password2){
            cout<<"Those Passwords Dont Match. Try Again."<<endl;}
        else{    //if passwords match, breaks out of loo[
            cout<<endl<<"Information Changed!"<<endl;
            break;
        }
    }
    int rowHold1;      //Holds location of the row that the LOGGED IN user's password is found
    string passHold;   //Holds the password for the LOGGED IN user
    string userHold;
    for(int i=0; i<100; i++){
        if(readerData[i][0]=="1"){
            rowHold1=i;
            passHold=readerData[i][2];
            userHold=readerData[i][1];
            break;
        }
    }
    int rowHold;
    for(int i=0; i<100; i++){
        if(passHold==readerData[i][1]){     //Checks to see if LOGGED IN users password matches with password in Reader.txt
            rowHold=i;                      //Holds the row that this occurs in
            break;
        }
    }
    readerData[rowHold][1]=password1;       //Sets new password to the LOGGED IN data
    readerData[rowHold1][2]=password1;      //Sets new password to User's information
    readerData[rowHold][0]=username1;       //Sets new username to the LOGGED IN data
    readerData[rowHold1][1]=username1;      //Sets new username to User's information
    ofstream ReaderOut;
    ReaderOut.open("Reader.txt");           //Ouput Reader.txt file setup
    for(int i=0; i<100; i++){               //Sends updated readerData[][] information to Reader.txt
        ReaderOut<<readerData[i][0]<<"\t"<<readerData[i][1]<<"\t"<<readerData[i][2]<<"\t"<<readerData[i][3]<<"\t"<<readerData[i][4]<<endl;
    }
    string r;       //prompting to main menu
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
}

void User::logout(){
    //Variable Declaration
    vector<vector<string>> readerData;                  //Holds Data in Reader.txt
    //Log Out Algorithm
    cout<<"Logging Out. Thank You."<<endl;
    ifstream Current;
    Current.open("Reader.txt");
    while(!Current.eof()){
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect;
            string tmpString;
            for (int j = 0; j < 5; j++){
                Current  >> tmpString;
                tmpVect.push_back(tmpString);
            }
            readerData.push_back(tmpVect);       //Wil have a removed unit
        }
    }
    Current.close();
    for(int i=0; i<100; i++){
        if(readerData[i][0]=="1"){
            for(int h=0; h<5; h++){
                readerData[i][h].erase();
            }
            break;
        }
    }
    ofstream Currentout;
    Currentout.open("Reader.txt", std::ofstream::out | std::ofstream::trunc);
    Currentout.close();
    Currentout.open("Reader.txt");
    for(int i=0; i<100; i++){
        Currentout<<readerData[i][0]<<"\t"<<readerData[i][1]<<"\t"<<readerData[i][2]<<"\t"<<readerData[i][3]<<"\t"<<readerData[i][4]<<endl;
    }
    exit(1);

}


