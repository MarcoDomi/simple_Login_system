#include <iostream>
#include <string>
#include <fstream>


void login(){
    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    getline(std::cin, username);

    std::cout << "Enter password: ";
    std::cin >> password;

    std::cout << std::endl;
    
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

    bool login_status = username_check && password_check;

    if(login_status){
        std::cout << "Login Successful!" << std::endl;
    }
    else{
        std::cout << "Incorrect Username or Password" << std::endl;
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