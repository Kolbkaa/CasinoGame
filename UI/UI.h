//
// Created by dawid on 16.04.2022.
//

#ifndef CASINOGAME_UI_H
#define CASINOGAME_UI_H


#include <iostream>
#include "../Model/User.h"
#include "../Utils/List.h"

using namespace std;

class UI {
public:
    static int PrintUsers(List<User> *users) {
        int *index = new int;
        *index = 0;
        users->Iterate([&index](User *user) {
            cout << ++(*index) << ". " << user->GetNick() << " Pieniadze: " << user->GetMoney() << endl;
        });
        return *index;
    }

    static int PrintUserMenu() {
        int index = 0;
        cout << ++index << ". Wybierz gracza." << endl;
        cout << ++index << ". Dodaj gracza." << endl;
        cout << ++index << ". Wyjscie." << endl;
        return index;
    }

    static int PrintMainMenu() {
        int index = 0;
        cout << ++index << ". Gracze." << endl;
        cout << ++index << ". Gry." << endl;
        cout << ++index << ". Wyjscie." << endl;
        return index;
    }

    static bool GetUserInput(int &input, int max) {
        if (max == 0) {
            input = 0;
            return true;
        }
        cout << "Twoj wybor?" << endl;
        cin >> input;
        if (input <= max && input > 0) {
            return true;
        }
        cout << "Bledny wybor." << endl;
        return false;
    }

};


#endif //CASINOGAME_UI_H
