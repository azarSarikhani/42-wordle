#pragma once

#include<stdio.h>
#include<string>
#include<vector>

#define DICTIONARY_PATH "words.txt"

bool word_is_valid(const std::string& word);

std::string	load_word(const std::string& dictionary_path);

class Guesses
{
public:
	std::vector<std::string> guess;
	std::string	buffer;
	Guesses(void);
	~Guesses(void);
};

void	game_on(std::string word);
