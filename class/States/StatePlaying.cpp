#include <iostream>
#include "States/StatePlaying.hpp"
#include "GUI/Button.hpp"
#include "GUI/Textbox.hpp"
#include "Game.hpp"

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
,   m_TestMenu  (game.getWindow(), 50)
{
    std::unique_ptr<gui::Button> b = std::make_unique<gui::Button>();
    b->setText("Button 1");
    b->setFunction([]() {
        std::cout << "Button 1 clicked!" << '\n';
    });

    m_TestMenu.addWidget(std::move(b));
}

void StatePlaying::handleEvent(sf::Event e)
{
    m_TestMenu.handleEvent(e, m_pGame->getWindow());
}

void StatePlaying::handleInput()
{

}

void StatePlaying::update(sf::Time deltaTime)
{
    (void)deltaTime;
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{
    (void)deltaTime;
}

void StatePlaying::render(sf::RenderTarget& renderer)
{
    m_TestMenu.render(renderer);
}
