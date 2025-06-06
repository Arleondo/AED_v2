#include "Arbolito.hpp"
#include <iostream>


int main() {
    
    Tree t;
    t.Insert(10);
    t.Insert(5);
    t.Insert(15);
    t.Insert(12);
    t.Insert(17);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Visualización del Árbol Binario");

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


	return 0;
}


