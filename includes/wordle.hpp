#pragma once

#include<stdio.h>
#include<string>
#include<vector>

#define DICTIONARY_PATH "words.txt"

bool word_is_valid(const std::string& word);
bool word_is_in_dict(const std::string& word, const std::vector<std::string>& dictionary);

std::vector<std::string>	load_dictionary(const std::string& path);
std::string get_word_of_day(const std::vector<std::string>& dictionary);

class Guesses
{
public:
	std::vector<std::string> guess;
	std::string	buffer;
	Guesses(void);
	~Guesses(void);
};

void	game_on(const std::vector<std::string>& dictionary, std::string word);
