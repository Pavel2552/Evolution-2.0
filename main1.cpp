#include "Gui.h";
#include "Map.h";
#include "God.h";
#include "sas.hpp";

#include <SFML/Graphics.hpp>

#include <filesystem>
#include <iostream>

#include <thread>

void first_message(WorldSize* w)
{
	std::cout << "How much world?" << std::endl;
	std::cin >> w->x >> w->y;
	std::cout << "How much bot?" << std::endl;
	std::cin >> w->amount_bot;
	std::cout << "How much poison?" << std::endl;
	std::cin >> w->amount_poison;
	std::cout << "How much food?" << std::endl;
	std::cin >> w->amount_food;
	std::cout << "How much wall?" << std::endl;
	std::cin >> w->amount_wall;
	std::cout << "How mauch bot to evolue?" << std::endl;
	std::cin >> w->amount_boot_evolue;
	std::cout << std::endl;
	std::cout << "Need to cordinates(1-Yes,0-No)"<<std::endl;
	std::cin >> w->need_to_cordinat;

}


int first_reading(WorldSize* w)
{
	bool vod_x = true, vod_y = false, vod_bot = false, vod_food = false;
	bool vod_poison=false,vod_wall=false;
	bool vod_bot_need_evoule = false;
	sf::RenderWindow first_mes(sf::VideoMode(800, 600), "My window");
	sf::Event event;

	sf::Font font;//רנטפע 

	if (!font.loadFromFile("111.ttf"))
	{
		std::cout << "Font load error!\n";
	}
	std::string s_x,s_y,s_b,s_f,s_p,s_w,s_m;
	while (first_mes.isOpen())
	{
		sf::Event event;
		while ((vod_x)&&(first_mes.pollEvent(event)))
		{
			
			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				w->need_to_error = true;
				break;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Key::Enter:
					{
						vod_x = false;
						vod_y = true;
						break;
					}
					case sf::Keyboard::Key::Num0:
					{
						s_x.push_back('0');
						(w->x) = (w->x) * 10;
						break;
					}
					case sf::Keyboard::Key::Num1:
					{
						s_x.push_back('1');
						(w->x) = (w->x) * 10+1;
						break;
					}
					case sf::Keyboard::Key::Num2:
					{
						s_x.push_back('2');
						(w->x) = (w->x) * 10 + 2;
						break;
					}
					case sf::Keyboard::Key::Num3:
					{
						s_x.push_back('3');
						(w->x) = (w->x) * 10 + 3;
						break;
					}
					case sf::Keyboard::Key::Num4:
					{
						s_x.push_back('4');
						(w->x) = (w->x) * 10 + 4;
						break;
					}
					case sf::Keyboard::Key::Num5:
					{
						s_x.push_back('5');
						(w->x) = (w->x) * 10 + 5;
						break;
					}
					case sf::Keyboard::Key::Num6:
					{
						s_x.push_back('6');
						(w->x) = (w->x) * 10 + 6;
						break;
					}
					case sf::Keyboard::Key::Num7:
					{
						s_x.push_back('7');
						(w->x) = (w->x) * 10 + 7;
						break;
					}
					case sf::Keyboard::Key::Num8:
					{
						s_x.push_back('8');
						(w->x) = (w->x) * 10 + 8;
						break;
					}
					case sf::Keyboard::Key::Num9:
					{
						s_x.push_back('9');
						(w->x) = (w->x) * 10 + 9;
						break;
					}
				}
			}
			std::cout << (w->x)<<std::endl;
			first_mes.clear();
			sf::Text text(s_x, font, 20);
			sf::Text text_2("How much world?", font, 20);
			text.setPosition(0,0);
			text_2.setPosition(50,50);
			first_mes.draw(text_2);
			first_mes.draw(text);
			first_mes.display();
		}

		while ((vod_y) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_y = false;
				w->need_to_error = true;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Enter:
				{
					vod_y = false;
					vod_bot = true;
					break;
				}
				case sf::Keyboard::Key::Num0:
				{
					s_y.push_back('0');
					(w->y) = (w->y) * 10;
					break;
				}
				case sf::Keyboard::Key::Num1:
				{
					s_y.push_back('1');
					(w->y) = (w->y) * 10 + 1;
					break;
				}
				case sf::Keyboard::Key::Num2:
				{
					s_y.push_back('2');
					(w->y) = (w->y) * 10 + 2;
					break;
				}
				case sf::Keyboard::Key::Num3:
				{
					s_y.push_back('3');
					(w->y) = (w->y) * 10 + 3;
					break;
				}
				case sf::Keyboard::Key::Num4:
				{
					s_y.push_back('4');
					(w->y) = (w->y) * 10 + 4;
					break;
				}
				case sf::Keyboard::Key::Num5:
				{
					s_y.push_back('5');
					(w->y) = (w->y) * 10 + 5;
					break;
				}
				case sf::Keyboard::Key::Num6:
				{
					s_y.push_back('6');
					(w->y) = (w->y) * 10 + 6;
					break;
				}
				case sf::Keyboard::Key::Num7:
				{
					s_y.push_back('7');
					(w->y) = (w->y) * 10 + 7;
					break;
				}
				case sf::Keyboard::Key::Num8:
				{
					s_y.push_back('8');
					(w->y) = (w->y) * 10 + 8;
					break;
				}
				case sf::Keyboard::Key::Num9:
				{
					s_y.push_back('9');
					(w->y) = (w->y) * 10 + 9;
					break;
				}
				}
			}
			std::cout << (w->y) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.display();
		}
	
		while ((vod_bot) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_bot = false;
				w->need_to_error = true;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Enter:
				{
					vod_bot = false;
					vod_food = true;
					break;
				}
				case sf::Keyboard::Key::Num0:
				{
					s_b.push_back('0');
					(w->amount_bot) = (w->amount_bot) * 10;
					break;
				}
				case sf::Keyboard::Key::Num1:
				{
					s_b.push_back('1');
					(w->amount_bot) = (w->amount_bot) * 10 + 1;
					break;
				}
				case sf::Keyboard::Key::Num2:
				{
					s_b.push_back('2');
					(w->amount_bot) = (w->amount_bot) * 10 + 2;
					break;
				}
				case sf::Keyboard::Key::Num3:
				{
					s_b.push_back('3');
					(w->amount_bot) = (w->amount_bot) * 10 + 3;
					break;
				}
				case sf::Keyboard::Key::Num4:
				{
					s_b.push_back('4');
					(w->amount_bot) = (w->amount_bot) * 10 + 4;
					break;
				}
				case sf::Keyboard::Key::Num5:
				{
					s_b.push_back('5');
					(w->amount_bot) = (w->amount_bot) * 10 + 5;
					break;
				}
				case sf::Keyboard::Key::Num6:
				{
					s_b.push_back('6');
					(w->amount_bot) = (w->amount_bot) * 10 + 6;
					break;
				}
				case sf::Keyboard::Key::Num7:
				{
					s_b.push_back('7');
					(w->amount_bot) = (w->amount_bot) * 10 + 7;
					break;
				}
				case sf::Keyboard::Key::Num8:
				{
					s_b.push_back('8');
					(w->amount_bot) = (w->amount_bot) * 10 + 8;
					break;
				}
				case sf::Keyboard::Key::Num9:
				{
					s_b.push_back('9');
					(w->amount_bot) = (w->amount_bot) * 10 + 9;
					break;
				}
				}
			}
			std::cout << (w->amount_bot) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_bot(s_b, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_bot.setPosition(0, 80);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_bot);
			first_mes.display();
		}
		while ((vod_food) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_food = false;
				w->need_to_error = true;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Key::Enter:
					{
						vod_food = false;
						vod_poison = true;
						break;
					}
					case sf::Keyboard::Key::Num0:
					{
						s_f.push_back('0');
						(w->amount_food) = (w->amount_food) * 10;
						break;
					}
					case sf::Keyboard::Key::Num1:
					{
						s_f.push_back('1');
						(w->amount_food) = (w->amount_food) * 10 + 1;
						break;
					}
					case sf::Keyboard::Key::Num2:
					{
						s_f.push_back('2');
						(w->amount_food) = (w->amount_food) * 10 + 2;
						break;
					}
					case sf::Keyboard::Key::Num3:
					{
						s_f.push_back('3');
						(w->amount_food) = (w->amount_food) * 10 + 3;
						break;
					}
					case sf::Keyboard::Key::Num4:
					{
						s_f.push_back('4');
						(w->amount_food) = (w->amount_food) * 10 + 4;
						break;
					}
					case sf::Keyboard::Key::Num5:
					{
						s_f.push_back('5');
						(w->amount_food) = (w->amount_food) * 10 + 5;
						break;
					}
					case sf::Keyboard::Key::Num6:
					{
						s_f.push_back('6');
						(w->amount_food) = (w->amount_food) * 10 + 6;
						break;
					}
					case sf::Keyboard::Key::Num7:
					{
						s_f.push_back('7');
						(w->amount_food) = (w->amount_food) * 10 + 7;
						break;
					}
					case sf::Keyboard::Key::Num8:
					{
						s_f.push_back('8');
						(w->amount_food) = (w->amount_food) * 10 + 8;
						break;
					}
					case sf::Keyboard::Key::Num9:
					{
						s_f.push_back('9');
						(w->amount_food) = (w->amount_food) * 10 + 9;
						break;
					}
				}
			}
			std::cout << (w->amount_food) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_b(s_b, font, 20);
			sf::Text text_3("How much food?", font, 20);
			sf::Text text_f(s_f, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_b.setPosition(0, 80);
			text_3.setPosition(0, 100);;
			text_f.setPosition(0, 120);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_b);
			first_mes.draw(text_3);
			first_mes.draw(text_f);
			first_mes.display();
		}
		while ((vod_poison) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_poison = false;
				w->need_to_error = true;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Enter:
				{
					vod_poison = false;
					vod_wall = true;
					break;
				}
				case sf::Keyboard::Key::Num0:
				{
					s_p.push_back('0');
					(w->amount_poison) = (w->amount_poison) * 10;
					break;
				}
				case sf::Keyboard::Key::Num1:
				{
					s_p.push_back('1');
					(w->amount_poison) = (w->amount_poison) * 10 + 1;
					break;
				}
				case sf::Keyboard::Key::Num2:
				{
					s_p.push_back('2');
					(w->amount_poison) = (w->amount_poison) * 10 + 2;
					break;
				}
				case sf::Keyboard::Key::Num3:
				{
					s_p.push_back('3');
					(w->amount_poison) = (w->amount_poison) * 10 + 3;
					break;
				}
				case sf::Keyboard::Key::Num4:
				{
					s_p.push_back('4');
					(w->amount_poison) = (w->amount_poison) * 10 + 4;
					break;
				}
				case sf::Keyboard::Key::Num5:
				{
					s_p.push_back('5');
					(w->amount_poison) = (w->amount_poison) * 10 + 5;
					break;
				}
				case sf::Keyboard::Key::Num6:
				{
					s_p.push_back('6');
					(w->amount_poison) = (w->amount_poison) * 10 + 6;
					break;
				}
				case sf::Keyboard::Key::Num7:
				{
					s_p.push_back('7');
					(w->amount_poison) = (w->amount_poison) * 10 + 7;
					break;
				}
				case sf::Keyboard::Key::Num8:
				{
					s_p.push_back('8');
					(w->amount_poison) = (w->amount_poison) * 10 + 8;
					break;
				}
				case sf::Keyboard::Key::Num9:
				{
					s_p.push_back('9');
					(w->amount_poison) = (w->amount_poison) * 10 + 9;
					break;
				}
				}
			}
			std::cout << (w->amount_poison) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_b(s_b, font, 20);
			sf::Text text_3("How much food?", font, 20);
			sf::Text text_f(s_f, font, 20);
			sf::Text text_4("How much poison?", font, 20);
			sf::Text text_p(s_p, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_b.setPosition(0, 80);
			text_3.setPosition(0, 100);;
			text_f.setPosition(0, 120);
			text_4.setPosition(0, 140);
			text_p.setPosition(0, 160);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_b);
			first_mes.draw(text_3);
			first_mes.draw(text_f);
			first_mes.draw(text_4);
			first_mes.draw(text_p);
			first_mes.display();
		}
		while ((vod_wall) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_wall = false;
				w->need_to_error = true;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Enter:
				{
					vod_wall = false;
					vod_bot_need_evoule = true;
					break;
				}
				case sf::Keyboard::Key::Num0:
				{
					s_w.push_back('0');
					(w->amount_wall) = (w->amount_wall) * 10;
					break;
				}
				case sf::Keyboard::Key::Num1:
				{
					s_w.push_back('1');
					(w->amount_wall) = (w->amount_wall) * 10 + 1;
					break;
				}
				case sf::Keyboard::Key::Num2:
				{
					s_w.push_back('2');
					(w->amount_wall) = (w->amount_wall) * 10 + 2;
					break;
				}
				case sf::Keyboard::Key::Num3:
				{
					s_w.push_back('3');
					(w->amount_food) = (w->amount_food) * 10 + 3;
					break;
				}
				case sf::Keyboard::Key::Num4:
				{
					s_w.push_back('4');
					(w->amount_wall) = (w->amount_wall) * 10 + 4;
					break;
				}
				case sf::Keyboard::Key::Num5:
				{
					s_w.push_back('5');
					(w->amount_wall) = (w->amount_wall) * 10 + 5;
					break;
				}
				case sf::Keyboard::Key::Num6:
				{
					s_w.push_back('6');
					(w->amount_wall) = (w->amount_wall) * 10 + 6;
					break;
				}
				case sf::Keyboard::Key::Num7:
				{
					s_w.push_back('7');
					(w->amount_wall) = (w->amount_wall) * 10 + 7;
					break;
				}
				case sf::Keyboard::Key::Num8:
				{
					s_w.push_back('8');
					(w->amount_wall) = (w->amount_wall) * 10 + 8;
					break;
				}
				case sf::Keyboard::Key::Num9:
				{
					s_w.push_back('9');
					(w->amount_wall) = (w->amount_wall) * 10 + 9;
					break;
				}
				}
			}
			std::cout << (w->amount_wall) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_b(s_b, font, 20);
			sf::Text text_3("How much food?", font, 20);
			sf::Text text_f(s_f, font, 20);
			sf::Text text_4("How much poison?", font, 20);
			sf::Text text_p(s_p, font, 20);
			sf::Text text_5("How much wall?", font, 20);
			sf::Text text_w(s_w, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_b.setPosition(0, 80);
			text_3.setPosition(0, 100);;
			text_f.setPosition(0, 120);
			text_4.setPosition(0, 140);
			text_p.setPosition(0, 160);
			text_5.setPosition(0, 180);
			text_w.setPosition(0, 200);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_b);
			first_mes.draw(text_3);
			first_mes.draw(text_f);
			first_mes.draw(text_4);
			first_mes.draw(text_p);
			first_mes.draw(text_5);
			first_mes.draw(text_w);
			first_mes.display();
		}
		while ((vod_bot_need_evoule) && (first_mes.pollEvent(event)))
		{

			if (event.type == sf::Event::Closed)
			{
				first_mes.close();
				vod_bot_need_evoule = false;
				w->need_to_error = true;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Key::Enter:
				{
					vod_bot_need_evoule = false;
					return 1;
					break;
				}
				case sf::Keyboard::Key::Num0:
				{
					s_m.push_back('0');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10;
					break;
				}
				case sf::Keyboard::Key::Num1:
				{
					s_m.push_back('1');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 1;
					break;
				}
				case sf::Keyboard::Key::Num2:
				{
					s_w.push_back('2');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 2;
					break;
				}
				case sf::Keyboard::Key::Num3:
				{
					s_m.push_back('3');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 3;
					break;
				}
				case sf::Keyboard::Key::Num4:
				{
					s_m.push_back('4');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 4;
					break;
				}
				case sf::Keyboard::Key::Num5:
				{
					s_m.push_back('5');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 5;
					break;
				}
				case sf::Keyboard::Key::Num6:
				{
					s_m.push_back('6');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 6;
					break;
				}
				case sf::Keyboard::Key::Num7:
				{
					s_m.push_back('7');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 7;
					break;
				}
				case sf::Keyboard::Key::Num8:
				{
					s_m.push_back('8');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 8;
					break;
				}
				case sf::Keyboard::Key::Num9:
				{
					s_m.push_back('9');
					(w->amount_boot_evolue) = (w->amount_boot_evolue) * 10 + 9;
					break;
				}
				}
			}
			std::cout << (w->amount_wall) << std::endl;
			first_mes.clear();
			sf::Text text("How much world?", font, 20);
			sf::Text text_x(s_x, font, 20);
			sf::Text text_y(s_y, font, 20);
			sf::Text text_2("How much bot?", font, 20);
			sf::Text text_b(s_b, font, 20);
			sf::Text text_3("How much food?", font, 20);
			sf::Text text_f(s_f, font, 20);
			sf::Text text_4("How much poison?", font, 20);
			sf::Text text_p(s_p, font, 20);
			sf::Text text_5("How much wall?", font, 20);
			sf::Text text_w(s_w, font, 20);
			sf::Text text_6("How much bot need to evolue?",font,20);
			sf::Text text_m(s_m, font, 20);
			text.setPosition(0, 0);
			text_x.setPosition(0, 20);
			text_y.setPosition(0, 40);
			text_2.setPosition(0, 60);
			text_b.setPosition(0, 80);
			text_3.setPosition(0, 100);;
			text_f.setPosition(0, 120);
			text_4.setPosition(0, 140);
			text_p.setPosition(0, 160);
			text_5.setPosition(0, 180);
			text_w.setPosition(0, 200);
			text_6.setPosition(0, 220);
			text_m.setPosition(0, 240);
			first_mes.draw(text);
			first_mes.draw(text_x);
			first_mes.draw(text_y);
			first_mes.draw(text_2);
			first_mes.draw(text_b);
			first_mes.draw(text_3);
			first_mes.draw(text_f);
			first_mes.draw(text_4);
			first_mes.draw(text_p);
			first_mes.draw(text_5);
			first_mes.draw(text_w);
			first_mes.draw(text_6);
			first_mes.draw(text_m);
			first_mes.display();
		}
	}
}


int main()
{
	
	WorldSize w;
	first_reading(&w);
	//if(!(w.otkladka)) first_message(&w);
	if (w.need_to_error)
	{
		std::cout << "ERROR";
		return 0;
	}

        
    God g(&w);
	g.run_2(&w);





}