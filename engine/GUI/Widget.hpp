#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "ResourceManager/ResourceHolder.hpp"

namespace gui
{
    enum class WidgetSize
    {
        Small32 = 32,
        Small64 = 64,
        Wide128 = 128,
        Wide256 = 256,
        Huge512 = 512,
    };

    class Widget
    {
        public:
            virtual void handleEvent(sf::Event e, const sf::RenderWindow& window) = 0;

            virtual void render(sf::RenderTarget& renderer) = 0;

            virtual sf::Vector2f getPosition() const = 0;
            virtual void setPosition(const sf::Vector2f& pos) = 0;

            virtual sf::Vector2f getSize() const = 0;

            class Text : public sf::Text
            {
                public:
                    Text();
            };

            class Rectangle : public sf::RectangleShape
            {
                public:
                    bool isRolledOn (const sf::RenderWindow& window) const;
                    bool isClicked  (sf::Event, const sf::RenderWindow& window);
            };
    };
}

