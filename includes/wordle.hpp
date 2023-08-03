#pragma once

#include<stdio.h>
#include<string>
#include<vector>

#define DICTIONARY_PATH "words.txt"

bool word_is_valid(const std::string& word);
bool word_is_in_dict(const std::string& word, const std::vector<std::string>& dictionary);

std::vector<std::string>	load_dictionary(const std::string& path);
std::string get_word_of_day(const std::vector<std::string>& dictionary);

enum class key_state
{
	UNUSED = 0,
	WRONG,
	WRONG_PLACE,
	RIGHT
};

class Wordle
{
public:
	Wordle();
	~Wordle();

	void display() const;

	std::vector<std::string> guess;
	std::vector<key_state> keys;
	std::string	buffer;
	std::string	info;
};

void	game_on(const std::vector<std::string>& dictionary, std::string word);
