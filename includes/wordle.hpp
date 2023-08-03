#pragma once

#include <stdio.h>
#include <string>
#include <vector>

#define DICTIONARY_PATH "words.txt"

#define RED    "\e[0;31m"
#define GREEN  "\e[0;32m"
#define GREY_BG   "\e[0;37m"
#define GREEN_BG  "\e[0;30;42m"
#define YELLOW_BG "\e[0;30;43m"
#define WHITE_BG  "\e[0;30;47m"

#define RESET  "\e[0m"

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

	void display();

	std::vector<std::string> guess;
	std::vector<key_state> keys;
	std::string	buffer;
	std::string	info;
};

void	game_on(const std::vector<std::string>& dictionary, std::string word);

bool word_is_valid(const std::string& word);
bool word_is_in_dict(const std::string& word, const std::vector<std::string>& dictionary);

key_state	get_letter_color(char letter, std::size_t index, std::string& sample);
std::string	get_color_escape(key_state state);

std::vector<std::string>	load_dictionary(const std::string& path);
std::string get_word_of_day(const std::vector<std::string>& dictionary);
