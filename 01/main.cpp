#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "House");
    window.clear();

    //Smoke
    sf::CircleShape shapeSmoke_0(20);
    shapeSmoke_0.setPosition({ 445, 100 });
    shapeSmoke_0.setFillColor(sf::Color(0xC0,0xC0,0xC0));
    window.draw(shapeSmoke_0);

    sf::CircleShape shapeSmoke_1(25);
    shapeSmoke_1.setPosition({ 450, 70 });
    shapeSmoke_1.setFillColor(sf::Color(0xC0,0xC0,0xC0));
    window.draw(shapeSmoke_1);

    sf::CircleShape shapeSmoke_2(30);
    shapeSmoke_2.setPosition({ 465, 30 });
    shapeSmoke_2.setFillColor(sf::Color(0xC0,0xC0,0xC0));
    window.draw(shapeSmoke_2);

    sf::CircleShape shapeSmoke_3(30);
    shapeSmoke_3.setPosition({ 490, 10 });
    shapeSmoke_3.setFillColor(sf::Color(0xC0,0xC0,0xC0));
    window.draw(shapeSmoke_3);
    
    //Roof
    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0x50,0x00,0x00));
    //trapeze.setScale({ 2.5, 2 });
    trapeze.setPosition({ 395, 180 });
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-90, 0});
    trapeze.setPoint(1, {+90, 0});
    trapeze.setPoint(2, {+280, 120});
    trapeze.setPoint(3, {-280, 120});
    window.draw(trapeze);

    //Pipe
    sf::RectangleShape shapePipe;
    shapePipe.setSize({ 30, 60 });
    shapePipe.setPosition({ 443, 175 });
    shapePipe.setFillColor(sf::Color(0x30,0x30,0x30));
    window.draw(shapePipe); 

    //OnPipe
    sf::RectangleShape shapeOnPipe;
    shapeOnPipe.setSize({ 55, 40 });
    shapeOnPipe.setPosition({ 430, 135 });
    shapeOnPipe.setFillColor(sf::Color(0x30,0x30,0x30));
    window.draw(shapeOnPipe); 

    //Wall
    sf::RectangleShape shapeWall;
    shapeWall.setSize({ 450, 230 });
    shapeWall.setPosition({ 170, 300 });
    shapeWall.setFillColor(sf::Color(0x60,0x30,0x00));
    window.draw(shapeWall); 

    //Door
    sf::RectangleShape shapeDoor;
    shapeDoor.setSize({ 70, 160 });
    shapeDoor.setPosition({ 210, 370 });
    shapeDoor.setFillColor(sf::Color(0x10,0x10,0x10));
    window.draw(shapeDoor); 

    window.display();

    sf::sleep(sf::seconds(30));
}