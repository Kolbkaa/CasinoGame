#include <iostream>
#include "Model/Game.h"
#include "Utils/List.h"
#include "Model/User.h"

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
    User *user = new User("user");
    cout<< user->GetNick();
    return 0;
}
