#include <iostream>
#include "Model/Game.h"
#include "Services/GameList.h"

int main() {


    GameList *gameList = new GameList();
    int a = gameList->AddGame(new Game("tytul1", "opis"));
    int b = gameList->AddGame(new Game("tytul2", "opis"));
    int c = gameList->AddGame(new Game("tytul3", "opis"));

    Game* game1 = gameList->GetGameById(0);
    Game* game2 = gameList->GetGameById(1);
    Game* game3 = gameList->GetGameById(2);
    cout<< game1->GetTitle()<<endl;
    cout<< game2->GetTitle()<<endl;
    cout<< game3->GetTitle()<<endl;

    gameList->Clear();
    return 0;
}
