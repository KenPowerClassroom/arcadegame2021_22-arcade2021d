#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenSize.h"

class Window {
	// main window
	sf::RenderWindow m_window;
	int buttoncount{ 0 };
public:
	Window() : m_window(
		sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32),
		"SFML Playground",
		sf::Style::Titlebar | sf::Style::Close) {
		sf::Image icon;
		if (!icon.loadFromFile("./resources/images/harryandme.png"))
		{
			std::cout << "problem loading icon" << std::endl;
		}
		m_window.setIcon(540, 540, icon.getPixelsPtr());
		m_window.setVerticalSyncEnabled(true);
		m_window.setPosition(sf::Vector2i(50, 50));
		m_window.setSize(sf::Vector2u(ScreenSize::s_width * 3, ScreenSize::s_height * 3));
	};

	sf::RenderWindow& getWindow() {return m_window;}

	void startFrame() {
		m_window.clear(sf::Color(82, 82, 82, 255));
	}
	void changeScreenSize() {
		if (m_window.getSize().x == ScreenSize::s_width)
		{
			m_window.setSize(sf::Vector2u(ScreenSize::s_width * 2, ScreenSize::s_height * 2));
		}
		else if (m_window.getSize().x == ScreenSize::s_width * 2)
		{
			m_window.setSize(sf::Vector2u(ScreenSize::s_width * 3, ScreenSize::s_height * 3));
		}
		else if (m_window.getSize().x == ScreenSize::s_width * 3)
		{
			m_window.setSize(sf::Vector2u(ScreenSize::s_width * 4, ScreenSize::s_height * 4));
		}
		else if (m_window.getSize().x == ScreenSize::s_width * 4)
		{
			m_window.setSize(sf::Vector2u(ScreenSize::s_width * 5, ScreenSize::s_height * 5));
		}
		else
		{
			m_window.setSize(sf::Vector2u(ScreenSize::s_width, ScreenSize::s_height));
		}
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
				if (event.key.code == sf::Keyboard::P)
					changeScreenSize();
			}
		}
	}

};