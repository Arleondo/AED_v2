
#include <cmath>
#include <sstream>

using namespace std;

template <class T>
struct Node {
    Node<T>* Nodos[2];
    T valor;

    explicit Node(T valor, Node<T>* Left = nullptr, Node<T>* Right = nullptr) :
        valor(valor) {
        Nodos[0] = Left; Nodos[1] = Right;
    };
};

template <class T>
class Tree {
    Node<T>* Root;

    Node<T>**& rep(Node<T>** pos) {
        Node<T>** left = &((*pos)->Nodos[0]);
        for (; (*left)->Nodos[1] && *left; left = &((*left)->Nodos[1])) {}
        return left;
    }

public:

    Tree() : Root(nullptr) {};

    bool find(T valor, Node<T>**& pos) {
        /*
        while (*pos && (*pos)->valor!=valor ){
            if(valor<(*pos)->valor){
                pos = & ((*pos)->Left);
            }
            pos = &((*pos)->Right);
        }
        */

        while (*pos && (*pos)->valor != valor) {
            pos = &((*pos)->Nodos[(valor >= (*pos)->valor)]);
        }

        return *pos != nullptr;
    }

    bool Insert(T valor) {
        Node<T>** p = &Root;

        if (!find(valor, p)) {
            *p = new Node<T>(valor); return true;
        }
        return false;
    }

    bool Remove(T valor) {
        Node<T>** p = &Root;

        if (find(valor, p)) {
            //Caso 2
            if ((*p)->Nodos[0] && (*p)->Nodos[1]) {
                Node<T>** q = rep(p);
                (*p)->valor = (*q)->valor; p = q;
            }
            //Caso 1-0
            Node<T>* temp = *p; *p = (*p)->Nodos[(*p)->Nodos[1] != nullptr];
            delete temp; return true;
        }
        return false;
    }

};


template <class T>
class TreeDrawer {
    Node<T>* root;
    sf::RenderWindow window;
    const int nodeRadius = 20;
    const int horizontalSpacing = 40;
    const int verticalSpacing = 75;

public:
    TreeDrawer(Node<T>* root) : root(root), window(sf::VideoMode(800, 600), "Binary Tree Visualizer") {}

    void drawTree() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            drawNode(root, 400, 40, 200); // Start at center-top
            window.display();
        }
    }

private:
    void drawNode(Node<T>* node, int x, int y, int offsetX) {
        if (!node) return;

        sf::CircleShape circle(nodeRadius);
        circle.setFillColor(sf::Color(200, 220, 255));
        circle.setOutlineThickness(2);
        circle.setOutlineColor(sf::Color::Black);
        circle.setPosition(x - nodeRadius, y - nodeRadius);
        window.draw(circle);

        // Dibujar texto dentro del nodo
        sf::Font font;
        font.loadFromFile("arial.ttf");  // Asegúrate de tener esta fuente o cambia el nombre
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Black);

        std::stringstream ss;
        ss << node->valor;
        text.setString(ss.str());
        text.setPosition(x - 10, y - 10);
        window.draw(text);

        // Líneas y recursión
        for (int i = 0; i < 2; ++i) {
            if (node->Nodos[i]) {
                int newX = x + (i == 0 ? -offsetX : offsetX);
                int newY = y + verticalSpacing;
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x, y + nodeRadius)),
                    sf::Vertex(sf::Vector2f(newX, newY - nodeRadius))
                };
                window.draw(line, 2, sf::Lines);
                drawNode(node->Nodos[i], newX, newY, offsetX / 1.5);
            }
        }
    }
};