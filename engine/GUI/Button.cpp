#include <iostream>
#include "GUI/Button.hpp"

namespace gui {

Button::Button(WidgetSize s)
{
    m_button.setOutlineThickness(1);
    m_button.setOutlineColor(sf::Color::Green);
    m_button.setFillColor(sf::Color::Black);
    switch (s) {
        case WidgetSize::Wide128:
            m_button.setSize({128, 64});
            break;
        case WidgetSize::Wide256:
            m_button.setSize({256, 64});
            break;
        default:
            std::cerr << "Size of BUTTON not supported.\nSet to Wide128." << std::endl;
            m_button.setSize({128, 64});
            break;
    }
}

void Button::setFunction(std::function<void(void)>func)
{
    m_function = func;
}

void Button::setText (const std::string& str)
{
    m_text.setString(str);
    updateText();
}

void Button::setTexture (const sf::Texture& tex)
{
    m_button.setTexture(&tex);
}

void Button::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window);

    switch(e.type) {
        case sf::Event::MouseButtonPressed:
            switch(e.mouseButton.button) {
                case sf::Mouse::Left:
                    if (m_button.getGlobalBounds().contains((float)pos.x, (float)pos.y)) {
                        m_function();
                    }

                default:
                    break;
            }

        default:
            break;
    }
}

void Button::render(sf::RenderTarget& renderer)
{
    renderer.draw(m_button);
    renderer.draw(m_text);
}

void Button::setPosition(const sf::Vector2f& pos)
{
    m_button.setPosition(pos);
    m_text.setPosition(m_button.getPosition());
    updateText();
}

sf::Vector2f Button::getPosition() const
{
    return (m_button.getPosition());
}

sf::Vector2f Button::getSize() const
{
    return m_button.getSize();
}

void Button::updateText()
{
    m_text.setOrigin(m_text.getGlobalBounds().width  / 2,
                     m_text.getGlobalBounds().height / 2);

    m_text.move(m_button.getGlobalBounds().width  / 2.0f,
                m_button.getGlobalBounds().height / 2.5f);
}

}
