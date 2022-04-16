#include <iostream>
#include "Model/Game.h"
#include "Utils/List.h"
#include "Model/User.h"
#include "Persistent/UserRepository.h"
#include "UI/UI.h"
#include "Services/UserService.h"

int main() {
    User *user = 0;

    UserService *userService = new UserService();
    List<User> *users = userService->GetUsers();

    int choose = 0;
    int maxChoose = 0;
    bool isRunning = true;

    while (isRunning == true) {
        do {
            maxChoose = UI::PrintMainMenu();
        } while (!UI::GetUserInput(choose, maxChoose));
        switch (choose) {
            case 1:
                do {
                    do {
                        maxChoose = UI::PrintUserMenu();
                    } while (!UI::GetUserInput(choose, maxChoose));
                    switch (choose) {
                        case 1: {
                            int userMaxChoose = UI::PrintUsers(users);
                            int userChoose = 0;
                            if (userMaxChoose == 0){
                                cout<<"Brak graczy do wybrania"<<endl;
                            }
                            else if(UI::GetUserInput(userChoose, userMaxChoose)) {
                                user = userService->GetUserById(userChoose - 1);
                            }
                            break;
                        }
                        case 2: {
                            string nick;
                            cout << "Podaj nick: "<<endl;
                            cin >> nick;
                            if(userService->AddUsers(nick)){
                                cout<<"Dodano gracza - "<<nick<<endl;
                            }else{
                                cout<<"Istnieje juz gracz o nicku - "<<nick<<endl;
                            };
                            break;
                        }
                    }
                } while (choose != maxChoose);
                break;
            case 2:
                if (user == NULL) {
                    cout << "Nie wybrano gracza" << endl;
                }
                break;
            case 3:
                isRunning = false;
                break;
        }
        choose = 0;
    }

    return 0;
}
