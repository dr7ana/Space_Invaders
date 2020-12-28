#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "Object_Collision.h"


#define _CRT_SECURE_NO_WARNINGS

using namespace std;


/*
The two following overloaded functions will return the coordinates of the intersection between the two objects.
SFML has a SF::FloatRect method that returns the four corners of the png for the object. The SF::intersects static method
is then called on the two FloatRect objects to find their intersection and return a boolean.

https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Rect.php
*/


bool Collision::collision_between(Ship& human_ship, Alien& alien_ship)
{
	//Human ship bounding box
	sf::FloatRect h_ship;

	h_ship.left = human_ship.get_sprite().getPosition().x + 8;					//	Fill FloatRect object values necessary for .intersect() member function
	h_ship.top = human_ship.get_sprite().getPosition().y + 8;					//	left/top calculated returned getposition() and accounting for adjusted target (8 pixels)
	h_ship.height = human_ship.get_sprite().getGlobalBounds().width - 8;		//	height/width returned using getGlobalBounds, which accounts for image resizing (do not
	h_ship.width = human_ship.get_sprite().getGlobalBounds().height - 8;		//	use getlocalbounds())
	
	//Alien ship bounding box
	sf::FloatRect a_ship;

	a_ship.left = alien_ship.get_sprite().getPosition().x;
	a_ship.top = alien_ship.get_sprite().getPosition().y;
	a_ship.height = alien_ship.get_sprite().getGlobalBounds().width;
	a_ship.width = alien_ship.get_sprite().getGlobalBounds().height;

	return h_ship.intersects(a_ship);
}


bool Collision::collision_between(Torpedo& torp, Alien& alien_ship)
{
	//Torpedo bounding box
	sf::FloatRect Torpedo;

	Torpedo.left = torp.get_sprite().getPosition().x;
	Torpedo.top = torp.get_sprite().getPosition().y;
	Torpedo.height = torp.get_sprite().getGlobalBounds().width;
	Torpedo.width = torp.get_sprite().getGlobalBounds().height;

	//Alien ship bounding box
	sf::FloatRect a_ship;

	a_ship.left = alien_ship.get_sprite().getPosition().x;
	a_ship.top = alien_ship.get_sprite().getPosition().y;
	a_ship.height = alien_ship.get_sprite().getGlobalBounds().width;
	a_ship.width = alien_ship.get_sprite().getGlobalBounds().height;

	return a_ship.intersects(Torpedo);
}