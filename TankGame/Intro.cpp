#include"Intro.h"

Intro::Intro() :
	m_window{ sf::VideoMode{ 720U, 720U, 32U }, " ", sf::Style::None}
{
	HWND hideWindow = GetConsoleWindow();
	ShowWindow(hideWindow, SW_HIDE);
	m_window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - 360, sf::VideoMode::getDesktopMode().height / 2 - 360));
	if (!logoTexture1.loadFromFile("resources/images/harryandme.png"))
	{
		std::cout << "problem loading logo" << std::endl;
	}
	fogyLogo.setTexture(logoTexture1);

	if (!beepBuffer.loadFromFile("resources/boonk.wav"))
	{
		std::cout << "problem loading icon" << std::endl;
	}
	beep.setBuffer(beepBuffer);
}

void Intro::playIntro()
{
	sf::Font m_font;
	if (!m_font.loadFromFile("resources/ogFont.ttf"))
	{
		std::cout << "problem loading icon" << std::endl;
	}
	sf::Text m_message;
	m_message.setFont(m_font);
	m_message.setString("");
	sf::Clock clock;
	sf::Time timeUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps);
	while (!introBool)
	{
		timeUpdate += clock.restart();
		while (timeUpdate > timePerFrame)
		{
			timeUpdate -= timePerFrame;
			m_window.clear(sf::Color(51, 51, 51, 255));

			if (introCount < 100)
			{
				int yPos = m_window.getSize().y / 2 - fogyLogo.getGlobalBounds().width / 2;
				float bitOff = (m_window.getSize().y / 100.0f) * introCount - fogyLogo.getGlobalBounds().height;
				fogyLogo.setPosition(yPos, bitOff);
			}
			if (introCount == 100)
			{
				m_message.setString("Harry and Stephen.INC");
				m_message.setPosition(m_window.getSize().x / 2.0f - m_message.getGlobalBounds().width / 2.0f, 80);
				beep.play();
			}
			else if (introCount < 210)
			{
				
			}
			else
			{
				introBool = true;
				m_window.close();
				HWND hideWindow = GetConsoleWindow();
				ShowWindow(hideWindow, SW_SHOW);
			}
			m_window.draw(fogyLogo);
			m_window.draw(m_message);
			m_window.display();
			introCount++;
		}
	}
}
