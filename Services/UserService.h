//
// Created by dawid on 16.04.2022.
//

#ifndef CASINOGAME_USERSERVICE_H
#define CASINOGAME_USERSERVICE_H


#include "../Model/User.h"
#include "../Utils/List.h"
#include "../Persistent/UserRepository.h"

class UserService {
private:
    UserRepository *_repository;
    List<User> *_users;
public:
    UserService(UserRepository *userRepository) {
        _repository = userRepository;
        _users = _repository->ReadUsers();
    }

    ~UserService() {

        if (_users != NULL) {
            delete _users;
            _users = NULL;
        }

    }

    List<User> *GetUsers() {
        return _users;
    }

    bool AddUsers(string nick) {
        bool *isExist = new bool;
        *isExist = false;
        _users->Iterate([&isExist, nick](User *user) {
            *isExist = user->GetNick() == nick;
            if (isExist) {
                return;
            }
        });

        if (!*isExist) {
            _users->AddItem(new User(nick));
            _repository->SaveUsers(_users);
        }
        return isExist;
    }

    User *GetUserById(int id) {
        return _users->GetItemById(id);
    }

    void SaveUsers() {
        _repository->SaveUsers(_users);
    }
};


#endif //CASINOGAME_USERSERVICE_H
