#include "../includes/wordle.hpp"
#include <string>
#include <cctype>
#include<iostream>

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
		case key_state::UNUSED:      return WHITE_BG;
		case key_state::WRONG:       return GREY_BG;
		case key_state::WRONG_PLACE: return YELLOW_BG;
		case key_state::RIGHT:       return GREEN_BG;
		default: return RESET;
	}
}

void	game_on(const std::vector<std::string>& dictionary, std::string word)
{
	Wordle game;

	for (int i = 0; i < 6;)
	{
		std::cout << "\nEnter your guess : ";
		if (!std::getline(std::cin, game.buffer))
		{
			std::cout << "\nExiting ";
			return ;
		}
		std::cout << "\033[2J";
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
				std::cout << GREEN << "Yay you win!\n";
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
	std::cout << RED << "You lost!" << std::endl;
	std::cout << "Word of the day was: " << RESET << word << std::endl;
}
