/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: SplashState contains the prototypes for writing text to screen
*/
#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H

#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"

class SplashState : public State
{
public:
   SplashState(StateManager * gameStates);
   ~SplashState() {}

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:

   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;
   
   sf::Text SplashText1, SplashText2, SplashText3, SplashText4;

};

#endif