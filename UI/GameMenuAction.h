//
// Created by dawid on 01.06.2022.
//

#ifndef CASINOGAME_GAMEMENUACTION_H
#define CASINOGAME_GAMEMENUACTION_H

#include <iostream>
#include "../Services/GameService.h"
#include "UI.h"

class GameMenuAction {
private:
    GameService *_gameService;
public:
    GameMenuAction(GameService *gameService) {
        _gameService = gameService;
    }

    void Run(GameState *_gameState) {
        int maxChoose = 0;
        int choose = 0;

        if (_gameState->GetUser() == NULL) {
            cout << "Nie wybrano gracza" << endl;
            return;
        }
        cout << "Wybierz gre: " << endl;
        do {
            maxChoose = PrintGames();
        } while (!UI::GetUserInput(choose, maxChoose));

        Game *game = _gameService->GetGameById(choose - 1);
        game->Run(_gameState->GetUser());

    }

private:
    int PrintGames() {
        int *index = new int;
        *index = 0;
        _gameService->GetGames()->Iterate([&index](Game *game) {
            cout << ++(*index) << ". " << game->GetTitle() << endl;
        });
        cout << endl;
        return *index;
    }
};


#endif //CASINOGAME_GAMEMENUACTION_H
