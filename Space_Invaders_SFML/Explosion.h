#pragma once

#ifndef EXPLOSION_CLASS_H
#define EXPLOSION_CLASS_H

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Alien.h"
#include "Human.h"


#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class Explosion
{
private:
	sf::Sprite sprite;

	sf::Texture texture;

	bool status;

public:
	Explosion();

	void set_explosion_location(float x_pix, float y_pix);

	void draw_explosion(sf::RenderWindow& window);

};

/*
Description: yadda yadda yadda


*/


#endif