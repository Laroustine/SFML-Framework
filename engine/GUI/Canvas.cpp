#include <iostream>
#include "GUI/Canvas.hpp"

namespace gui {

Canvas::Canvas(WidgetSize s)
{
    switch (s) {
        case WidgetSize::Small32:
            m_rect.setSize({32, 32});
            break;
        case WidgetSize::Small64:
            m_rect.setSize({64, 64});
            break;
        case WidgetSize::Wide128:
            m_rect.setSize({128, 128});
            break;
        case WidgetSize::Wide256:
            m_rect.setSize({256, 256});
            break;
        case WidgetSize::Huge512:
            m_rect.setSize({512, 512});
            break;
        case WidgetSize::FullPicture:
            m_rect.setSize({32, 32});
            break;
    }
    m_rect.setOrigin((float)m_rect.getScale().x / 2.0f, (float)m_rect.getScale().y / 2.0f);
    m_rect.setTexture(&ResourceHolder::get().textures.get("_fail_"));
    if (m_rect.getSize().x == 0)
        m_rect.setSize({(float)m_rect.getTexture()->getSize().x, (float)m_rect.getTexture()->getSize().y});
}

Canvas::Canvas(WidgetSize s, const sf::Texture& tex)
{
    switch (s) {
        case WidgetSize::Small32:
            m_rect.setSize({32, 32});
            break;
        case WidgetSize::Small64:
            m_rect.setSize({64, 64});
            break;
        case WidgetSize::Wide128:
            m_rect.setSize({128, 128});
            break;
        case WidgetSize::Wide256:
            m_rect.setSize({256, 256});
            break;
        case WidgetSize::Huge512:
            m_rect.setSize({512, 512});
            break;
        case WidgetSize::FullPicture:
            m_rect.setSize({0, 0});
            break;
    }
    m_rect.setOrigin((float)m_rect.getScale().x / 2.0f, (float)m_rect.getScale().y / 2.0f);
    m_rect.setTexture(&tex);
    if (m_rect.getSize().x == 0)
        m_rect.setSize({(float)m_rect.getTexture()->getSize().x, (float)m_rect.getTexture()->getSize().y});
}

void Canvas::setTexture(const sf::Texture& tex)
{
    m_rect.setTexture(&tex, true);
}

void Canvas::setTextureRect(const sf::IntRect& rectangle)
{
    m_rect.setTextureRect(rectangle);
}

void Canvas::setSize(const sf::Vector2f& size)
{
    m_rect.setSize(size);
}

void Canvas::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    (void)(window);
    (void)(e);
}

void Canvas::render(sf::RenderTarget& renderer)
{
    renderer.draw(m_rect);
}

void Canvas::setPosition(const sf::Vector2f& pos)
{
    m_rect.setPosition(pos);
}

sf::Vector2f Canvas::getPosition() const
{
    return (m_rect.getPosition());
}

sf::Vector2f Canvas::getSize() const
{
    return (m_rect.getSize());
}

}