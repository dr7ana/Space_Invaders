#pragma once

#ifndef MAIN_MENU_CLASS_H
#define MAIN_MENU_CLASS_H

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>


#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class Menu
{
private:
	sf::Font main_font;
	sf::Font secondary_font;

	sf::Text main_text;
	sf::Text secondary_text;

public:

	Menu(sf::RenderWindow& window);

	sf::Text& get_text(int arg);

};




#endif