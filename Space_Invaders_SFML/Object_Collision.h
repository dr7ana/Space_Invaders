#pragma once

#ifndef OBJECT_COLLISION_MANAGER_H
#define OBJECT_COLLISION_MANAGER_H

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Alien.h"
#include "Human.h"
#include "Torpedo.h"


#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class Collision
{
public:
	static bool collision_between(Ship& human_ship, Alien& alien_ship);

	static bool collision_between(Torpedo& torp, Alien& alien_ship);
};

/*
This class solely consists of two overloaded functions, representing different collisions that may be encountered.
The first function refers to an alien ship colliding with the player, resulting in the game over screen. The second
function refers to a collision between a torpedo and an alien ship, destroying the alien ship and displaying the
destruction image.

"Static" is added to these member function definitions to allow for the use of static member functions from the 
SFML module in Object_collision.cpp. Specifically, the SF::FloatRect::intersect function.
*/


#endif