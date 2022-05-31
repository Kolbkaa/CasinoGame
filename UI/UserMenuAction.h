//
// Created by dawid on 31.05.2022.
//

#ifndef CASINOGAME_USERMENUACTION_H
#define CASINOGAME_USERMENUACTION_H


#include "../Model/User.h"
#include "UI.h"
#include "../Services/UserService.h"
#include "../Model/GameState.h"

class UserMenuAction {
    UserService *userService = new UserService();
    List<User> *users = userService->GetUsers();
public:
    void Run(GameState *gameState) {
        int maxChoose = 0;
        int choose = 0;
        do {
            do {
                maxChoose = UI::PrintUserMenu();
            } while (!UI::GetUserInput(choose, maxChoose));
            switch (choose) {
                case 1: {
                    gameState->SetUser(ChooseUser());
                    break;
                }
                case 2: {
                    AddUser();
                    break;
                }
                case 3: {
                    GetTop10();
                    break;
                }
            }
        } while (choose != maxChoose);
        users->Clear();
    }

private:
    User *ChooseUser() {
        int userMaxChoose = UI::PrintUsers(users);
        int userChoose = 0;
        if (userMaxChoose == 0) {
            cout << "Brak graczy do wybrania" << endl;
        } else if (UI::GetUserInput(userChoose, userMaxChoose)) {
            return userService->GetUserById(userChoose - 1);
        }
        cout << endl;
        return NULL;
    }

    void AddUser() {
        string nick;
        cout << "Podaj nick: " << endl;
        cin >> nick;
        if (userService->AddUsers(nick)) {
            cout << "Dodano gracza - " << nick << endl;
        } else {
            cout << "Istnieje juz gracz o nicku - " << nick << endl;
        };
        cout << endl;
    }

    void GetTop10() {
        cout << "Lista TOP 10 graczy:" << endl;
        User **userArray = users->ToArray();
        if (users->Length() > 1) {
            for (int i = 1; i < users->Length(); i++) {
                User *temp = userArray[i];
                bool isChanged = true;
                int index = i;
                while (isChanged && index - 1 >= 0) {
                    if (userArray[index - 1]->GetMoney() < temp->GetMoney()) {
                        userArray[index] = userArray[index - 1];
                        index--;
                    } else {
                        isChanged = false;
                    }

                }
                userArray[index] = temp;

            }
        }
        for (int i = 0; i < users->Length(); i++) {
            cout << i + 1 << ". " << userArray[i]->GetNick() << "\t\tPieniadze: " << userArray[i]->GetMoney() << endl;
        }
        cout << endl;
    }
};


#endif //CASINOGAME_USERMENUACTION_H
