/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: this file contains the functions for printing the instructions to the screen
*/
#include "InstructionsState.h"


InstructionsState::InstructionsState(StateManager * gameStateManager)
{
   this->gameStates = gameStateManager;
}

void InstructionsState::Init()
{
   // Load background texture
   gameStates->assets.loadTexture("Instructions Background", MENU_STATE_BACKGROUND_FILEPATH);
   mBackground.setTexture(gameStates->assets.getTexture("Instructions Background"));

   // Load font
   gameStates->assets.loadFont("Instructions Font", MENU_FONT);
   mFont = gameStates->assets.getFont("Instructions Font");

   // Splash Title
   Instruction1.setFont(mFont);
   Instruction1.setString("---- keybindings ----");
   Instruction1.setCharacterSize(SCREEN_HEIGHT / 24);
   Instruction1.setFillColor(sf::Color::Red);
   Instruction1.setPosition(SCREEN_WIDTH / 5, 100);
   Instruction1.setOutlineColor(sf::Color::Blue);
   Instruction1.setOutlineThickness(7);

   Instruction2.setFont(mFont);
   Instruction2.setString("MOVE LEFT:  Left Arrow");
   Instruction2.setCharacterSize(SCREEN_HEIGHT / 24);
   Instruction2.setFillColor(sf::Color::Red);
   Instruction2.setPosition(SCREEN_WIDTH / 5, 200);
   Instruction2.setOutlineColor(sf::Color::Blue);
   Instruction2.setOutlineThickness(7);

   Instruction3.setFont(mFont);
   Instruction3.setString("MOVE RIGHT:  Right Arrow");
   Instruction3.setCharacterSize(SCREEN_HEIGHT / 24);
   Instruction3.setFillColor(sf::Color::Red);
   Instruction3.setPosition(SCREEN_WIDTH / 5, 300);
   Instruction3.setOutlineColor(sf::Color::Blue);
   Instruction3.setOutlineThickness(7);

   Instruction4.setFont(mFont);
   Instruction4.setString("FIRE:               SPACEBAR");
   Instruction4.setCharacterSize(SCREEN_HEIGHT / 24);
   Instruction4.setFillColor(sf::Color::Red);
   Instruction4.setPosition(SCREEN_WIDTH / 5, 400);
   Instruction4.setOutlineColor(sf::Color::Blue);
   Instruction4.setOutlineThickness(7);

   Instruction5.setFont(mFont);
   Instruction5.setString("GOD_MODE:  Play Better");
   Instruction5.setCharacterSize(SCREEN_HEIGHT / 24);
   Instruction5.setFillColor(sf::Color::Red);
   Instruction5.setPosition(SCREEN_WIDTH / 5, 500);
   Instruction5.setOutlineColor(sf::Color::Blue);
   Instruction5.setOutlineThickness(7);
}

void InstructionsState::Update()
{
   Draw();
   HandleInput();
}

void InstructionsState::HandleInput()
{
   while (gameStates->window.isOpen())
   {
      sf::Event event;
      while (gameStates->window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            gameStates->window.close();

         if (event.type == sf::Event::KeyPressed)
         {
            gameStates->RemoveState();
         }
      }
   }
}

void InstructionsState::Draw()
{
   // Update Window
   gameStates->window.clear(sf::Color::Black);

   gameStates->window.draw(mBackground);
   gameStates->window.draw(Instruction1);
   gameStates->window.draw(Instruction2);
   gameStates->window.draw(Instruction3);
   gameStates->window.draw(Instruction4);
   gameStates->window.draw(Instruction5);

   gameStates->window.display();
}
