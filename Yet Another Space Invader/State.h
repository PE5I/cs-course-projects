/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: State contains the prototype for creating, deleting, and handling different states
*				the States are defined as different screen types
*/
#ifndef STATE_H
#define STATE_H

#include "standard_dependency.h"

class State
{
public:
   
   virtual void Init() = 0;
   virtual void Draw() = 0;
   virtual void Update() = 0;
   virtual void HandleInput() = 0;
   //void Pause();
   //void Resume();
   
};

#endif