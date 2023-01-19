#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <ctime>
#include "bat.h"



struct Ball {
	sf::CircleShape shape;
	float speedx, speedy;
	int score;

};

void ball_init(Ball& ball) {
	ball.shape.setRadius(ball_r);
	ball.shape.setFillColor(ball_color);
	ball.shape.setPosition(ball_startpos);

	srand(time(nullptr));
	float arr_speed[]{ 1.f,2.f,3.f,4.f,5.f ,-5.f,-4.f,-3.f,-2.f,-1.f };
	int index = rand() % 10;
	ball.speedx = arr_speed[index];
	index = rand() % 5;
	ball.speedy = arr_speed[index];
}
void ball_rebound_horizontal(Ball& ball) {
	if (ball.shape.getPosition().x <= 0) {
		ball.speedx *= -1;
	}

	if (ball.shape.getPosition().x + 2 * ball_r >= window_size) {
		ball.speedx *= -1;
	}
}
void ball_rebound_vertical(Ball& ball) {

	if (ball.shape.getPosition().y <= 0) {
		ball.speedy *= -1;
	}

}


void ball_update(Ball& ball) {
	ball.shape.move(ball.speedx, ball.speedy);
	ball_rebound_horizontal(ball);
	ball_rebound_vertical(ball);

}
void ball_draw(Ball& ball, sf::RenderWindow& window) {
	window.draw(ball.shape);
}
