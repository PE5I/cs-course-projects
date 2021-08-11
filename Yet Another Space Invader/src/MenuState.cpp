/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: this file contains all the function necessary for a fully working menu
*/
#include "MenuState.h"
#include "CreditsState.h"
#include "InstructionsState.h"
#include "PlayState.h"
#include "standard_dependency.h"

MenuState::MenuState(StateManager * gameStateManager)
{
   this->menu_selection = 0;
   this->select_pos = 1; // bottom option is zero
   int select_positions[] = { 2, 3, 6 };
   this->gameStates = gameStateManager;
}

void MenuState::Init()
{
   // Load background texture
   gameStates->assets.loadTexture("Menu Background", MENU_STATE_BACKGROUND_FILEPATH);
   mBackground.setTexture(gameStates->assets.getTexture("Menu Background"));

   // Load font
   gameStates->assets.loadFont("Menu Font", MENU_FONT);
   mFont = gameStates->assets.getFont("Menu Font");
 
   // Initialize selector box
   select_box.setSize(sf::Vector2f(500, 70));
   select_box.setFillColor(sf::Color::Transparent);
   select_box.setOutlineColor(sf::Color::Red);
   select_box.setOutlineThickness(10);
   select_box.setPosition(SCREEN_HEIGHT / 7, SCREEN_HEIGHT / 3);

   // Set up option text
   option1.setFont(mFont);
   option1.setString("Play");
   option1.setCharacterSize(SCREEN_HEIGHT / 16);
   option1.setFillColor(sf::Color::Red);
   option1.setPosition(SCREEN_WIDTH / 2.4, SCREEN_HEIGHT/6);
   option1.setOutlineColor(sf::Color::Blue);
   option1.setOutlineThickness(7);

   option2.setFont(mFont);
   option2.setString("Instructions");
   option2.setCharacterSize(SCREEN_HEIGHT / 16);
   option2.setFillColor(sf::Color::Red);
   option2.setPosition(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 3);
   option2.setOutlineColor(sf::Color::Blue);
   option2.setOutlineThickness(7);

   option3.setFont(mFont);
   option3.setString("Credits");
   option3.setCharacterSize(SCREEN_HEIGHT / 16);
   option3.setFillColor(sf::Color::Red);
   option3.setPosition(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2);
   option3.setOutlineColor(sf::Color::Blue);
   option3.setOutlineThickness(7);

   Draw();

}

void MenuState::Update()
{

   do
   {
      Draw();

      HandleInput();

   } while (menu_selection == 0);
   
}

void MenuState::HandleInput()
{
   int select_positions[] = { 2, 3, 6 };

   while (gameStates->window.isOpen())
   {
      sf::Event event;
      while (gameStates->window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            gameStates->window.close();

         if (event.type == sf::Event::KeyPressed)
         {
            cout << "button pressed" << endl;

            // If Up is pushed and not at top of menu, Move selector box up one
            if (select_pos < 2 && event.key.code == sf::Keyboard::Up)
            {
               select_box.setPosition(select_box.getPosition().x, SCREEN_HEIGHT / select_positions[++select_pos]);
               Draw();
            }
            // If Down is pushed and not at Bottom of menu, Move selector box down one
            else if (select_pos > 0 && event.key.code == sf::Keyboard::Down)
            {
               select_box.setPosition(select_box.getPosition().x, SCREEN_HEIGHT / select_positions[--select_pos]);
               Draw();
            }
            else if (event.key.code == sf::Keyboard::Return)
            {
               menu_selection = select_pos+1;
               
               if (menu_selection == 3)
               {
                  // enter game
                  //menu_selection = 0;
                  gameStates->AddState(new PlayState(gameStates), false);
               }
               else if (menu_selection == 2)
               {
                  // display instructions
                  gameStates->AddState(new InstructionsState(gameStates), false);
               }
               else if (menu_selection == 1)
               {
                  // display credits
                  gameStates->AddState(new CreditsState(gameStates), false);
               }
               else
               {
                  menu_selection = 0;
               }
            }

         }
      }
   }
   
   cin >> menu_selection;
}

void MenuState::Draw()
{
   system("cls");

   cout << "In the menu" << endl;
   cout << "1. Start" << endl;
   cout << "2. Credits" << endl;


   // Update Window
   gameStates->window.clear(sf::Color::Black);

   // Update Background, option1, option2, option2, and select_box
   gameStates->window.draw(mBackground);
   gameStates->window.draw(option1);
   gameStates->window.draw(option2);
   gameStates->window.draw(option3);
   gameStates->window.draw(select_box);

   gameStates->window.display();
}

