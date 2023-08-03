#include "../includes/wordle.hpp"
#include <string>
#include <cctype>
#include<iostream>

#define GREY   "\e[0;37m"
#define GREEN  "\e[0;30;42m"
#define YELLOW "\e[0;30;43m"
#define WHITE  "\e[0;30;47m"
#define RESET  "\e[0m"

key_state	get_letter_color(char letter, std::size_t index, std::string& sample)
{
	for (std::size_t i = 0; i < sample.size(); ++i) {
		if (letter == sample[i])
		{
			sample[i] = 0;
			if (i == index)
				return key_state::RIGHT;
			else
				return key_state::WRONG_PLACE;
		}
	}
	return key_state::WRONG;
}

std::string	get_color_escape(key_state state)
{
	switch (state)
	{
		case key_state::UNUSED:      return WHITE;
		case key_state::WRONG:       return GREY;
		case key_state::WRONG_PLACE: return YELLOW;
		case key_state::RIGHT:       return GREEN;
		default: return RESET;
	}
}

void	Wordle::display() const
{
	std::cout << "\n       #=================#\n";
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

void	game_on(const std::vector<std::string>& dictionary, std::string word)
{
	Wordle game;

	for (int i = 0; i < 6;)
	{
		std::cout << "\nEnter your guess : ";
		std::getline(std::cin, game.buffer);
		std::cout << '\n';
		for (auto& letter: game.buffer)
		{
			letter = std::toupper(letter);
		}
		if (!word_is_valid(game.buffer))
		{
			game.info = "Word should be 5 alphabetical characters";
		}
		else if (!word_is_in_dict(game.buffer, dictionary))
		{
			game.info = "Word is not in dictionary";
		}
		else
		{
			std::string new_line;
			std::string copy = word;

			for (std::size_t c = 0; c < game.buffer.size(); ++c) 
			{
				key_state current = get_letter_color(game.buffer[c], c, copy);
				if (current > game.keys[game.buffer[c] - 'A'])
				{
					game.keys[game.buffer[c] - 'A'] = current;
				}
				std::string color = get_color_escape(current);
				new_line += color + ' ' + (char)std::toupper(game.buffer[c]) +  ' ' + RESET;
			}
			new_line += RESET;
			game.guess[i] = new_line;

			if (game.buffer == word)
			{
				game.display();
				printf("Yay you win\n");
				return ;
			} 
			
			++i;
		}
		game.display();
		if (!game.info.empty())
		{
			std::cout << '\n' << game.info;
			game.info.clear();
		}
	}
	game.display();
	std::cout << "You lost!" << std::endl;
	std::cout << "Word of the day was: " << word << std::endl;
}
