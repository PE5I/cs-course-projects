/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: CreditsState contains the functions for printing the credit to the screen
*/
#include "CreditsState.h"

CreditsState::CreditsState(StateManager * gameStateManager)
{
   this->gameStates = gameStateManager;
   this->message = "People's Names Go Here...";
}

void CreditsState::Init()
{

   // Load background texture
   gameStates->assets.loadTexture("Credits Background", MENU_STATE_BACKGROUND_FILEPATH);
   mBackground.setTexture(gameStates->assets.getTexture("Credits Background"));

   // Load font
   gameStates->assets.loadFont("Credits Font", MENU_FONT);
   mFont = gameStates->assets.getFont("Credits Font");

   // Pesi
   name1.setFont(mFont);
   name1.setString("Pesi Taototo");
   name1.setCharacterSize(SCREEN_HEIGHT / 24);
   name1.setFillColor(sf::Color::Red);
   name1.setPosition(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 6);
   name1.setOutlineColor(sf::Color::Blue);
   name1.setOutlineThickness(7);

   // Kostya
   name2.setFont(mFont);
   name2.setString("Konstantin Shvedov");
   name2.setCharacterSize(SCREEN_HEIGHT / 24);
   name2.setFillColor(sf::Color::Red);
   name2.setPosition(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 3);
   name2.setOutlineColor(sf::Color::Blue);
   name2.setOutlineThickness(7);

   // Jacob
   name3.setFont(mFont);
   name3.setString("Jacob Jones");
   name3.setCharacterSize(SCREEN_HEIGHT / 24);
   name3.setFillColor(sf::Color::Red);
   name3.setPosition(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 2);
   name3.setOutlineColor(sf::Color::Blue);
   name3.setOutlineThickness(7);

   // Derek
   name4.setFont(mFont);
   name4.setString("Derek Nevins");
   name4.setCharacterSize(SCREEN_HEIGHT / 24);
   name4.setFillColor(sf::Color::Red);
   name4.setPosition(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 1.5);
   name4.setOutlineColor(sf::Color::Blue);
   name4.setOutlineThickness(7);

}

void CreditsState::Update()
{
   Draw();
   HandleInput();
}

void CreditsState::HandleInput()
{
   //system("pause");
   cout << "need to go back to menu" << endl;
   //

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

void CreditsState::Draw()
{
   cout << message << endl;

   // Update Window
   gameStates->window.clear(sf::Color::Black);
   gameStates->window.draw(mBackground); // Update Background
   gameStates->window.draw(name1); // Update name1
   gameStates->window.draw(name2); // Update name2
   gameStates->window.draw(name3); // Update name3
   gameStates->window.draw(name4); // Update name4

   gameStates->window.display();
}
