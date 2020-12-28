#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "Explosion.h"


#define _CRT_SECURE_NO_WARNINGS

using namespace std;


Explosion::Explosion()
{
	//Load SFML texture
	texture.loadFromFile("explosion.png");

	//Scale sprite and image to workable size
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.1, 0.1));

	//Activate ship
	status = true;
}


void Explosion::set_explosion_location(float x_pix, float y_pix)
{
	sprite.setPosition(x_pix, y_pix);
}


void Explosion::draw_explosion(sf::RenderWindow& window)
{
	sprite.setTexture(texture);
	window.draw(sprite);
}
