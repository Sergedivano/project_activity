#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <time.h>
#include "Game.h"
#include "Game.cpp"

using namespace sf;

class Button {
public:
    Texture s, e, m;
    Sprite start, exit, menu, prod, naczap;

    Button() {
        s.loadFromFile("C:/labs/Project_activity/sfml3/project_activity/start.png");
        e.loadFromFile("C:/labs/Project_activity/sfml3/project_activity/exit.png");
        m.loadFromFile("C:/labs/Project_activity/sfml3/project_activity/menu.png");

        start.setTexture(s);
        start.setPosition(585, 380);
        start.setTextureRect(IntRect(0, 0, 196, 200));

        exit.setTexture(e);
        exit.setPosition(585, 470);
        exit.setTextureRect(IntRect(0, 0, 196, 200));

        menu.setTexture(m);
        menu.setPosition(585, 150);
        menu.setTextureRect(IntRect(0, 0, 196, 300));

        prod.setTexture(s);
        prod.setPosition(585, 150);
        prod.setTextureRect(IntRect(0, 0, 196, 65));

        naczap.setTexture(s);
        naczap.setPosition(585, 300);
        naczap.setTextureRect(IntRect(0, 65, 196, 65));
    }
};

class Boolean {
public:
    bool stop = true, play = false, pause = false;
};

Boolean boolean;

class Stopwatch {
    public:
        Sprite min[2], sec[2], toc;
        int m[2], s[2], ms;
    
        Stopwatch(Texture& image) {
            for (int i = 0; i < 2; i++) {
                min[i].setTexture(image);
                sec[i].setTexture(image);
    
                min[i].setPosition(600 + 30 * i, 25);
                sec[i].setPosition(680 + 30 * i, 25);
    
                min[i].setTextureRect(IntRect(0, 0, 24, 38));
                sec[i].setTextureRect(IntRect(0, 0, 24, 38));
    
                m[i] = 0;
                s[i] = 0;
            }
    
            toc.setTexture(image);
            toc.setPosition(585, 100);
            toc.setTextureRect(IntRect(240, 0, 24, 38));
    
            ms = 0;
        }
    
        void update() {
            if (boolean.play)
                ms++;
    
            if (ms >= 7) {
                s[1]++;
                ms = 0;
            }
    
            if (s[1] == 10) {
                s[0]++;
                s[1] = 0;
            }
    
            if (s[0] == 6) {
                m[1]++;
                s[0] = 0;
            }
    
            if (m[1] == 10) {
                m[0]++;
                m[1] = 0;
            }
    
            for (int i = 0; i < 2; i++) {
                sec[i].setTextureRect(IntRect(24 * s[i], 0, 24, 38));
                min[i].setTextureRect(IntRect(24 * m[i], 0, 24, 38));
            }
        }
    };

class Gaming {
public:
    int x = 0, y = 0; 
};

int main()
{
    srand(time(0));

    // Создаем окно размером 800 на 600 и частотой обновления 60 кадров в секунду
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
	RenderWindow window(
        VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pyatnashki");
    window.setFramerateLimit(60);

	Font font;
    font.loadFromFile("calibri.ttf");
   
	// Текст с обозначением клавиш
    Text text("Pyatnashki Game", font, 30);
	text.setFillColor(Color::Cyan);
    text.setPosition(5.f, 5.f);

    // Позиционирование текста
    FloatRect bounds(text.getLocalBounds());
    text.setPosition(
        window.getSize().x/2 - (bounds.left + bounds.width/2), 
        window.getSize().y/15 - (bounds.top + bounds.height));

   	// Создаем объект игры
	Game game;
    game.setPosition(50.f, 50.f);
    
    Button button;

    Texture ti;
    ti.loadFromFile("C:/labs/Project_activity/sfml3/project_activity/time.png");
    Stopwatch watch(ti);

	Event event;
	int move_counter = 0;	// Счетчик случайных ходов для перемешивания головоломки

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed) window.close();
            
			if (event.type == Event::KeyPressed)
			{
				// Получаем нажатую клавишу - выполняем соответствующее действие
				if (event.key.code == Keyboard::Escape) window.close();
				if (event.key.code == Keyboard::Left) game.Move(Direction::Left);
				if (event.key.code == Keyboard::Right) game.Move(Direction::Right);
				if (event.key.code == Keyboard::Up) game.Move(Direction::Up);
				if (event.key.code == Keyboard::Down) game.Move(Direction::Down);
				// Новая игра
				if (event.key.code == Keyboard::F2)
				{
                    game.Init();
					move_counter = 100;
                }
            
            if (event.type == Event::MouseButtonPressed)
                if (event.mouseButton.button == Mouse::Left) 
                {
                    Vector2i pos = Mouse::getPosition(window);

                    if (boolean.play) {
                        if (pos.x <= 512) 
                        {
                            //gaming.x = pos.x
                            //gaming.y = pos.y
                        }
                    else if (button.start.getGlobalBounds().contains(pos.x, pos.y)) 
                    {
                            boolean.pause = true;
                            boolean.play = false;
                    }
                    else if (boolean.stop) 
                    {
                        if (button.start.getGlobalBounds().contains(pos.x, pos.y)) 
                        {
                            boolean.stop = false;

                            window.setFramerateLimit(0);

                            for (int i = 0; i < 2; i++) 
                            {
                                watch.m[i] = 0;
                                watch.s[i] = 0;
                            }
                            watch.ms = 0;  

                            button.start.setTextureRect(IntRect(0, 65, 196, 65));  
                        }    
                    }
                }    
			}
        }
    }

		// Если счетчик ходов больше нуля, продолжаем перемешивать головоломку
		if (move_counter-- > 0) game.Move((Direction)(rand() % 4));

		// Выполняем необходимые действия по отрисовке
        //gaming.update();
        window.clear();
        watch.update();
        window.draw(game);
            if (boolean.stop || boolean.play)
        window.draw(button.start);
            for (int i = 0; i < 2; i++) 
            {
                window.draw(watch.min[i]);
                window.draw(watch.sec[i]);
            }
        window.draw(watch.toc);
            if (boolean.pause) 
            {
                window.draw(button.prod);
                window.draw(button.naczap);
            }
        window.draw(text);
        window.draw(button.exit);
        window.draw(button.menu);
        window.draw(button.start);
        window.draw(watch.toc);
        window.display();
	}

	return 0;
}