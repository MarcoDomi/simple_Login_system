#include <iostream>
#include <string>
#include <fstream>


void login(){
    

   
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