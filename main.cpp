#include <iostream>
#include <string>
#include <fstream>


void login(){
    //change the logic of logging in
    std::ifstream usernameFile;
    std::ifstream passwordFile;

    usernameFile.open("usernames.txt");
    passwordFile.open("passwords.txt");

    bool usernameFound = false;
    bool passwordFound = false;

    if(usernameFile && passwordFile){
        std::string username;
        std::string password;

        std::cout << "Enter Username: ";
        getline(std::cin, username);

        std::cout << "Enter Password: ";
        std::cin >> password;

        std::string usernameInFile;
        while (usernameFile >> usernameInFile){
            if(usernameInFile == username){
                usernameFound = true;
                break;
            }
        }

        std::string pwInFile;
        while(passwordFile >> pwInFile){
            if(pwInFile == password){
                passwordFound = true;
                break;
            }
        }


    }
    else{
        
        if(!usernameFile){
            std::cout << "ERROR: cannot find username file" << std::endl;
        }
        if(!passwordFile){
            std::cout << "ERROR: cannot find password file" << std::endl;
        }
    }
    usernameFile.close();
    passwordFile.close();
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
            std::cout << "TODO: CREATE SIGN UP\n";
            break;
        
        case 3:
            continueLoop = false;
            break;

        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }
}

int main(){

    loginSystem();
}