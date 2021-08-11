/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: InstructionState contains the prototypes for printing the instructions to the screen
*/
#ifndef INSTRUCTIONSSTATE_H
#define INSTRUCTIONSSTATE_H

#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"

class InstructionsState : public State
{
public:
   InstructionsState(StateManager * gameStateManager);
   ~InstructionsState() {};

   void Init();
   void Update();
   void HandleInput();
   void Draw();

private:

   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;

   sf::Text Instruction1, Instruction2, Instruction3, Instruction4, Instruction5;
};

#endif