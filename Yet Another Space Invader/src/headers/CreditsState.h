/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: CreditsState contains the prototypes for printing the credit to the screen
*/
#ifndef CREDITSSTATE_H
#define CREDITSSTATE_H

#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"


class CreditsState : public State
{
public:
   CreditsState(StateManager * gameStateManager);
   ~CreditsState() {}

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:
   std::string message;
   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;

   sf::Text name1, name2, name3, name4;
};
#endif