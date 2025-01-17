#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include <vector>
#include "Object.h"
#include "sas.hpp"
#include <fstream>

class Gui
{

public:
	enum class EventType
	{
		NUN = 0,
		SWITCH_DRAW_MODE = 1,  //c
		SWITCH_PAUSE = 2,      //z
		INCREASE_SPEED = 3,
		DECREASE_SPEED = 4,
		STANDART_PAUSE = 5,
		DRAW_GRAPH=6,
		MOVE_UP_START=7,
		MOVE_UP_END=8,
		MOVE_DOWN_START=9,
		MOVE_DOWN_END=10,
		MOVE_LEFT_START=11,
		MOVE_LEFT_END=12,
		MOVE_RIGHT_START=13,
		MOVE_RIGHT_END=14,
		CHANGE_SCALE=15,
		RESET_SCALE=16
	};

	Gui(int x, int y);
	~Gui();
	std::vector<Gui::EventType> get_events();
	void draw_graph(sf::VertexArray asd);
	void draw(std::vector<std::vector<Object::ObjectType>> result,WorldSize* w);
	sf::VertexArray zad();
	std::ifstream fin;
	bool isAppClosed();
	void draw_2(std::vector<std::vector<Object::ObjectType>> result, WorldSize* w);
private:
	
	sf::RenderWindow mWindow;
	sf::RenderWindow first_window;
	sf::Text mText;
};


#endif // !GUI_H


