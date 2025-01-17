#include "God.h"
#include <iostream>

#define x_world_size 1920
#define y_world_size 1080

//#define need_to_pause false
//#define need_to_draw  true 

God::God(WorldSize* w) :
	mWorld (w),//map
	mWindow (x_world_size, y_world_size)//gui
{
	fout.open("out.out");
}
/*/
void God::first_mes(WorldSize* w)
{
	bool vod = true;
	sf::RenderWindow first_mes(sf::VideoMode(800, 600), "My window");
	sf::Event event;

	sf::Font font;//����� 

	if (!font.loadFromFile("111.ttf"))
	{
		std::cout << "Font load error!\n";
	}
	std::string s1;
	while (first_mes.isOpen())
	{
		while (vod)
		{
			sf::Event event;
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Key::Enter:
					{
						vod = false;
						break;
					}
					case sf::Keyboard::Key::Num0:
					{
						s1.push_back('0');
						(w->x) = (w->x) * 10;
						break;
					}
					case sf::Keyboard::Key::Num1:
					{
						s1.push_back('1');
						(w->x) = (w->x) * 10+1;
						break;
					}
					case sf::Keyboard::Key::Num2:
					{
						s1.push_back('2');
						(w->x) = (w->x) * 10 + 2;
						break;
					}
					case sf::Keyboard::Key::Num3:
					{
						s1.push_back('3');
						(w->x) = (w->x) * 10 + 3;
						break;
					}
					case sf::Keyboard::Key::Num4:
					{
						s1.push_back('4');
						(w->x) = (w->x) * 10 + 4;
						break;
					}
					case sf::Keyboard::Key::Num5:
					{
						s1.push_back('5');
						(w->x) = (w->x) * 10 + 5;
						break;
					}
					case sf::Keyboard::Key::Num6:
					{
						s1.push_back('6');
						(w->x) = (w->x) * 10 + 6;
						break;
					}
					case sf::Keyboard::Key::Num7:
					{
						s1.push_back('7');
						(w->x) = (w->x) * 10 + 7;
						break;
					}
					case sf::Keyboard::Key::Num8:
					{
						s1.push_back('8');
						(w->x) = (w->x) * 10 + 8;
						break;
					}
					case sf::Keyboard::Key::Num9:
					{
						s1.push_back('9');
						(w->x) = (w->x) * 10 + 9;
						break;
					}
				}
			}
			sf::Text text(s1, font, 10);
			sf::Text text_2("How much world?", font, 10);
			first_mes.draw(text_2);
			first_mes.draw(text);

		}
	}

}
*/
God::~God() 
{
	fout.close();
};

void God::run(WorldSize* w)
{
	for (long long n = 0;;)        // Namber // progress //
	{

		for (long long pr = 0; ; ++pr)
		{
			if (w->need_to_draw) mWindow.draw(mWorld.getPresentation(),w);
			
			if (w->need_to_pause) for (int i = 0; i < 7e5; i++) {}

			//Pair<int> a;//= Event::mouse();
			//std::cout << a.x << " " << a.y << '\n';

			Event C;
			C.mouse();

			mWorld.makeTurn(w);
			if (mWorld.need_to_evolve(w))
			{
				mWorld.evolve(w);
				std::cout  << pr << '\n';    ///       << n   << ": " 
				pr = 0;
				n++;
			}
		}
	}
}

void God::run_2(WorldSize* w)
{
	sf::VertexArray asd;
	for (int cnt = 1, era = 0; !mWindow.isAppClosed(); )
	{
		if (w->need_to_zad)
		{
			std::cout << std::endl << " ZAAAAAAAAAAAAAAD" << std::endl;
			asd = mWindow.zad();
			w->need_to_zad = false;
		}
		if (w->need_to_draw)
		{
			if ((w->mas_1) && (!(w->mas_2)))
				mWindow.draw(mWorld.getPresentation(), w);
			if ((!(w->mas_1)) && (w->mas_2))
				mWindow.draw_2(mWorld.getPresentation(), w);
		}
		else if (w->need_to_draw_graph) mWindow.draw_graph(asd);

		for (int i = 0; i < w->pause_time; i++)
		{
			std::vector<Gui::EventType> events = mWindow.get_events();
			for (int i = 0; i < events.size(); i++)
			{
				if (w->need_to_pause) for (int i = 0; i < 10e7; i++) {}
				switch (events[i])
				{
					case Gui::EventType::SWITCH_DRAW_MODE:
					{
						w->need_to_draw = !(w->need_to_draw);
						break;
					}
					case Gui::EventType::SWITCH_PAUSE:
					{
						w->mIsTurnedOff = !(w->mIsTurnedOff);
						if(w->mIsTurnedOff) std::cout << "Evolution is pause"<<std::endl;
						if (!(w->mIsTurnedOff)) std::cout << "Evolution is play" << std::endl;
						break;
					}
					case Gui::EventType::INCREASE_SPEED:
					{
						w->pause_time = (w->pause_time) + (w->pause_delta);
						break;
					}
					case Gui::EventType::DECREASE_SPEED:
					{
						w->pause_time = (w->pause_time) - (w->pause_delta);
						break;
					}
					case Gui::EventType::DRAW_GRAPH:
					{
						w->need_to_draw_graph = !(w->need_to_draw_graph);
						if (w->need_to_draw_graph)
							w->need_to_zad = true;
						w->need_to_move = !(w->need_to_move);
						w->need_to_draw = !(w->need_to_draw);
						break;
					}
					case Gui::EventType::MOVE_RIGHT_START: 
					{
						w->move_right = true;
						/*if (!((w->y_draw) + 1 >= (w->y)))
							w->y_draw = (w->y_draw) + 1;*/
						break;
					}
					case Gui::EventType::MOVE_RIGHT_END:
					{
						w->move_right = false;
						break;
					}
					case Gui::EventType::MOVE_LEFT_START:
					{
						w->move_left = true;
						std::cout << "Move";
						/*if ((w->y_draw - 1) >-1)
							w->y_draw = (w->y_draw) - 1;*/
						break;
					}
					case Gui::EventType::MOVE_LEFT_END:
					{
						w->move_left = false;
						std::cout << "SADF";
						break;
					}
					case Gui::EventType::MOVE_DOWN_START:
					{
						w->move_down = true;
						/*if (((w->x_draw) + 1 <= (w->x)))
							w->x_draw = (w->x_draw) + 1;*/
						break;
					}
					case Gui::EventType::MOVE_DOWN_END:
					{
						w->move_down = false;
						break;
					}
					case Gui::EventType::MOVE_UP_END:
					{
						w->move_up = false;
						/*if ((w->x_draw) - 1 >-1 )
							w->x_draw = (w->x_draw) - 1;
						std::cout << "End";*/
						break;
					}
					case Gui::EventType::MOVE_UP_START:
					{
						w->move_up = true;
						//std::cout << "Start";
						break;
					}
					case Gui::EventType::CHANGE_SCALE:
					{
						w->mas_1 = !(w->mas_1);
						w->mas_2 = !(w->mas_2);
						break;
					}
					case Gui::EventType::RESET_SCALE:
					{
						w->mas_1 = true;
						w->mas_2 = false;
						break;
					}
				}
			}
			if (!(w->need_to_draw)) break;
			
		}
		if (w->mIsTurnedOff) continue;
		
		if ((w->move_up)&&((w->x_draw) - 1 > -1))
				w->x_draw = (w->x_draw) - 1;

		if ((w->move_down)&&(((w->x_draw) + 1 <= (w->x))))
				w->x_draw = (w->x_draw) + 1;

		if((w->move_right)&& (((w->y_draw) + 1 <= (w->y))))
			w->y_draw = (w->y_draw) + 1;

		if ((w->move_left) && ((w->y_draw) - 1 > -1))
			w->y_draw = (w->y_draw) - 1;
		


		if(w->need_to_move) 
		{
			mWorld.makeTurn(w);
			++cnt;
		}
		
		if (mWorld.need_to_evolve(w))
		{
			mWorld.evolve(w);
			std::cout << era << ": " << cnt << std::endl;

			fout << era << " " << cnt << std::endl;

			cnt = 0;
			++era;
						
		}
	}
}

