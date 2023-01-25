#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

void signUp(){

    std::string username;
    

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    char password[10]; //password has max length of 10
    std::cout << "Enter your password(MAX 10 characters): ";
    char ch;
    int index = 0;
    
    //TODO: IMPLEMENT PASSWORD INPUT

    std::string passwordTemp;
    std::cout << "Re-enter your password: ";
    std::cin >> passwordTemp;

    if(password == passwordTemp){
        std::ofstream userfile;
        username.append(".txt");
        userfile.open(username);

        userfile << password;
        std::cout << "\nProfile Created" << std::endl;
    }
    else{
        std::cout << "\nERROR: Re-entered password does not match" << std::endl;
    }

}


void login(){
    std::string username;
    std::string password;

    std::cout << "Enter username: "; //get username from user
    getline(std::cin, username);

    std::cout << "Enter password: "; //get password from user
    std::cin >> password;
    
    std::string fileName = username.append(".txt"); //append .txt extension to end of the username string to get users stored file

    std::ifstream userFile; //ifstream object used to read from a file

    userFile.open(fileName); //link file object with a 

    bool username_check = false;
    bool password_check = false;

    if(userFile.is_open()){//uses the entered username to check if the file actually exists
        username_check = true; //set username check to true if a user file is found

        std::string pw_inFile; //used to store the password found in user file

        userFile >> pw_inFile; //stores password found in user file

        if(password == pw_inFile) //check if entered password is equal to password in file
            password_check = true; // if matches then set paassword check to true;
    }

    if (username_check && password_check){ //if both username and password checks are true then print success
        std::cout << "\nLogin Successful!" << std::endl;
    }
    else{
        std::cout << "\nERROR: Incorrect Username or Password" << std::endl;
    }
}

//TODO: IMPLEMENT INPUT VALIDATION
void loginSystem(){

    bool continueLoop = true;
    while (continueLoop){

        std::cout << std::endl
                  << "  Login Page\n"
                  << "--------------\n"
                  << "1. Login\n"
                  << "2. Sign up\n"
                  << "3. Exit" 
                  << std::endl;
        std::cout << std::endl;

        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice){

        case 1:
            /* code */
            login();
            break;
        
        case 2:
            signUp();
            break;
        
        case 3:
            continueLoop = false;
            break;

        default:
            std::cout << "\nInvalid choice" << std::endl;
        }
    }
}

int main(){

    loginSystem();
}