#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include "func.h"
#include "bat.h"
#include "ball.h"
#include "brick.h"
using namespace sf;


int main()
{
	
	//ðàêåòêà 
	Bat bat;
	bat_init(bat);
	//ìÿ÷
	Ball ball;
	ball_init(ball);

	Brick brick;
	brick_init(brick, Color::Yellow, Vector2f{200,100});
	//ñ÷åò
	int player_score = 0;
	Font font;
	font.loadFromFile("DS-DIGIB.ttf");
	Text player_score_text;
	init_text(player_score_text, player_score, font, char_size, text_start_pos);

	// Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
	RenderWindow window(VideoMode(window_size, window_size), "SFML Works!");

	window.setFramerateLimit(fps);

	// Ãëàâíûé öèêë ïðèëîæåíèÿ. Âûïîëíÿåòñÿ, ïîêà îòêðûòî îêíî
	while (window.isOpen())
	{
		// Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
		Event event;
		while (window.pollEvent(event))
		{
			// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
			if (event.type == Event::Closed) {
				// òîãäà çàêðûâàåì åãî
				window.close();
			}


		}
		Vector2f mid_left{ ball.shape.getPosition().x, ball.shape.getPosition().y + ball_r };
		Vector2f mid_right{ ball.shape.getPosition().x + 2 * ball_r, ball.shape.getPosition().y + ball_r };
		Vector2f mid_bottom{ ball.shape.getPosition().x + ball_r, ball.shape.getPosition().y + 2 * ball_r };
		//îò âåðõíåé
		if (point_in_rect(bat.shape, mid_bottom)) {
			ball.speedy *= -1;
		}
		//îò ëåâîé
		if (point_in_rect(bat.shape, mid_left)) {
			ball.speedx *= -1;
		}
		//îò ïðàâîé
		if (point_in_rect(bat.shape, mid_right)) {
			ball.speedx *= -1;
		}

		RectangleShape arr_brick[size_mass];
		for (int i = 0; i < size_mass; i++) {
			arr_brick[i].setSize(Vector2f(brick_width, brick_height));
			arr_brick[i].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
			arr_brick[i].setPosition(brick_width*i,0);
		}
		bat_update(bat);
		ball_update(ball);
		brick_update(brick);


		window.clear();
		bat_draw(bat, window);
		ball_draw(ball, window);
		brick_draw(brick, window);
		window.draw(player_score_text);
		for (int k = 0; k < size_mass; k++) {
			window.draw(arr_brick[k]);
		}
		window.display();
	}
	return 0;
}