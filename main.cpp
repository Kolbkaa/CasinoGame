#include <iostream>
#include "Model/Game.h"
#include "Utils/List.h"
#include "Model/User.h"
#include "Services/UserRepository.h"

int main() {


    List<Game> *gameList = new List<Game>();
    int a = gameList->AddItem(new Game("tytul1", "opis"));
    int b = gameList->AddItem(new Game("tytul2", "opis"));
    int c = gameList->AddItem(new Game("tytul3", "opis"));

    Game* game1 = gameList->GetItemById(0);
    Game* game2 = gameList->GetItemById(1);
    Game* game3 = gameList->GetItemById(2);
    cout<< game1->GetTitle()<<endl;
    cout<< game2->GetTitle()<<endl;
    cout<< game3->GetTitle()<<endl;

    gameList->Clear();
    List<User> *users = new List<User>();
    users->AddItem(new User("user1"));
    users->AddItem(new User("user2"));
    UserRepository *userRepository = new UserRepository();
    userRepository->SaveUsers(users);

    List<User> *user = userRepository->ReadUsers();
    User* u = user->GetItemById(0);
    cout<<u->GetNick();
    return 0;
}
