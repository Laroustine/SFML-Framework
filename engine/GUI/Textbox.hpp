#pragma once

#include <functional>

#include "GUI/Widget.hpp"

namespace gui
{
    class TextBox : public gui::Widget
    {
        public:
            TextBox(WidgetSize s = gui::WidgetSize::Wide256, const std::string& modString = "TextBox");

            void setTitle       (const std::string& str);
            void setTexture     (const sf::Texture& tex);

            void handleEvent    (sf::Event e, const sf::RenderWindow& window) override;
            void render         (sf::RenderTarget& renderer) override;
            void setPosition    (const sf::Vector2f& pos) override;
            sf::Vector2f getPosition() const override;
            sf::Vector2f getSize() const override;

        private:
            void handleClick    (sf::Event e, const sf::RenderWindow& window);
            void handleTextInput(sf::Event e);

            bool isValidCharacter   (unsigned char keyCode);
            bool isBackspace        (unsigned char keycode);
            bool isQuit             (unsigned char keycode);


            sf::Vector2f    m_position;

            Rectangle       m_rect;
            Text            m_text;
            Text            m_label;
            std::string     m_pModString;

            bool m_isActive = false;
    };

    inline std::unique_ptr<TextBox> makeTextBox(WidgetSize s = WidgetSize::Wide256, const std::string& modStr = "TextBox")
    { return std::make_unique<TextBox>(s, modStr); }
}
