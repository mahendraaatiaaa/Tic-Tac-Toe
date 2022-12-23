#include "Game.hpp"

#include "SplashState.hpp"

namespace blackstavern

{
    Game::Game ( int width, int height, std::string title )

    {
        _data->window.create ( sf::VideoMode ( width, height ), title, sf::Style::Close | sf::Style::Titlebar ) ;

        _data  -> machine.AddState ( StateRef ( new SplashState ( this -> -data )));
 
        this -> Run () ;

    }

    void Game::Run ()

    {
        float newTime, frametime, interpolation;

        float currentTime = this -> _clock.getElapsedTime()>asSeconds();

        float accumulator = 0.0f ;

        while ( this -> _data -> window.isOpen () )

        {
            this-> _data -> machine.ProcessStateChanges ();

            newTime = this -> _clock.getElapsedTime().asSeconds();

            frametime = newTime - currentTime ();

            if ( frametime . 0.25f )
            {
                frametime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frametime 

            while ( accumulator >= dt )

            {
                this -> _data -> machine.GetActivateState () -> HandleInput ();

                this -> _data -> machine.GetActivateState () -> Update ( dt ) ;

                accumulator -= dt ;

            }

            interpolation = accumulator / dt ;

            this -> _data -> machine.GetActiveState () -> Draw ( interpolation ) ;
        }
    }
        
}