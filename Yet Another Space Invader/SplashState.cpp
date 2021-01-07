/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: SplashState contains the function for writing text to screen
*/

#include "SplashState.h"
#include "MenuState.h"

SplashState::SplashState(StateManager * gameStates)
{
   this->gameStates = gameStates;
}

void SplashState::Init()
{
   // Load background texture
   gameStates->assets.loadTexture("Splash Background", MENU_STATE_BACKGROUND_FILEPATH);
   mBackground.setTexture(gameStates->assets.getTexture("Splash Background"));

   // Load font
   gameStates->assets.loadFont("Splash Font", MENU_FONT);
   mFont = gameStates->assets.getFont("Splash Font");

   // Splash Title
   SplashText1.setFont(mFont);
   SplashText1.setString("Yet");
   SplashText1.setCharacterSize(SCREEN_HEIGHT / 18);
   SplashText1.setFillColor(sf::Color::Red);
   SplashText1.setPosition(SCREEN_WIDTH / 5, 200);
   SplashText1.setOutlineColor(sf::Color::Blue);
   SplashText1.setOutlineThickness(7);

   SplashText2.setFont(mFont);
   SplashText2.setString("More");
   SplashText2.setCharacterSize(SCREEN_HEIGHT / 18);
   SplashText2.setFillColor(sf::Color::Red);
   SplashText2.setPosition(SCREEN_WIDTH / 5, 300);
   SplashText2.setOutlineColor(sf::Color::Blue);
   SplashText2.setOutlineThickness(7);

   SplashText3.setFont(mFont);
   SplashText3.setString("Space");
   SplashText3.setCharacterSize(SCREEN_HEIGHT / 18);
   SplashText3.setFillColor(sf::Color::Red);
   SplashText3.setPosition(SCREEN_WIDTH / 5, 400);
   SplashText3.setOutlineColor(sf::Color::Blue);
   SplashText3.setOutlineThickness(7);

   SplashText4.setFont(mFont);
   SplashText4.setString("Invaders!!");
   SplashText4.setCharacterSize(SCREEN_HEIGHT / 18);
   SplashText4.setFillColor(sf::Color::Red);
   SplashText4.setPosition(SCREEN_WIDTH / 5, 500);
   SplashText4.setOutlineColor(sf::Color::Blue);
   SplashText4.setOutlineThickness(7);

}

void SplashState::Update()
{
   Draw();
   HandleInput();
}

void SplashState::HandleInput()
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
            // Go to main menu
            gameStates->AddState(new MenuState(gameStates));
            gameStates->window.close();
         }
      }
   }
}

void SplashState::Draw()
{   
   // Update Window
   gameStates->window.clear(sf::Color::Black);

   gameStates->window.draw(mBackground);
   gameStates->window.draw(SplashText1);
   gameStates->window.draw(SplashText2);
   gameStates->window.draw(SplashText3);
   gameStates->window.draw(SplashText4);

   gameStates->window.display();
}
