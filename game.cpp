#include "game.hpp"



Game::Game(){}

Game::~Game(){}

SDL_Texture* playerTexture;
SDL_Rect sourceRectangle, destinationRectangle;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized!..";
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	SDL_Surface* surface = IMG_Load("assets/man.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Game::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update(){
	count++;

	destinationRectangle.w = 128;
	destinationRectangle.h = 128;
	destinationRectangle.x = count;
	std::cout << count << std::endl;
}

void Game::render(){
	SDL_RenderClear(renderer);
	// This is where we would add stuffer to render
	SDL_RenderCopy(renderer, playerTexture, NULL, &destinationRectangle);
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
