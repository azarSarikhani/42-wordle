#pragma once

#include <stdio.h>
#include <string>

#define DICTIONARY_PATH "words.txt"

bool word_is_valid(const std::string& word);

std::string	load_word(const std::string& dictionary_path);

void	game_on(char word);
