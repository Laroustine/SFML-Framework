#include "GUI/StackMenu.hpp"
#include "ResourceManager/ResourceHolder.hpp"

namespace gui
{

StackMenu::StackMenu(const sf::Vector2f& position)
{
    m_background.setSize({300, 20});
    m_background.setOrigin({150, 0});
    m_background.setFillColor({100, 100, 100, 128});
    m_background.setOutlineThickness(5);
    m_background.setOutlineColor({40, 40, 40, 255});
    m_background.setPosition(position);

    m_titleText.setPosition(position.x, position.y - 14);
    m_titleText.setOutlineColor(sf::Color::Black);
    m_titleText.setOutlineThickness(1);
    m_titleText.setCharacterSize(18);
}

StackMenu::StackMenu(StackMenu&& other)
:   m_widgets       (std::move(other.m_widgets))
,   m_background    (std::move(other.m_background))
{
}

StackMenu& StackMenu::operator=(StackMenu&& other)
{
    m_widgets       =   std::move(other.m_widgets);
    m_background    =   std::move(other.m_background);

    return *this;
}

void StackMenu::addWidget(std::unique_ptr<Widget> w)
{
    initWidget(*w);
    m_widgets.push_back(std::move(w));
}

void StackMenu::initWidget(Widget& widget)
{
    sf::Vector2f pos = m_background.getPosition();
    sf::Vector2f size = m_background.getSize();

    widget.setPosition({pos.x - widget.getSize().x / 2, pos.y});
    pos.y += widget.getSize().y + 20;
    size.y += widget.getSize().y + 20;
    if (widget.getSize().x > size.x)
        size.x = widget.getSize().x + 44;
    m_background.setSize(size);
    m_background.setOrigin({(float)size.x / 2, size.y});
    m_background.setPosition(pos);
}

void StackMenu::setTitle(const std::string & title)
{
    m_titleText.setString(title);
    m_titleText.setOrigin(m_titleText.getGlobalBounds().width  / 2.0f, m_titleText.getGlobalBounds().height / 2);
}

void StackMenu::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    for (std::unique_ptr<gui::Widget>& widget : m_widgets) {
        widget->handleEvent(e, window);
    }
}

void StackMenu::render(sf::RenderTarget& renderer)
{
    renderer.draw(m_background);
    for (std::unique_ptr<gui::Widget>& widget : m_widgets) {
        widget->render(renderer);
    }
    renderer.draw(m_titleText);
}

}