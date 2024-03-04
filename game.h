
#pragma once
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void Render();
	void Update();
	float mx=30;
	float my=30;

	sf::RenderWindow m_window;
	std::vector<sf::CircleShape> m_circle;

 };
#endif // GAME_H
