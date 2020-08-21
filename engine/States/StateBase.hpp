#pragma once

#include <SFML/Graphics.hpp>
#include "Util/NonCopyable.hpp"

class Game;

class StateBase : public NonCopyable
{
    public:
        StateBase(Game& game)
            : m_pGame(&game)
        {}

        virtual ~StateBase() = default;

        virtual void handleEvent(sf::Event e) {(void)e;}
        virtual void handleInput() = 0;
        virtual void update(sf::Time deltaTime) {(void)deltaTime;}
        virtual void fixedUpdate(sf::Time deltaTime) {(void)deltaTime;}
        virtual void render(sf::RenderTarget& renderer) = 0;

    protected:
        Game* m_pGame;
};
