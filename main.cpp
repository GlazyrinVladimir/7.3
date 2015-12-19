#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#include "var.h"
#include "pendulum.h"
#include "detail.h"

using namespace sf;
using namespace std;

void draw_objects(RenderWindow &window, RectangleShape background, ConvexShape pendulum, ConvexShape leftPallet, ConvexShape rightPallet, ConvexShape weight, Sprite firstDetail, Sprite secondDetail)
{
	window.clear();
	window.draw(background);
	window.draw(pendulum);
	window.draw(leftPallet);
	window.draw(rightPallet);
	window.draw(weight);
	window.draw(firstDetail);
	window.draw(secondDetail);
	window.display();
}

void init_background(RectangleShape &background) {
	background.setSize(sf::Vector2f(WINDOW_HEIGHT, WINDOW_WIDTH));
	background.setPosition(0, 0);
}

void calculation_speed(float &speed, float &acceleration, float &rotation, float &rotGear, bool &downhill) {
	if (int(speed * 1000) == 0) {
		speed = acceleration * 2;
		downhill = true;
	}
	if (int(rotation) == 0 && downhill) {
		if (speed > 0)
			rotGear -= acceleration;
		speed += acceleration * 8;
		acceleration = -acceleration;
		downhill = false;
	}
	rotGear += acceleration * 100;
	speed += acceleration;
	rotation += speed;
}

void start_move_time(RenderWindow &window, Sprite firstDetail, Sprite secondDetail) {
	float rotation = 30, rotGear = 0;
	float speed = -0.001;
	float acceleration = -0.001;
	bool downhill = true;

	init_gears(firstDetail, secondDetail);
	RectangleShape background;
	init_background(background);

	ConvexShape pendulum;
	ConvexShape leftPallet;
	ConvexShape rightPallet;
	ConvexShape weight;
	
	init_pendulum(pendulum, leftPallet, rightPallet, weight);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		firstDetail.setRotation(-rotGear);
		secondDetail.setRotation(rotGear);

		pendulum_rotation(pendulum, leftPallet, rightPallet, weight, rotation);
		calculation_speed(speed, acceleration, rotation, rotGear, downhill);

		draw_objects(window, background, pendulum, leftPallet, rightPallet, weight, firstDetail, secondDetail);
	}
}

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "lab7.3", sf::Style::Default);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	Texture firstDetailImage, secondDetailImage;
	Sprite firstDetail, secondDetail;

	firstDetailImage.loadFromFile("image/detail1.png");
	firstDetail.setTexture(firstDetailImage);

	secondDetailImage.loadFromFile("image/detail2.png");
	secondDetail.setTexture(secondDetailImage);

	start_move_time(window, firstDetail, secondDetail);
	return 0;
}