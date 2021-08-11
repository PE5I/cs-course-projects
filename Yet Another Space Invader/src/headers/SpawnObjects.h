/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: SpawnObjects is an abstract class containing the constructor for Projectile, Enemy, and Player objects
*/
#ifndef SPAWNOBJECTS_H
#define SPAWNOBJECTS_H

#include "standard_dependency.h"

class SpawnObject : public sf::RectangleShape {
public:
	SpawnObject(sf::Color const &newColor, sf::Vector2f const &size, sf::Vector2f const &position)
	{
		cout << "Inside SpawnObject constructor!" << endl;

		setFillColor(newColor);
		setSize(size);
		setPosition(position);
	}

	void virtual setObjWidth(float new_width) {
		obj_width = new_width;
	}
	void setObjHeight(float new_height) {
		obj_height = new_height;
	}
protected:

	float obj_width;
	float obj_height;
};

#endif