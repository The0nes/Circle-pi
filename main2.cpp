#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
using namespace std;

double calculatearea(int radius);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circles");
    sf::CircleShape circle;

    int xpos = 0;
    int ypos = 0;
    int size = 50;
    float i = 0;


    //while (window.isOpen())//GAME LOOP--------------------------------
    //{
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear();
        //modify these arguments so each is a different slot of the vectors above
        while(i<6.28){
        //for (int i = 0; i < 10000; i+=300) {
           
                circle.setRadius(size);
                circle.setFillColor((sf::Color(52, 152, 219, 50)));
                //xpos = sin(3.14 * i) * 150;
                //ypos = cos(3.14 * i) * 150;
                //circle.setPosition(xpos + 400, ypos + 400);
                circle.setPosition(400 + sin(3*i) * 200, 400 + cos(i) * 200);
                window.draw(circle);
                i += 3.14 / 50;

        }
        calculatearea(100);
        calculatearea(50);
        calculatearea(25);
        cout << "screen area is " << (800.0 * 800.0) - calculatearea(50) * 64.0 << endl;
        window.display();

   // }//end game loop-------------------------------------------------
        system("pause");
    return 0;
} //end main
double calculatearea(int radius){
    double area = 3.14159 * (radius * radius);
    cout << "the area for " << radius << " is " << area << endl;
    return area;
}
