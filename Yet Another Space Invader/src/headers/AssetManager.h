/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: Asset manager contains the prototype for importing texture, font, and other graphical dependencies to the screen
*/
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "standard_dependency.h"
#include <map>

class AssetManager
{
public:
   void loadTexture(std::string name, std::string filepath);
   sf::Texture & getTexture(std::string name);

   void loadFont(std::string name, std::string filepath);
   sf::Font & getFont(std::string name);
   
private:
    std::map<std::string, sf::Texture> Textures;
    std::map<std::string, sf::Font> Fonts;

};
#endif