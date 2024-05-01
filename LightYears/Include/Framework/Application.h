#pragma once
#include <SFML/Graphics.hpp>
namespace ly
{
	class Application
	{
	public: 
		Application(); //constructor
		void run();

	private:
		void Render();
		void Tick(float deltaTime);
		sf::RenderWindow m_window;
		float mTargetFrameRate;
		sf::Clock mTickClock;

	};
}