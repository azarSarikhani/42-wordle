#include "../includes/wordle.hpp"
#include <string>
#include <cctype>
#include<iostream>

#define GREEN  "\e[0;32m"
#define YELLOW "\e[0;33m"
#define WHITE   "\e[0m"

std::string	get_letter_color(char letter, std::size_t index, std::string& sample)
{
	for (std::size_t i = 0; i < sample.size(); ++i) {
		if (letter == sample[i])
		{
			sample[i] = 0;
			if (i == index)
				return std::string(GREEN);
			else
				return std::string(YELLOW);
		}
	}
	return std::string(WHITE);
}

void	game_on(const std::vector<std::string>& dictionary, std::string word)
{
	Guesses guess;

	for (int i = 0; i < 6;)
	{
		std::cout << '\n';
		for (const auto& member: guess.guess)
		{
			std::cout << member << std::endl;
		}
		printf("Enter your guess : \n");
		std::getline(std::cin, guess.buffer);
		for (auto& letter: guess.buffer)
		{
			letter = std::toupper(letter);
		}
		if (word_is_valid(guess.buffer) && word_is_in_dict(guess.buffer, dictionary))
		{
			std::string new_line;
			std::string copy = word;

			for (std::size_t c = 0; c < guess.buffer.size(); ++c) 
			{
				std::string color = get_letter_color(guess.buffer[c], c, copy);
				new_line += color + (char)std::toupper(guess.buffer[c]) + ' ';
			}
			new_line += WHITE;
			guess.guess[i] = new_line;

			if (guess.buffer == word)
			{
				for (const auto& member: guess.guess)
				{
					std::cout << member << std::endl;
				}
				printf("Yay you win\n");
				return ;
			} 
			
			++i;
		}

	}
	std::cout << "You lost!" << std::endl;
	std::cout << " Word of the day was: " << word << std::endl;
}
