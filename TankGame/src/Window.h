#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenSize.h"

class Window {
	// main window
	sf::RenderWindow m_window;

public:
	Window() : m_window(
		sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32), 
		"SFML Playground",
		sf::Style::Default) {
			m_window.setVerticalSyncEnabled(true);
		};

	void startFrame() {
		m_window.clear(sf::Color(0, 0, 0, 0));
	}

	void drawSprites(const std::vector<sf::Sprite>& sprites) {
		for (auto s : sprites)
			m_window.draw(s);
	}

	void endFrame() { m_window.display(); }

	bool isOpen() { return m_window.isOpen(); }

	void processEvents()
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}

			if (sf::Event::KeyPressed == event.type)
			{
				if (event.key.code == sf::Keyboard::Escape)
					m_window.close();
			}
		}
	}

};