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
        cout << endl;
        return *index;
    }

    static int PrintUserMenu() {
        int index = 0;
        cout << ++index << ". Wybierz gracza." << endl;
        cout << ++index << ". Dodaj gracza." << endl;
        cout << ++index << ". TOP 100" << endl;
        cout << ++index << ". Wyjscie." << endl;
        cout << endl;
        return index;
    }

    static int PrintMainMenu() {
        int index = 0;
        cout << ++index << ". Gracze." << endl;
        cout << ++index << ". Gry." << endl;
        cout << ++index << ". Wyjscie." << endl;
        cout << endl;
        return index;
    }

    static bool GetUserMenuChoose(int &input, int max) {
        cin.clear();
        if (max == 0) {
            input = 0;
            return true;
        }
        cout << "Twoj wybor?" << endl;
        cin >> input;

        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "Wprowadz wartosc liczbowa" << endl;
            input = 0;
            return false;
        }

        if (input <= max && input > 0) {
            cout << endl;
            return true;
        }
        cout << "Bledny wybor." << endl;
        cout << endl;
        return false;
    }

    static bool GetUserIntInput(int &input) {
        cin.clear();

        cin >> input;

        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "Wprowadz wartosc liczbowa" << endl;
            input = 0;
            return false;
        }

        return true;
    }
};


#endif //CASINOGAME_UI_H
