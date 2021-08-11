/*
* Programmers: Jacob J, Derek N, Konstantin S, Pesi T
* Class: CptS 122
* Programming Assignment: PA9
* Date: 06/12/2017
* Description: Asset manager contains functions for importing texture, font, and other graphical dependencies to the screen
*/
#include "AssetManager.h"

//loads tectures
void AssetManager::loadTexture(std::string name, std::string filepath)
{
   sf::Texture tex;

   if (tex.loadFromFile(filepath))
   {
      Textures[name] = tex;
   }
}

//getter fucntion for textures
sf::Texture & AssetManager::getTexture(std::string name)
{
   return Textures[name];
}

//loads the font
void AssetManager::loadFont(std::string name, std::string filepath)
{
   sf::Font font;

   if (font.loadFromFile(filepath))
   {
      Fonts[name] = font;
   }
}

//getter for font
sf::Font & AssetManager::getFont(std::string name)
{
   return Fonts[name];
}
