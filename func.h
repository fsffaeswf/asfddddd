#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"



bool point_in_rect(sf::RectangleShape bat, sf::Vector2f point) {
	float batx = bat.getPosition().x;
	float baty = bat.getPosition().y;
	return(point.x >= batx && point.x <= batx + bat_size.x) &&
		(point.y >= baty && point.y <= baty + bat_size.y);
}
void init_text(sf::Text& scoreText, int score, sf::Font& font,
	const int charSize, const sf::Vector2f textStartPos) {
	scoreText.setString(std::to_string(score));
	scoreText.setFont(font);
	scoreText.setCharacterSize(charSize);
	scoreText.setPosition(textStartPos);
}