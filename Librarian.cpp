//
//  Librarian.cpp
//  224FinalProject
//
//  Created by Zyad Gomaa on 11/10/17.
//  Copyright © 2017 Zyad Gomaa. All rights reserved.
//

#include "Librarian.hpp"
#include "User.hpp"
#include <string>
#include <sstream>
using namespace std;

Librarian::Librarian(){
}

void Librarian::newBook(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-              Make a New Book In Our Library             -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string newBookName, newAuthorName, newISBN, newCategory, newCopies, newBookNumber; int copyNumber; //User Specified new Book Data
    int choice;
    vector<vector<string>> copyData;            //Vector Holding information from Copy.txt
    ofstream copiesUpdated;                     //Output File Setup for Copy.txt
    copiesUpdated.open("Copy.txt", ios::app);
    cout<<"What Would You Like To Do?"<<endl    //Prompting User option to continue
        <<"Continue.............1"<<endl
        <<"Main Menu......2"<<endl;
    cout<<endl;
    cin>>choice;
    switch(choice){
        case 1://Create new book
            cout<<"What is the title of the book?"<<endl;
            cin.ignore();                       //Input BookName
            getline (cin,newBookName);
            newBookName.erase(remove(newBookName.begin(),newBookName.end(),' '),newBookName.end()); //Ignoring whitespaces
            transform(newBookName.begin(), newBookName.end(), newBookName.begin(), ::toupper);      //Converting to Upper to format
            cout<<"What is the Author's full name?"<<endl;
            getline (cin,newAuthorName);        //Input Authors Name
            newAuthorName.erase(remove(newAuthorName.begin(),newAuthorName.end(),' '),newAuthorName.end()); //Ignoring whitespaces
            transform(newAuthorName.begin(), newAuthorName.end(), newAuthorName.begin(), ::toupper);        //Converting to Upper to format
            cout<<"Please Type The ISBN Number Including Dashes (ex. 123-4-56-789012-3):"<<endl;
            cin>>newISBN;      //Input ISBN
            cout<<"What is the Category?"<<endl;
            cin.ignore();      //Input Category
            getline (cin,newCategory);
            newCategory.erase(remove(newCategory.begin(),newCategory.end(),' '),newCategory.end()); //Ignoring whitespaces
            transform(newCategory.begin(), newCategory.end(), newCategory.begin(), ::toupper);      //Converting to Upper to format
            cout<<"How Many Copies Do You Want To Add?"<<endl;
            cin>>newCopies;    //Input Number of Copies
            copyNumber = atoi(newCopies.c_str());           //Convert newCopies string to INT COPYNUMBER
            for(int j=1; j<=copyNumber; j++){               //Convert j to string
                stringstream ss;
                ss << j;
                string str = ss.str();
                copiesUpdated<<str<<" "<<newBookName<<" "<<newAuthorName<<" "<<newISBN<<" "<<newCategory<<endl; //Output Book Data to Copy.txt
            }
            break;
        case 2:                                     //Jumps to mainMenu() function in User Class
            break;
        default:
            cout<<"Thats Not An Option!"<<endl;
    }
    cout<<endl;
    cout<<"Book Added!"<<endl;
    string r;                                       //Jumps to mainMenu() function in User Class
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
}

void Librarian::deleteBooks(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                Delete a Book In Our Library             -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    bool bookExist=false;                       //Tells Us if Book Exists
    vector<vector<string>> copyData;            //Vector that holds data in Copy.txt
    string bookName;                            //User specified Book Name
    string copyNumber;                          //User specified Copy Number of Book
    ifstream copies;                            //Input Copy.txt File Setup
    copies.open("Copy.txt");
    if(copies.fail()) {
        cerr<<"Library Can't be accessed at this moment"<<endl;
        exit(1);
    }
    ofstream copiesUpdated;                     //Output Copy.txt File Setup
    while (!copies.eof()) {
        for(int i = 0; i < 100; i++){
            vector<string> tmpVect;
            string tmpString;
            for (int j = 0; j < 5; j++){
                copies  >> tmpString;
                tmpVect.push_back(tmpString);
            }
            copyData.push_back(tmpVect);
        }
    }
    cout<<"Please Enter the Name of the Book You Want to Delete!"<<endl;        //Prompting Book Name
    cin.ignore();
    getline (cin,bookName);
    bookName.erase(remove(bookName.begin(),bookName.end(),' '),bookName.end()); //Ignoring whitespaces
    transform(bookName.begin(), bookName.end(), bookName.begin(), ::toupper);   //Converting to Upper to format
    cout<<"Please Enter the Copy Number of this Book"<<endl;
    cin>>copyNumber;
    for(int i=0; i<100; i++) {          //Comparing copyData to User Inputs
        if(bookName==copyData[i][1] && copyNumber==copyData[i][0]){
            cout<<"Copy Deleted"<<endl;
            bookExist=true;
            for(int j=0; j<5; j++) {
                copyData[i][j].erase(); //Deletes book of user data nad copyData match
            }
        }
    }
    int deleteOption;
    if(bookExist==false){       //Book Doesn't exist
        cout<<"Book Doesn't Exist in Our Library!"<<endl<<endl;
        cout<<"Would You Like to Delete Another Book?"<<endl;      //Allows User to Continue Deleting
        cout<<"Yes......1"<<endl;
        cout<<"No.......2"<<endl;
        cin>>deleteOption;
        if(deleteOption==1) {
            deleteBooks();
        }
        if(deleteOption==2){
            cout<<"Going Back To Main Menu!"<<endl;
        }
    }
    copiesUpdated.open("Copy.txt");
    if(bookExist==true){            //Sends Deleted Data Back to Copy.txt
        for(int i=0; i<100; i++){
            copiesUpdated<<copyData[i][0]<<" "<<copyData[i][1]<<" "<<copyData[i][2]<<" "<<copyData[i][3]<<" "<<copyData[i][4]<<endl;
        }
        cout<<endl;
    }
    copies.close();
    cout<<endl;
    cout<<"Successful. Going Back To Main Menu!"<<endl;
    int r;          //Goes Back to Main
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
    
}

void Librarian::addUsers(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                     Add A New User                      -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string user, pass, type, borrow1, penality1;
    string newUsername, newPassword, newUserType;   //User specified account data
    bool continues=true;    //while loop continues until password/username are not unique
    bool trigger=true;      //if username and passwords are unique, jump to else
    int penality=0;         //Users start with 0 penalities
    int borrow=0;           //Users start wth 0 borrows
    int userTypeInt(0);
    ifstream userDatain;                    //Input Reader.txt Setup
    userDatain.open("Reader.txt");
    if(!userDatain){
        cout<<"error opening file"<< endl;
        exit(1);
    }
    userDatain.close();
    ofstream userData;                      //Output Reader.txt Setup
    userData.open("Reader.txt", ios::app);
    
    while(continues){
        cout<<"Enter a username"<<endl;     //Prompting new username
        cin>>newUsername;
        cout<<"Enter a password"<<endl;     //Prompting new password
        cin>>newPassword;
        cout<<"What type of user are you?\n"
        <<"Student.....1\n"
        <<"Teacher.....2\n"
        <<"Librarian...3\n"<<endl;
        cin>>userTypeInt;
        switch(userTypeInt){                //Set user type string from integer input
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
        while(!userDatain.eof()){           //Checking if newUsername and newPassword are Unique in Reader.txt
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
        if(trigger){
            break;
        }
    }
    cout<<"\nProfile Successfully Created! \n\nYour Username is: "<<newUsername
    <<"\nYour Password is: "<<newPassword
    <<"\nYour User Type is: "<<newUserType
    <<endl<<endl;
    userData<<newUsername<<"\t"<<newPassword<<"\t"<<newUserType<<"\t"<<penality<<"\t"<<borrow<<endl;    //Sending Account data to Reader.txt
    userData.close();
}

void Librarian::searchUsers(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                        Search Users                     -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    vector<vector<string>> reader;  //
    string username, status;        //User saerch data (ex. "Brendan" for username)
    string usernameD, passwordD, statusD; int borrowD, penalitiesD;     //Reader.txt Data
    bool noUser=false;              //If suggested Username can be found
    
    ifstream Reader;                //Input Reader.txt file setup
    Reader.open("Reader.txt");
    if(Reader.fail()){
        cerr<<"Can't access file at this time"<<endl;
        exit(1);
    }
    int searchOption, continueSearch;
    cout<<"How Would you like to Search for User"<<endl;
    cout<<"Username........1"<<endl;
    cout<<"Status....2"<<endl;
    cout<<endl;
    cin>>searchOption;
    switch (searchOption) {     //Switch Statement for "How user wants to Search"
        case 1:     //Username Search
            cout<<"Please Enter Username(Case Sensitive): "<<endl;
            cin>>username;
            while(!Reader.eof()){    //Scans Reader.txt for the user-specified username
                Reader>>usernameD>>passwordD>>statusD>>borrowD>>penalitiesD;
                if(username==usernameD){
                    cout<<"User Has Been Found"<<endl<<endl;    //Prints User Data
                    cout<<"Username: "<<usernameD<<endl;
                    cout<<"Status: "<<statusD<<endl;
                    cout<<"Borrowed Books: "<<borrowD<<endl;
                    cout<<"Penalities: "<<penalitiesD<<endl;
                    noUser=true;      //User has been Found
                    break;
                }
            }
            if(noUser==false){      //If User can't be found, offer 1. continue search 2. go to Main menu
                cout<<"User Not Found"<<endl<<endl;
                cout<<"Would You Like to Continue Search"<<endl;
                cout<<"Yes......1"<<endl;
                cout<<"No.......2"<<endl;
                cin>>continueSearch;
                if(continueSearch==1)
                    searchUsers();
                if(continueSearch==2) {
                    cout<<"Going Back To Main Menu!"<<endl;
                    break;
                }
            }
            break;
        case 2:   //Status-based search
            Reader.close();
            Reader.open("Reader.txt");
            cout<<"Please Enter Status (Case Sensitive etc. Librarian)"<<endl;
            cin>>status;
            cout<<endl;
            while(!Reader.eof()){       //Searches Reader.txt for specified status
                Reader>>usernameD>>passwordD>>statusD>>borrowD>>penalitiesD;
                if(status==statusD){
                    cout<<"User Has Been Found"<<endl<<endl;
                    cout<<"Username: "<<usernameD<<endl;
                    cout<<"Status: "<<statusD<<endl;
                    cout<<"Borrowed Books: "<<borrowD<<endl;
                    cout<<"Penalities: "<<penalitiesD<<endl;
                    noUser=true;
                    break;
                }
            }
            if(noUser==false){
                cout<<"User Not Found"<<endl<<endl;
                cout<<"Would You Like to Continue Search"<<endl;
                cout<<"Yes......1"<<endl;
                cout<<"No.......2"<<endl;
                cin>>continueSearch;
                if(continueSearch==1)
                    searchUsers();
                if(continueSearch==2) {
                    cout<<"Going Back To Main Menu!"<<endl;
                    break;
                }
            }
            break;
        default:
            cout<<"Thats Not An Option!"<<endl;
        
    }
    cout<<endl;
    string r;   //Goes to Main Menu
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
}


void Librarian::removeUser() {
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                        Remove a User                    -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string username;        //User specified username
    bool userExist=false;   //If username exists in Reader.txt truth condition
    vector<vector<string>> readerData;  //Holds data in Reader.txt
    ofstream ReaderOut;     //Output Reader.txt file setup
    ifstream Reader;        //Input Reader.txt file setup
    Reader.open("Reader.txt");
    if(Reader.fail()) {
        cerr<<"Library Can't be accessed at this moment"<<endl;
        exit(1);
    }
    while (!Reader.eof()) {     //Inputs data from Reader.txt to readerData[][]
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
    cout<<"Please Enter the Username You Want to Delete! (Case Sensitive)"<<endl;
    cin>>username;      //User Specified username to delete
    for(int i=0; i<100; i++) {
        if(username==readerData[i][0]){
            cout<<"User Deleted"<<endl;
            userExist=true;
            for(int j=0; j<5; j++) {
                readerData[i][j].erase();   //Erases data in readerData if username is in readerData(thus in Reader.txt)
            }
        }
    }
    int deleteOption;
    if(userExist==false){   //If Username is not found in readerData
        cout<<"User Doesnt Exist!"<<endl<<endl;
        cout<<"Would You Like to Delete Another User?"<<endl;
        cout<<"Yes......1"<<endl;
        cout<<"No.......2"<<endl;
        cin>>deleteOption;
        if(deleteOption==1) {
            removeUser();
        }
        if(deleteOption==2){
            cout<<"Going Back To Main Menu!"<<endl;
        }
    }
    ReaderOut.open("Reader.txt");    //Send new informatio after erasing the specified user's data
    if(userExist==true){
        for(int i=0; i<100; i++){
            ReaderOut<<readerData[i][0]<<"\t"<<readerData[i][1]<<"\t"<<readerData[i][2]<<"\t"<<readerData[i][3]<<"\t"<<readerData[i][4]<<endl;
        }
        cout<<endl;
    }
    Reader.close();
    cout<<endl;
    string r;   //prompting to main menu
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
    
}

void Librarian::myInformation(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                        My Information                   -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string value, user,pass,type, fluff;        //All Data Taken From Reader.txt
    string holdUser, holdPass;
    ifstream Current;       //Input Reader.txt File setup
    Current.open("Reader.txt");
    while(!Current.eof()){
        Current>>value>>user>>pass>>type>>fluff;    //Data taken from Reader.txt
        if(value=="1"){
            holdUser=user;  //holds the current username of the LOGGED IN person
            holdPass=pass;  //holds the current password of the LOGGED IN person
        }
    }
    cout<<"Your Username is: "<<holdUser<<endl; //Outputs LOGGED IN username
    cout<<"Your Password is: "<<holdPass<<endl; //Outputs LOGGED IN password
    cout<<"Your Status is Librarian"<<endl;
    Current.close();
    string r;               //Prompting to main menu
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
}

void Librarian::changePassword(){
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"-                      Change Password                    -"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    string password1, password2;       //User specified new passwords
    
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
        cout<<"Enter Your New Password (Case Sensitive)"<<endl;
        cin>>password1;
        cout<<"Enter Your New Password Again(Case Sensitive)"<<endl;
        cin>>password2;
        if(password1!=password2){
            cout<<"Those Passwords Dont Match. Try Again."<<endl;}
        else    //if passwords match, breaks out of loo[
            break;
    }
    int rowHold1;      //Holds location of the row that the LOGGED IN user's password is found
    string passHold;   //Holds the password for the LOGGED IN user
    for(int i=0; i<100; i++){
        if(readerData[i][0]=="1"){
            rowHold1=1;
            passHold=readerData[i][2];
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
    readerData[rowHold][1]=password1;       //Sets new password to both the LOGGED IN data
    readerData[rowHold1][2]=password1;      //Sets new password to User's information
    ofstream ReaderOut;
    ReaderOut.open("Reader.txt");           //Ouput Reader.txt file setup
    for(int i=0; i<100; i++){               //Sends updated readerData[][] information to Reader.txt
        ReaderOut<<readerData[i][0]<<"\t"<<readerData[i][1]<<"\t"<<readerData[i][2]<<"\t"<<readerData[i][3]<<"\t"<<readerData[i][4]<<endl;
    }
    string r;       //prompting to main menu
    cout<<"Press Any Key To Return To Main Menu!"<<endl;
    cin>>r;
}

        
            


    
    
    
    
    
    
    
    
    


