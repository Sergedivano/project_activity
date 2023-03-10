#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const int SIZE = 4;						// Размер игрового поля в плашках
const int ARRAY_SIZE = SIZE * SIZE;		// Размер массива
const int FIELD_SIZE = 500;				// Размер игрового поля в пикселях
const int CELL_SIZE = 120;				// Размер плашки в пикселях

enum class Direction { 
    Left, 
    Right, 
    Up, 
    Down
};

class Game : public Drawable, public sf::Transformable
{
protected:
	int elements[ARRAY_SIZE];
	int empty_index;
	bool solved;
    Font font;
    Image background;
public:
	Game();
	void Init();
	bool Check();
	void Move(Direction direction);
public:
	virtual void draw(RenderTarget& target, RenderStates states) const;
};