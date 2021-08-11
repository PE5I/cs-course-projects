/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: PlayState contains the prototype for initializing the game screen
*/
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "standard_dependency.h"
#include "StateManager.h"
#include "Player.h"
#include "Enemy.h"

#define BULLET "../assets/Bullet.jpg"
#define ENEMIES "../assets/Enemies.jpg"
#define PLAYER "../assets/player.jpg"

class PlayState : public State
{
public:
   PlayState(StateManager * gameStateManager);
   ~PlayState() {}

   void Init();
   void Update();
   void HandleInput();
   void Draw();

   void loadTexture();
   Player thePlayer;
private:
   void moveProjectiles(vector<sf::Sprite*> &projectiles);
   void moveEnemies(vector<Enemy *>& enemies);

   sf::Texture texture;
   sf::Texture enemytexture;
   sf::Texture playertexture;



   StateManager * gameStates;
   sf::Sprite mBackground;
   sf::Font mFont;
   sf::Text gameEndText;
   sf::Text scoreText;
   sf::Text scoreLabel;
   sf::Text highScoreText;
   sf::Text highScoreLabel;
   sf::Text winText;
   
   int score;
   bool isGameOver;

   //Player thePlayer;
   
   //Enemy enemy1, enemy2, enemy3, enemy4, enemy5;

  // vector<sf::Sprite*> projectiles;
   vector<sf::Sprite*> projectiles;

   vector<Enemy*> enemies;
   sf::FloatRect enemyHitbox;
   bool leftisPressed, rightisPressed, fireKeyPressed;
   time_t time_accumulator;
   long int last_time;
};

#endif