#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
//#pragma comment(lib,"thor-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
//#pragma comment(lib,"thor.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 
#pragma comment(lib,"libyaml-cppmdd") 


#include "Game.h"
#include "Intro.h"

/// <summary>
/// @brief starting point for all C++ programs.
/// 
/// Create a game object and run it.
/// </summary>
/// <param name=""></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int, char* argv[])
{
	/*Intro* op = new Intro;
	op->playIntro();
	delete op;*/

	Game game;
	game.run();

	/*INPUT typeEnter;
	typeEnter.type = INPUT_KEYBOARD;
	typeEnter.ki.wScan = 0;
	typeEnter.ki.time = 0;
	typeEnter.ki.dwExtraInfo = 0;

	typeEnter.ki.wVk = 32;
	typeEnter.ki.dwFlags = 0;
	SendInput(1, &typeEnter, sizeof(INPUT));*/


	return 0;
}
