#pragma once

#include <functional>
#include "GUI/Widget.hpp"

namespace gui
{

    class Button : public gui::Widget
    {
        public:
            Button(WidgetSize s = WidgetSize::Wide128);

            void setFunction(std::function<void(void)> func);
            void setText    (const std::string& str);
            void setTexture (const sf::Texture& tex);

            void handleEvent    (sf::Event e, const sf::RenderWindow& window) override;
            void render         (sf::RenderTarget& renderer) override;
            void setPosition    (const sf::Vector2f& pos) override;
            sf::Vector2f getPosition() const override;
            sf::Vector2f getSize() const override;

        private:
            void updateText();

            Rectangle   m_button;
            Text        m_text;
            std::function<void(void)> m_function = [](){std::cout << "Button as been clicked!" << std::endl;};

    };
    inline std::unique_ptr<Button> makeButton(WidgetSize s = WidgetSize::Wide128)
    { return std::make_unique<Button>(s); }
}