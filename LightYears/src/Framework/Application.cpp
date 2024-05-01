#include "Framework/Application.h"
#include <iostream>
namespace ly
{
	Application::Application() : m_window(sf::VideoMode(500, 800), "Light Years"),  //1024, 1440
		mTargetFrameRate(60.f), mTickClock(){}

	void Application::run()
	{
		mTickClock.restart();
		float accumulatedTime = 0;
		float targetDeltaTime = 1.f / mTargetFrameRate;
		while (m_window.isOpen())
		{
			sf::Event windowEvent;
			while (m_window.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					m_window.close();
				}
			}
		} //end of window 
		accumulatedTime += mTickClock.restart().asSeconds(); //when sf::clock resart is called it restarts the clock and returns the time stored in it before its wiped. 
		//checking if our time rate is up to par with our targetDelta time
		while (accumulatedTime > targetDeltaTime)
		{
			accumulatedTime -= targetDeltaTime; //the difference between target time and the time we got. need update
			Tick(targetDeltaTime);
			Render();
		}
	
	}
	void Application::Render()
	{
		m_window.clear();
		sf::RectangleShape rect(sf::Vector2f(100, 100));
		rect.setFillColor(sf::Color::Green);
		m_window.draw(rect);
		rect.setPosition(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);
		m_window.display();
	}
	void Application::Tick(float deltaTime)
	{
		std::cout << "ticking at frame rate: " << 1.f / deltaTime << std::endl;
		
	}
}