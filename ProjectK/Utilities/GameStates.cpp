#include "GameStates.hpp"

void GameStates::LoadGameStates(void)
{
	const char* stateList[NB_STATES] =
	{
		"MENU",
		"GAME",
		"PAUSE"
	};

	for (auto stateID = 0; stateID < NB_STATES; stateID++)
	{
		gameState->push_back(stateList[stateID]);
	}


	font.loadFromFile("assets/fonts/StateFont.ttf");
	auto initializeText = [&](sf::Text& _text, int _characterSize, const sf::Color& _color, const sf::Vector2f& _position, const std::string& _string = "")
	{
		_text.setFont(font);
		_text.setCharacterSize(_characterSize);
		_text.setFillColor(_color);
		_text.setPosition(_position);
		_text.setString(_string);
	};

	initializeText(text, 50, sf::Color::Yellow, sf::Vector2f(SCREEN_WIDTH/2.f - 50.f, 0.f), gameState->front());
}
std::string GameStates::GetCurrentState(void) const
{
	return gameState->front();
}
void GameStates::DisplayGameStateList(void) const
{
	for (const auto& list : *gameState)
	{
		std::cout << list << std::endl;
	}
}
void GameStates::SetCurrentState(const std::string& _state)
{
	std::vector<std::string>::iterator itr;
	itr = std::find(gameState->begin(), gameState->end(), _state);

	if (itr != gameState->end())
	{
		std::swap(gameState->front(), *itr);
	}
}
void GameStates::AddState(const std::string& _state)
{
	gameState->push_back(_state);
}
void GameStates::RemoveState(const std::string& _state)
{
	std::vector<std::string>::iterator itr;
	itr = std::find(gameState->begin(), gameState->end(), _state);

	if (itr != gameState->end())
	{
		gameState->erase(itr);
		gameState->shrink_to_fit();

	}
}
#pragma region constructors
GameStates::GameStates()
	: gameState{ nullptr }
{
	gameState = new std::vector<std::string>;
	std::cout << "\033[6;1;31mDefault\033[0m constructor for GameStates called !!" << std::endl;
}
GameStates::~GameStates()
{
	if (gameState != nullptr)
	{
		delete gameState;
		gameState = nullptr;
	}

	std::cout << "\033[6;1;34mDeconstructor\033[0m for GameStates called !!" << std::endl;
}
#pragma endregion