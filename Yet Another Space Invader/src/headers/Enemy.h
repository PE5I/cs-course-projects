/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: Enemy contains the prototypes for creating an enemy object. The Enemy class uses the constructor of the SpawnObject class to initialize its attributes
*/
#ifndef ENEMY_H
#define ENEMY_H
#include "SpawnObjects.h"

class Enemy : public SpawnObject {
public:
	Enemy(sf::Color const &newColor = sf::Color::Red, 
      sf::Vector2f const &size = sf::Vector2f(30, 30), 
      sf::Vector2f const &pos = sf::Vector2f(SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2))
		: SpawnObject(sf::Color::Red, size, pos) {
		//this->setTexture(enemytexture);
		cout << "Inside enemy constructor!" << endl;
	}

   ~Enemy() {}
	/*
	void setColor(sf::Color const &new_color) {
		setFillColor(new_color);
	}
	*/
	/*
	void setSize(string size) {
		setSize(size);
	}
	*/

	/*
	Enemies Spawn(sf::Color const enemy_color, double enemy_size_x, double enemy_size_y,
		double enemy_coord_x, double enemy_coord_y);
		*/
};
#endif