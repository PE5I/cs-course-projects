/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: PlayState contains the functions for initializing the game screen
*/
#include "PlayState.h"

PlayState::PlayState(StateManager * gameStateManager)
{
   this->gameStates = gameStateManager;
}

void PlayState::Init()
{
   // Load background texture
   gameStates->assets.loadTexture("Menu Background", MENU_STATE_BACKGROUND_FILEPATH);
   mBackground.setTexture(gameStates->assets.getTexture("Menu Background"));

   loadTexture();

   // Load font
   gameStates->assets.loadFont("Menu Font", MENU_FONT);
   mFont = gameStates->assets.getFont("Menu Font");

   time_accumulator = time(0);
   last_time = 0;
   score = 0;


   scoreText.setFont(mFont);
   scoreText.setString(std::to_string(score));
   scoreText.setCharacterSize(SCREEN_HEIGHT / 16);
   scoreText.setFillColor(sf::Color::Red);
   scoreText.setPosition(SCREEN_WIDTH *0.9, SCREEN_HEIGHT *0.05);
   scoreText.setOutlineColor(sf::Color::Blue);
   scoreText.setOutlineThickness(7);

   scoreLabel.setFont(mFont);
   scoreLabel.setString("Score: ");
   scoreLabel.setCharacterSize(SCREEN_HEIGHT / 16);
   scoreLabel.setFillColor(sf::Color::Red);
   scoreLabel.setPosition(SCREEN_WIDTH *0.5, SCREEN_HEIGHT *0.05);
   scoreLabel.setOutlineColor(sf::Color::Blue);
   scoreLabel.setOutlineThickness(7);

   highScoreText.setFont(mFont);
   highScoreText.setString(std::to_string(gameStates->highScore));
   highScoreText.setCharacterSize(SCREEN_HEIGHT / 16);
   highScoreText.setFillColor(sf::Color::Red);
   highScoreText.setPosition(SCREEN_WIDTH *0.4, SCREEN_HEIGHT *0.05);
   highScoreText.setOutlineColor(sf::Color::Blue);
   highScoreText.setOutlineThickness(7);

   highScoreLabel.setFont(mFont);
   highScoreLabel.setString("High: ");
   highScoreLabel.setCharacterSize(SCREEN_HEIGHT / 16);
   highScoreLabel.setFillColor(sf::Color::Red);
   highScoreLabel.setPosition(SCREEN_WIDTH *0.1, SCREEN_HEIGHT *0.05);
   highScoreLabel.setOutlineColor(sf::Color::Blue);
   highScoreLabel.setOutlineThickness(7);

   winText.setFont(mFont);
   winText.setString("");
   winText.setCharacterSize(SCREEN_HEIGHT / 16);
   winText.setFillColor(sf::Color::Red);
   winText.setPosition(SCREEN_WIDTH *0.5, SCREEN_HEIGHT *0.5);
   winText.setOutlineColor(sf::Color::Blue);
   winText.setOutlineThickness(7);


   // Spawn Enemy Wave
   for (int i = 0; i < 6; i++)
   {
      Enemy * e1 = new Enemy();
      e1->setPosition(100 * i, 50 * i);
      enemies.push_back(e1);
   }

   bool isGameOver = false;
   bool leftisPressed = false;
   bool rightisPressed = false;
   bool fireKeyPressed = false;

}

void PlayState::Update()
{
   Draw();
   HandleInput();
}

void PlayState::HandleInput()
{
   isGameOver = false;
   while (gameStates->window.isOpen())
   {
      time_accumulator = time(0);

      sf::Event event;

      // Update Flags Based On Player Input
      while (gameStates->window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            gameStates->window.close();
         
         if (isGameOver && event.type == sf::Event::KeyPressed)
            gameStates->RemoveState();
         
         if (event.type == sf::Event::KeyPressed)
         {
            if (!leftisPressed && event.key.code == sf::Keyboard::Left)
            {
               leftisPressed = true;
               //cout << "S" << endl;
            }
            if (!rightisPressed && event.key.code == sf::Keyboard::Right)
            {
               rightisPressed = true;
               //cout << "D" << endl;
            }
            if (!fireKeyPressed && event.key.code == sf::Keyboard::Space)
            {
               fireKeyPressed = true;
               //cout << "A" << endl;
            }
         }
         if (event.type == sf::Event::KeyReleased)
         {
            if (leftisPressed && event.key.code == sf::Keyboard::Left)
            {
               leftisPressed = false;
            }
            if (rightisPressed && event.key.code == sf::Keyboard::Right)
            {
               rightisPressed = false;
            }
            if (fireKeyPressed && event.key.code == sf::Keyboard::Space)
            {
               fireKeyPressed = false;
            }
         }
      }

      // Process Player Input
      if (leftisPressed == true) {
         thePlayer.move(-0.2, 0);
      }
      if (rightisPressed == true) {
         thePlayer.move(0.2, 0);
      }
      if (fireKeyPressed == true)
      {
         if (time_accumulator - last_time >= 1)
         {
			 sf::Sprite* s = new sf::Sprite();
			 s->setPosition(thePlayer.getPosition());
			 s->setTexture(texture);
			 s->scale(sf::Vector2f(5.f,5.f));
            projectiles.push_back(s);


            fireKeyPressed = false;
            last_time = time_accumulator;
         }

         fireKeyPressed = false;
      }
	  
      // Check for projectile/enemy collision
      for (int i = 0; i < enemies.size(); i++)
      {
         enemyHitbox = (*enemies.at(i)).getGlobalBounds();

         for (int j = 0; j < projectiles.size(); j++)
         {
            if (enemyHitbox.contains((*projectiles[j]).getPosition()))
            {
               cout << "sf::Sprite hit enemy\n" << endl;
               delete projectiles.at(j);
               projectiles.erase(projectiles.begin()+j);
            
               //delete enemies.at(i);
               //enemies.erase(enemies.begin()+i);
               (*enemies.at(i)).setPosition(sf::Vector2f((*enemies.at(i)).getPosition().x, 0+score*10));

               scoreText.setString(std::to_string(++score));

               if (score > gameStates->highScore)
               {
                  gameStates->highScore = score;
                  highScoreText.setString(std::to_string(gameStates->highScore));
               }

               if (score > 100)
               {
                  winText.setString("You Win!");
                  isGameOver = true;
               }
            }
         }
      }

      moveProjectiles(projectiles);
      moveEnemies(enemies);
      Draw();

      if (event.type == sf::Event::Closed)
         gameStates->window.close();
         
   }

}

void PlayState::Draw()
{
   gameStates->window.clear(sf::Color::Black);

   gameStates->window.draw(mBackground);
   gameStates->window.draw(gameEndText);
   gameStates->window.draw(scoreText);
   gameStates->window.draw(scoreLabel);
   gameStates->window.draw(highScoreText);
   gameStates->window.draw(highScoreLabel);
   gameStates->window.draw(winText);
   gameStates->window.draw(thePlayer);

   //this loop checks if there is anything in the projectiles vector, and draws them
   if (projectiles.size() > 0) {
      for (int i = 0; i < projectiles.size(); i++) {
         gameStates->window.draw(*projectiles.at(i));
      }
   }

   if (enemies.size() > 0) {
      for (int i = 0; i < enemies.size(); i++) {
         gameStates->window.draw(*enemies.at(i));
      }
   }


   //gameStates->window.draw(enemy1);
   //gameStates->window.draw(enemy2);
   //gameStates->window.draw(enemy3);
   //gameStates->window.draw(enemy4);
   //gameStates->window.draw(enemy5);

   gameStates->window.display();

   //for (int i = 0; i < enemies)
   //enemy1.move(sf::Vector2f(0, ENEMY_SPEED));
   //enemy2.move(sf::Vector2f(0, ENEMY_SPEED));
   //enemy3.move(sf::Vector2f(0, ENEMY_SPEED));
   //enemy4.move(sf::Vector2f(0, ENEMY_SPEED));
   //enemy5.move(sf::Vector2f(0, ENEMY_SPEED));

}

void PlayState::moveProjectiles(vector<sf::Sprite*>& projectiles)
{
   for (int i = 0; i < projectiles.size(); i++) {
      projectiles.at(i)->move(0, -1);

      //this checks if the projectile moved past the screen, if so, de-allocate the object and remove from vector
      if (projectiles.at(i)->getPosition().y < ORIGIN) {
         cout << "Deleted projectile!" << endl;
         delete projectiles.at(i);
         projectiles.erase(projectiles.begin()+i);
      }
   }
}

void PlayState::moveEnemies(vector<Enemy *>& enemies)
{
   for (int i = 0; i < enemies.size(); i++) {
      enemies.at(i)->move(0, ENEMY_SPEED);

      //cout << enemies.at(i)->getPosition().y << "   " << SCREEN_HEIGHT  << endl;

      //this checks if the projectile moved past the screen, if so, de-allocate the object and remove from vector
      if (enemies.at(i)->getPosition().y > SCREEN_HEIGHT) {
         cout << "Deleted enemy!" << endl;
         delete enemies.at(i);
         enemies.erase(enemies.begin()+i);

         gameEndText.setFont(mFont);
         gameEndText.setString("Game Over");
         gameEndText.setCharacterSize(SCREEN_HEIGHT / 16);
         gameEndText.setFillColor(sf::Color::Red);
         gameEndText.setPosition(SCREEN_WIDTH / 2.4, SCREEN_HEIGHT / 6);
         gameEndText.setOutlineColor(sf::Color::Blue);
         gameEndText.setOutlineThickness(7);

         isGameOver = true;
      }
   }
}

void PlayState::loadTexture() {
	texture.loadFromFile(BULLET);
	playertexture.loadFromFile(PLAYER);
	enemytexture.loadFromFile(ENEMIES);

}