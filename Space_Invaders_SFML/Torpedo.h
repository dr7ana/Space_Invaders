/*
Class: Torpedo.h
Purpose: To define the methods for the function of the player fired torpedo
Detais: The member functions for human.h, alien.h, and torpedo.h are all mostly similar. Sprites, tectures, status, and movement speed
are stored as private member values, while the getters and setters are public. All have a draw function that references the address of the
SFML object produced by SF::renderWindow -- the function that produces the game window.
*/

#pragma once

#ifndef TORPEDO_CLASS_H
#define TORPEDO_CLASS_H


#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class Torpedo
{
private:
	sf::Sprite sprite;

	sf::Texture texture;

	bool status;

	float movement_speed;

public:
	Torpedo() {};
	Torpedo(float speed);
	//~Torpedo();

	void activate(bool stat) { 
		status = stat; }

	void destroy() { 
		status = false; }

	bool is_alive() { 
		return status; }

	sf::Sprite& get_sprite() { 
		return sprite; }

	void set_torpedo_location(float x_pix, float y_pix);

	void draw_torpedo(sf::RenderWindow& window);

};


#endif