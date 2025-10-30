#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Collider
{
protected:
	Shape* hitbox_ = nullptr;

public:
	void SetPosition(Vector2f position) const;
	void SetHitbox(sf::Shape* shape, Vector2f position);
	Shape& GetHitboxRef() const;

};

