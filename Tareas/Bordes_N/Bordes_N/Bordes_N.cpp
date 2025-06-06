#include "Arbol.hpp"

int main()
{
    CBinTree t;
    t.Insert(100);
    t.Insert(30);
    t.Insert(200);
    t.Insert(10);
    t.Insert(40);
    t.Insert(24);
    t.Insert(20);
    t.Insert(300);
    t.Insert(250);
    t.Insert(270);
    t.Insert(70);
    t.Insert(80);
    t.Insert(150);
    t.Insert(170);
    t.Insert(120);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bordes_N");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        t.contorno(window);
        window.display();
    }

    return 0;
}