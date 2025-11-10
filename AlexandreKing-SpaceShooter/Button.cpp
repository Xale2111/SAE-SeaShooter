#include "Button.h"

#include <SFML/Graphics/RenderTarget.hpp>

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape_,states);
	if (text_.has_value())
	{
		target.draw(text_.value());
	}

}

void Button::HandleInput(const std::optional<sf::Event>& event)
{
    if (isMouseHover_)
    {
        if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
        {
            isPressed_ = true;
        }
        if (const auto* mouse = event->getIf<sf::Event::MouseButtonReleased>())
        {
            isPressed_ = false;
            hasBeenPressed_ = true;
        }
    }
    else
    {
        isPressed_ = false;
    }
}

bool Button::CheckHover(sf::Vector2f mousePosition)
{
    if (shape_.getGlobalBounds().contains(mousePosition))
    {
        isMouseHover_ = true;
    }
    else
    {
        isMouseHover_ = false;
    }

    return  isMouseHover_;
}

void Button::HandleState()
{
    if (isMouseHover_)
    {
        if (isPressed_)
        {
            shape_.setFillColor(pressColor_);
        }
        else
        {
            shape_.setFillColor(hoverColor_);
        }
    }
    else
    {
        shape_.setFillColor(fillColor_);
    }
}

bool Button::HasBeenPressed()
{
    return hasBeenPressed_;
}

void Button::SetText(std::string text)
{
	textValue_ = text;
}

void Button::SetSize(sf::Vector2f size)
{
	shape_.setSize(size);
    shape_.setOrigin(sf::Vector2f(size.x/2,size.y/2));
}

void Button::SetFillColor(sf::Color color)
{
    fillColor_ = color;
}

void Button::SetHoverColor(sf::Color color)
{
    hoverColor_ = color;
}

void Button::SetPressColor(sf::Color color)
{
    pressColor_ = color;
}

void Button::SetFontSize(int size)
{
}

void Button::SetPosition(sf::Vector2f position)
{
	shape_.setPosition(position);
}

void Button::SetActionCode(int action)
{
    actionCode_ = action;
}

int Button::GetActionCode()
{
    return actionCode_;
}


