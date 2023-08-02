#include "../includes/wordle.hpp"
#include <string>
#include <cctype>
#include<iostream>

void	game_on(std::string word)
{
	
	Guesses guess;

	for(int i = 0; i < 6; i++)
	{
		for (const auto& member: guess.guess)
		{
			std::cout << member << std::endl;
		}
		printf("Enter your guess : \n");
		std::getline(std::cin, guess.buffer);
		if (guess.buffer.length() != 5)
		{
			printf("Your guess must be 5 char long\n");
			i--;
		}
		else
		{
			if (!word_is_valid(guess.buffer))
			{
				printf("Your guess must be all alphabetical characters.\n");
				i--;
			}

			else
				if (guess.buffer == word)
				{
					printf("Yay you win\n");
					return ;
				}
				else
				{
					int index = 0;
					for (auto letter_buf : guess.buffer) 
					{
						guess.guess[i][index++] = letter_buf;
						guess.guess[i][index++] = ' ';
					}
				} 
		}

	}
	std::cout << "You lost!" << std::endl;
	std::cout << " Word of the day was: " << word << std::endl;
}