
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>

class Intro
{
public:
	Intro();
	void playIntro();
private:
	sf::RenderWindow m_window;
	sf::Texture logoTexture1;
	sf::Sprite fogyLogo;
	sf::Sound beep;
	sf::SoundBuffer beepBuffer;

	int introCount{ 0 };
	bool introBool{ false };
};