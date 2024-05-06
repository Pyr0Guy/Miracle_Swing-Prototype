#include "engine/Game.h"

int main(int argc, char** argv)
{
	Game game;

	game.Run();

	/*
		//FPS showing thing
		currentTime = fpsClock.getElapsedTime();
		fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
		//std::cout << "fps = " << floor(fps) << std::endl;
		previousTime = currentTime;
	*/

	return EXIT_SUCCESS;
}

/* */