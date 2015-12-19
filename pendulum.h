#pragma once

using namespace sf;
using namespace std;

void set_properties(ConvexShape &pendulum) {
	pendulum.setOrigin(130, 50);
	pendulum.setPosition(490, 100);
	pendulum.setFillColor(Color::Blue);
}

void pendulum_rotation(ConvexShape &pendulum, ConvexShape &leftPallet, ConvexShape &rightPallet, ConvexShape &weight, float rotation) {
	pendulum.setRotation(rotation);
	leftPallet.setRotation(rotation);
	rightPallet.setRotation(rotation);
	weight.setRotation(rotation);
}

void init_pendulum(ConvexShape &pendulum, ConvexShape &leftPallet, ConvexShape &rightPallet, ConvexShape &weight) {
	pendulum.setPointCount(3);
	pendulum.setPoint(0, sf::Vector2f(130, 50));
	pendulum.setPoint(1, sf::Vector2f(230, 110));
	pendulum.setPoint(2, sf::Vector2f(30, 110));
	set_properties(pendulum);

	leftPallet.setPointCount(3);
	leftPallet.setPoint(0, sf::Vector2f(50, 110));
	leftPallet.setPoint(1, sf::Vector2f(30, 150));
	leftPallet.setPoint(2, sf::Vector2f(30, 110));
	set_properties(leftPallet);

	rightPallet.setPointCount(3);
	rightPallet.setPoint(0, sf::Vector2f(230, 110));
	rightPallet.setPoint(1, sf::Vector2f(230, 150));
	rightPallet.setPoint(2, sf::Vector2f(210, 110));
	set_properties(rightPallet);

	weight.setPointCount(6);
	weight.setPoint(0, sf::Vector2f(130, 50));
	weight.setPoint(1, sf::Vector2f(130, 310));
	weight.setPoint(2, sf::Vector2f(150, 330));
	weight.setPoint(3, sf::Vector2f(130, 350));
	weight.setPoint(4, sf::Vector2f(110, 330));
	weight.setPoint(5, sf::Vector2f(125, 310));
	set_properties(weight);
}
