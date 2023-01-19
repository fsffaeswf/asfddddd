#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct Brick {
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f position;
};

void brick_init(Brick& brick, sf::Color color, sf::Vector2f position) {
	brick.color = color;
	brick.position = position;
	brick.shape.setSize(sf::Vector2f{ brick_width, brick_height });
	brick.shape.setFillColor(brick.color);
	brick.shape.setPosition(brick.position);
}
void brick_update(Brick& brick) {}

void brick_draw(Brick& brick, sf::RenderWindow& window) {
	window.draw(brick.shape);
}