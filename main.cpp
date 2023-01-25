#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

void signUp(){

    std::string username;
    
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    std::string fileName = username.append(".txt");
    std::ifstream doesFileExist(fileName); //associates filename with ifstream object
    
    if (doesFileExist.good()){ //good() checks if none of the file streams error state flags are set
        std::cout << "\nError: username is taken" << std::endl;
        doesFileExist.close();
    }
    else{
        std::cout << "Enter your password: ";
        std::string password;

        char ch;
        do{
            ch = getch();
            switch (ch){
                case 0://ignore any special characters that may get entered
                    getch();
                    break;
                case 8: //if getchar is equal to 8 which is ascii value of BACKSPACE
                    if(password.length() > 0){
                        password.erase(password.end() - 1);
                        std::cout << ch << " " << ch; //how does this work?
                    }
                    break;
                case 13: //if getchar is equal to 13 which is ascii value of ENTER/CARRIAGE RETURN
                    std::cout << std::endl;
                    break;
                default:
                    password += ch;
                    std::cout << "*";
                    break;
            }

        } while (ch != 13);
        
        std::cout << "Re-enter your password: ";
        std::string passwordTemp;

        do{
            ch = getch();

            switch(ch){
                case 0:
                    getch();
                case 8:
                    if(passwordTemp.length() > 0){
                        passwordTemp.erase(passwordTemp.end() - 1);
                        std::cout << ch << " " << ch;
                    }
                    break;
                case 13:
                    std::cout << std::endl;
                    break;
                default:
                    passwordTemp += ch;
                    std::cout << "*";
                    break;
            }
        } while (ch != 13);

        if(password == passwordTemp){

            std::ofstream userfile;
            userfile.open(fileName);

            userfile << password;
            std::cout << "\nProfile Created" << std::endl;
            userfile.close();
        }
        else{
            std::cout << "\nERROR: Re-entered password does not match" << std::endl;
        }
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

    userFile.close();
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