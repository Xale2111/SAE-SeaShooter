#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

class Button : public sf::Drawable
{
private:
	sf::RectangleShape shape_;
	std::optional<sf::Text> text_;

	sf::Texture* icon_ = nullptr;

	sf::Color fillColor_;
	sf::Color pressColor_;
	sf::Color hoverColor_;

	bool isPressed_ = false;
	bool hasBeenPressed_ = false;
	bool isMouseHover_ = false;

	int actionCode_;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	void HandleInput(const std::optional<sf::Event>& event);
	bool CheckHover(sf::Vector2f mousePosition);
	void HandleState();

	bool HasBeenPressed();
	void ResetPressState();

	void SetText(std::string text);
	void SetSize(sf::Vector2f size);
	void SetFillColor(sf::Color color);
	void SetHoverColor(sf::Color color);
	void SetPressColor(sf::Color color);
	void SetPosition(sf::Vector2f position);
	void SetOutline(int size, sf::Color color);

	void SetIcon(std::string path);

	void SetFont(sf::Font& font,int size);
	void SetFontColor(sf::Color color);

	void SetActionCode(int action);
	int GetActionCode();
};

