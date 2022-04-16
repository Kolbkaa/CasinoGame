//
// Created by dawid on 16.04.2022.
//

#ifndef CASINOGAME_USERREPOSITORY_H
#define CASINOGAME_USERREPOSITORY_H


#include "../Model/User.h"
#include "../Utils/List.h"
#include <iostream>
#include <fstream>
#include <cstring>

class UserRepository {
public:
    List<User>* ReadUsers(){
        List<User> *users = new List<User>();
        string line;
        ifstream userFile ("userFile.txt");
        if (userFile.is_open())
        {
            while ( getline (userFile,line) )
            {
                string nick = line.substr(0, line.find('|'));
                int money = stoi(line.substr(line.find('|')+1));
                users->AddItem(new User(nick,money));
            }
            userFile.close();
        }
        return users;
    }
    void SaveUsers(List<User> *users){
        ofstream userFile ("userFile.txt");
        if (userFile.is_open())
        {
            users->Iterate([&userFile](User *user) {
                userFile << user->GetNick()<<"|"<<user->GetMoney()<<endl;
            });

            userFile.close();
        }
    }
};


#endif //CASINOGAME_USERREPOSITORY_H
