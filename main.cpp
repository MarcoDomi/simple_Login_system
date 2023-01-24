#include <iostream>
#include <string>
#include <fstream>

void signUp(){

    std::string username;
    std::string password;

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    std::cout << "Enter your password: ";
    std::cin >> password;

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

    std::cout << "Enter username: ";
    getline(std::cin, username);

    std::cout << "Enter password: ";
    std::cin >> password;
    
    username.append(".txt");

    std::ifstream userFile;

    userFile.open(username);

    bool username_check = false;
    bool password_check = false;

    if(userFile.is_open()){
        username_check = true;

        std::string pw_inFile;

        userFile >> pw_inFile;

        if(password == pw_inFile)
            password_check = true;
    }

    if (username_check && password_check){
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