#include "../includes/wordle.hpp"
#include<iostream>

Wordle::Wordle(void)
	: guess(6),
	  keys(26, key_state::UNUSED),
	  info()
{

	for (auto& member : this->guess)
	{
		member = " _  _  _  _  _ ";
	}
	return;
}

Wordle::~Wordle(void)
{
	return;
}

void	Wordle::display() const
{
	std::cout << "\033[2J";
	std::cout
		<< "#================================#\n"
		<< "|  _    _  _____________ _   __  |\n"
		<< "| | |  | |/   | __ \\  _ | | |  | |\n"
		<< "| | |  | | /\\ | |_ / | || | | |  |\n"
		<< "| | |/\\| | || |   /| | || | |  | |\n"
		<< "| \\  /\\  | \\/ / |\\\\| |/ | |_| |_ |\n"
		<< "|  \\/  \\/ \\__/\\_| \\|___/\\___|__/ |\n"
		<< "|                                |\n"
		<< "#================================#\n";
	std::cout << "       #=================#\n";
	std::cout << "       |                 |\n";
	for (const auto& member : guess)
	{
		std::cout << "       | " << member << " |\n";
	}
	std::cout << "       |                 |\n";
	std::cout << "       #=================#\n";
	std::cout << "#================================#\n";
	std::cout << "|                                |\n";

	std::vector<char> key_map = {
		16, 22, 4, 17, 19, 24, 20, 8, 14, 15,
		0, 18, 3, 5, 6, 7, 9, 10, 11,
		25, 23, 2, 21, 1, 13, 12
	};

	std::cout << "| ";
	std::size_t l = 0;
	while (key_map[l] != 0)
	{
		std::cout << get_color_escape(keys[key_map[l]]) << ' ' << static_cast<char>('A' + key_map[l]) << ' ' << RESET;
		++l;
	}
	std::cout << " |\n|  ";
	while (key_map[l] != 25)
	{
		std::cout << get_color_escape(keys[key_map[l]]) << ' ' << static_cast<char>('A' + key_map[l]) << ' ' << RESET;
		++l;
	}
	std::cout << "   |\n|     ";
	while (l != key_map.size())
	{
		std::cout << get_color_escape(keys[key_map[l]]) << ' ' << static_cast<char>('A' + key_map[l]) << ' ' << RESET;
		++l;
	}
	std::cout << RESET << "      |\n";
	std::cout << "|                                |\n";
	std::cout << "#================================#\n";
}
