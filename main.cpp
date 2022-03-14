#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

double calculatearea(int radius);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circles");
    sf::CircleShape circle;

    int xpos = 0;
    int ypos = 0;
    int size = 50;


    while (window.isOpen())//GAME LOOP--------------------------------
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear();
        //modify these arguments so each is a different slot of the vectors above
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                circle.setRadius(size);
                circle.setFillColor((sf::Color(100, 0, 200, 255)));
                circle.setPosition(xpos + i * 100, ypos + j * 100);
                window.draw(circle);

            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                circle.setRadius(size/2);
                circle.setFillColor((sf::Color(245, 245, 245, 255)));
                circle.setPosition(xpos + i * 100 + 25, ypos + j * 100 + 25);
                window.draw(circle);

            }
        }
        calculatearea(100);
        calculatearea(50);
        calculatearea(25);
        cout << "screen area is " << (800.0 * 800.0) - calculatearea(50) * 64.0 << endl;
        window.display();

    }//end game loop-------------------------------------------------

    return 0;
} //end main
double calculatearea(int radius){
    double area = 3.14159 * (radius * radius);
    cout << "the area for " << radius << " is " << area << endl;
    return area;
}
