#include <iostream>
#include <SFML/Graphics.hpp>
#include "Framework\Application.h"
using std::endl;
using std::cout;

int main()
{
	//allocating on the heap
	ly::Application* app = new ly::Application();
	app->run();

	return 0;
}