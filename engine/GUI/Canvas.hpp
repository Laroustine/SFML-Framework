#pragma once

#include <functional>
#include "GUI/Widget.hpp"

namespace gui
{

    class Canvas : public gui::Widget
    {
        public:
            Canvas(WidgetSize s = WidgetSize::Small32);
            Canvas(WidgetSize s, const sf::Texture& tex);

            void setTexture (const sf::Texture& tex);
            void setTextureRect (const sf::IntRect& rectangle);
            void setSize (const sf::Vector2f& size);

            void handleEvent    (sf::Event e, const sf::RenderWindow& window) override;
            void render         (sf::RenderTarget& renderer) override;
            void setPosition    (const sf::Vector2f& pos) override;
            sf::Vector2f getPosition() const override;
            sf::Vector2f getSize() const override;

        private:
            Rectangle m_rect;
    };
}
