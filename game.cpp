#include "game.h"

	
Game::Game() :m_window(sf::VideoMode(1280,720),"game mode") {
sf::CircleShape circle1(50);

	m_window.setFramerateLimit(60);
	circle1.setFillColor(sf::Color::Magenta);

	float mx = m_window.getSize().x / 2;
	float my = m_window.getSize().y / 2;
	m_circle.push_back(circle1);

	

	circle1.setPosition(mx, my);

	sf::CircleShape circle2(30);
	circle1.setFillColor(sf::Color::Cyan);
	circle2.setPosition(200, 400);
	m_circle.push_back(circle2);



}
void Game::run() {
	while (m_window.isOpen())
	{
		processEvents();
		Render();
		Update();


	}
}
void Game::processEvents() {
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
	}
}
void Game::Update() {
   
    sf::Vector2f position = m_circle[0].getPosition();
    float radius = m_circle[0].getRadius();
    sf::Vector2u windowSize = m_window.getSize();
    
	 float speed = 30.0f;
    if (position.x < 0 || position.x > windowSize.x - radius * 2) {
        mx=-mx; // Reverse direction if hitting left or right boundary
    }
    if (position.y < 0 || position.y > windowSize.y - radius * 2) {
		my = -my; // Reverse direction if hitting top or bottom boundary
    }
	for (auto & circle:m_circle){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        circle.move(mx, 0);
    }
	
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        circle.move(-mx, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        circle.move(0, -my);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        circle.move(0, my);
    }
	}
}


void Game::Render() {
	m_window.clear();
	for (const auto& circle : m_circle) {
		m_window.draw(circle);
}
	m_window.display();

	

}