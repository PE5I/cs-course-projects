/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: Player contains the functions for creating a player object that shoots projectiles at anenemy
*/
#include "Player.h"

void Player::loadTexture() {
	playertexture.loadFromFile("Enemies.jpg");
	cout << "Texture has been loaded" << endl;

}