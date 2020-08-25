#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GUI/Widget.hpp"
#include "Util/NonCopyable.hpp"

namespace gui
{

class StackMenu : public NonCopyable
{
    public:
        StackMenu(const sf::Vector2f& position);

        StackMenu(StackMenu&& other);
        StackMenu& operator =(StackMenu&& other);

        ~StackMenu() = default;

        void addWidget(std::unique_ptr<Widget> w);

        void setTitle(const std::string& title);

        void handleEvent   (sf::Event e, const sf::RenderWindow& window);
        void render        (sf::RenderTarget& renderer);

    private:
        void initWidget(Widget& w);

        std::vector<std::unique_ptr<Widget>> m_widgets;
        sf::RectangleShape m_background;
        Widget::Text m_titleText;
};

}