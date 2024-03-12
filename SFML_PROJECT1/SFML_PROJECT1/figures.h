#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace laba {

    class Shapes {
    public:
        CircleShape circle;
        CircleShape square;
        CircleShape triangle;

        float circleSpeedX;
        float circleSpeedY;
        float squareSpeedX;
        float squareSpeedY;
        float triangleSpeedX;
        float triangleSpeedY;
        Shapes()
            : circle(30), square(50, 4), triangle(25, 3)
        {
            circle.setFillColor(Color::Red);
            circle.setPosition(0, 600 - circle.getRadius() * 2);
            square.setFillColor(Color::Green);
            square.setPosition(0, 600 - square.getRadius() * 2);

            triangle.setFillColor(Color::Blue);
            triangle.setOrigin(triangle.getRadius() - (triangle.getGlobalBounds().width / 2.f), 0);
            triangle.setPosition(0, 600 - triangle.getRadius() * 1.5);

            circleSpeedX = 0.12;
            circleSpeedY = -0.12;
            squareSpeedX = 0.10;
            squareSpeedY = -0.10;
            triangleSpeedX = 0.05;
            triangleSpeedY = -0.05;
        }
    };
}