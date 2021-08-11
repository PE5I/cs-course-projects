/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: Contains the prototypes for the Menu Screen functions
*/
#ifndef MENUSYSTEMTEST_H
#define MENUSYSTEMTEST_h

#include "standard_dependency.h"
#include "StateManager.h"
#include "MenuState.h"
#include "SplashState.h"
#include "CreditsState.h"

class MenuSystemTest
{
public:
   void RunMenu();

private:
   StateManager gameStates;
};
#endif