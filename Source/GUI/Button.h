#ifndef GUIBUTTON_H_INCLUDED
#define GUIBUTTON_H_INCLUDED

#include <functional>

#include "Widget.h"

namespace gui
{
    class Button : public gui::Widget
    {
        public:
            Button();

            void setFunction(std::function<void(void)> func);
            void setText    (const std::string& str);
            void setTexture (const sf::Texture& tex);

            void handleEvent    (sf::Event e, const sf::RenderWindow& window) override;
            void render         (sf::RenderTarget& renderer)override;
            void setPosition    (const sf::Vector2f& pos)         override;
            sf::Vector2f getSize() const                    override;

        private:
            void updateText();

            sf::Vector2f       m_position;
            sf::RectangleShape m_button;
            sf::Text m_text;
            std::function<void(void)> m_function = [](){};

    };
}

#endif // GUIBUTTON_H_INCLUDED
