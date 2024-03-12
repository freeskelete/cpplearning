#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "figures.h"

using namespace sf;
using namespace std;
using namespace laba;

namespace m_laba {
	class ShapeMech : public laba::Shapes {
    public:
        void moveShapes() {
            circle.move(circleSpeedX, circleSpeedY);
            square.move(squareSpeedX, squareSpeedY);
            triangle.move(triangleSpeedX, triangleSpeedY);
        }

        void checkBounds(float windowWidth, float windowHeight) {
            if (circle.getPosition().x + 2*circle.getRadius() >= windowWidth) {
                circle.setPosition(windowWidth - 2*circle.getRadius(), circle.getPosition().y);
                circleSpeedX = -circleSpeedX;
                circle.setFillColor(set_color(circle.getFillColor()));
            }
            if (circle.getPosition().y + 2*circle.getRadius() >= windowHeight) {
                circle.setPosition(circle.getPosition().x, windowHeight - 2*circle.getRadius());
                circleSpeedY = -circleSpeedY;
                circle.setFillColor(set_color(circle.getFillColor()));
            }

            if (circle.getPosition().y <= 0) {
                circle.setPosition(circle.getPosition().x, 0);
                circleSpeedY = -circleSpeedY;
                circle.setFillColor(set_color(circle.getFillColor()));
            }
            if (circle.getPosition().x <= 0) {
                circle.setPosition(0, circle.getPosition().y);
                circleSpeedX = -circleSpeedX;
                circle.setFillColor(set_color(circle.getFillColor()));
            }
            if (square.getPosition().x + 2 * square.getRadius() >= windowWidth) {
                square.setPosition(windowWidth - 2 * square.getRadius(), square.getPosition().y);
                squareSpeedX = -squareSpeedX;
                square.setFillColor(set_color(square.getFillColor()));
            }
            if (square.getPosition().y + 2 * square.getRadius() >= windowHeight) {
                square.setPosition(square.getPosition().x, windowHeight - 2 * square.getRadius());
                squareSpeedY = -squareSpeedY;
                square.setFillColor(set_color(square.getFillColor()));
            }

            if (square.getPosition().y <= 0) {
                square.setPosition(square.getPosition().x, 0);
                squareSpeedY = -squareSpeedY;
                square.setFillColor(set_color(square.getFillColor()));
            }
            if (square.getPosition().x <= 0) {
                square.setPosition(0, square.getPosition().y);
                squareSpeedX = -squareSpeedX;
                square.setFillColor(set_color(square.getFillColor()));
            }

            if (triangle.getPosition().x + triangle.getGlobalBounds().width >= windowWidth) {
                triangle.setPosition(windowWidth - triangle.getGlobalBounds().width, triangle.getPosition().y);
                triangleSpeedX = -triangleSpeedX;
                triangle.setFillColor(set_color(triangle.getFillColor()));
            }
            if (triangle.getPosition().y + triangle.getGlobalBounds().height >= windowHeight) {
                triangle.setPosition(triangle.getPosition().x, windowHeight - triangle.getGlobalBounds().height);
                triangleSpeedY = -triangleSpeedY;
                triangle.setFillColor(set_color(triangle.getFillColor()));
            }

            if (triangle.getPosition().y <= 0) {
                triangle.setPosition(triangle.getPosition().x, 0);
                triangleSpeedY = -triangleSpeedY;
                triangle.setFillColor(set_color(triangle.getFillColor()));
            }
            if (triangle.getPosition().x <= 0) {
                triangle.setPosition(0, triangle.getPosition().y);
                triangleSpeedX = -triangleSpeedX;
                triangle.setFillColor(set_color(triangle.getFillColor()));
            }
        }
        Color set_color(Color current_color) {
            Color result_color = Color(rand() % 255, rand() % 255, rand() % 255);
            while (current_color == result_color) {
                result_color = Color(rand() % 255, rand() % 255, rand() % 255);
            }
            return result_color;
        }
        const CircleShape& getCircle() const {
            return circle;
        }

        const CircleShape& getSquare() const {
            return square;
        }

        const CircleShape& getTriangle() const {
            return triangle;
        }
    };
};