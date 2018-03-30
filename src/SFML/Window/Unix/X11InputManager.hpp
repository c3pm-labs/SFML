////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_X11INPUTMANAGER_HPP
#define SFML_X11INPUTMANAGER_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/System/String.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <X11/X.h> // Keycode
#include <X11/XKBlib.h>

namespace sf {
namespace priv {

////////////////////////////////////////////////////////////
/// \brief sf::priv::InputImpl helper
///
/// This class manage as a singleton instance the keyboard state.
/// Its purpose is to help sf::priv::InputImpl class.
///
////////////////////////////////////////////////////////////
class X11InputManager
{
public:

    ////////////////////////////////////////////////////////////
    /// \copydoc sf::Keyboard::isKeyPressed(Key)
    ///
    ////////////////////////////////////////////////////////////
    static bool isKeyPressed(sf::Keyboard::Key key);

    ////////////////////////////////////////////////////////////
    /// \copydoc sf::Keyboard::isKeyPressed(Scancode)
    ///
    ////////////////////////////////////////////////////////////
    static bool isKeyPressed(sf::Keyboard::Scancode code);

    ////////////////////////////////////////////////////////////
    /// \copydoc sf::Keyboard::localize
    ///
    ////////////////////////////////////////////////////////////
    static sf::Keyboard::Scancode unlocalize(sf::Keyboard::Key key);

    ////////////////////////////////////////////////////////////
    /// \copydoc sf::Keyboard::unlocalize
    ///
    ////////////////////////////////////////////////////////////
    static sf::Keyboard::Key localize(sf::Keyboard::Scancode code);

    ////////////////////////////////////////////////////////////
    /// \copydoc sf::Keyboard::getDescription
    ///
    ////////////////////////////////////////////////////////////
    static sf::String getDescription(Keyboard::Scancode code);

    ////////////////////////////////////////////////////////////
    /// \brief Get the sf::Keyboard::Key from XKeyEvent
    ///
    /// \param event Event from which key is gotten
    ///
    /// \return A key being pressed or released
    ///
    ////////////////////////////////////////////////////////////
    static sf::Keyboard::Key getKeyFromEvent(XKeyEvent& event);

    ////////////////////////////////////////////////////////////
    /// \brief Get the sf::Keyboard::Scancode from XKeyEvent
    ///
    /// \param event Event from which scancode is gotten
    ///
    /// \return A scancode of a key being pressed or released
    ///
    ////////////////////////////////////////////////////////////
    static sf::Keyboard::Scancode getScancodeFromEvent(XKeyEvent& event);
};

} // namespace priv

} // namespace sf

#endif // SFML_X11INPUTMANAGER_HPP
