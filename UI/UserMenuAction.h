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


public:
    UserMenuAction(UserService *userService) {
        _userService = userService;
        _users = _userService->GetUsers();
    }

    void Run(GameState *gameState) {
        int maxChoose = 0;
        int choose = 0;
        do {
            do {
                maxChoose = UI::PrintUserMenu();
            } while (!UI::GetUserMenuChoose(choose, maxChoose));
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
    }

private:
    UserService *_userService;
    List<User> *_users;

    User *ChooseUser() {
        int userMaxChoose = UI::PrintUsers(_users);
        int userChoose = 0;
        if (userMaxChoose == 0) {
            cout << "Brak graczy do wybrania" << endl;
        } else if (UI::GetUserMenuChoose(userChoose, userMaxChoose)) {
            return _userService->GetUserById(userChoose - 1);
        }
        cout << endl;
        return NULL;
    }

    void AddUser() {
        string nick;
        cout << "Podaj nick: " << endl;
        cin >> nick;
        if (_userService->AddUsers(nick)) {
            cout << "Dodano gracza - " << nick << endl;
        } else {
            cout << "Istnieje juz gracz o nicku - " << nick << endl;
        };
        cout << endl;
    }

    void GetTop10() {
        cout << "Lista TOP 10 graczy:" << endl;
        User **userArray = _users->ToArray();
        if (_users->Length() > 1) {
            for (int i = 1; i < _users->Length(); i++) {
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
        int maxDisplay = 0;
        if (_users->Length() < 100) {
            maxDisplay = _users->Length();
        } else {
            maxDisplay = 100;
        }
        for (int i = 0; i < maxDisplay; i++) {
            cout << i + 1 << ". " << userArray[i]->GetNick() << "\t\tPieniadze: " << userArray[i]->GetMoney() << endl;
        }
        cout << endl;
    }
};


#endif //CASINOGAME_USERMENUACTION_H
