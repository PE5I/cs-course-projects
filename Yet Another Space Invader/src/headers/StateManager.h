/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: StateManager contains the prototypes for handling different states as the program executes
*/
#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <stack>
#include "State.h"
#include "Definintions.h"
#include "AssetManager.h"

class StateManager
{
public:
   StateManager();
   ~StateManager() {}

   void AddState(State * newState, bool isReplacing = true);
   void RemoveState();
   State * GetActiveState();

   sf::RenderWindow window;
   AssetManager assets;
   int highScore;

private:
   std::stack<State*> allStates;
   
   

   bool isAdding;
   bool isReplacing;
   bool isRemoving;
};
#endif