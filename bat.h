#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <iostream>
#include "ball.h"

struct Bat {
	sf::RectangleShape shape;
	float speed;
};

void bat_init(Bat& bat) {
	bat.shape.setSize(bat_size);
	bat.shape.setFillColor(bat_collor);
	bat.shape.setPosition(bat_startpos);
	bat.speed = 10.f;
}



void bat_update(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { bat.shape.move(bat_speed, 0); }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { bat.shape.move(-bat_speed, 0); }

	if (bat.shape.getPosition().x < 0) { bat.shape.move(bat_speed, 0); }

	if (bat.shape.getPosition().x + bat_size.x > window_size) { bat.shape.move(-bat_speed, 0); }
}


void bat_draw(Bat& bat, sf::RenderWindow& window) {
	window.draw(bat.shape);
}
