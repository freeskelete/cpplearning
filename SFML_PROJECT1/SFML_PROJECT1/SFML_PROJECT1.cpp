#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "figures.h"
#include "mech.h"
#include <chrono>
#include <thread>


using namespace std;
using namespace laba;
using namespace m_laba;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Moving Shapes");

    ShapeMech shapes;
    srand(static_cast<unsigned int>(time(nullptr)));
    bool flag = true;


    while (window.isOpen()) {
        Event event;


        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();

        window.draw(shapes.getCircle());
        window.draw(shapes.getSquare());
        window.draw(shapes.getTriangle());

        window.display();

        if (flag) {
            flag = false;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }
        shapes.moveShapes();
        shapes.checkBounds(800, 600);
    }
    return 0;
}
