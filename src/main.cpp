#include "../includes/wordle.hpp"
#include<iostream>

int main()
{
	std::vector<std::string> dictionary = load_dictionary(DICTIONARY_PATH);

	if (dictionary.empty())
	{
		return 1;
	}

    std::string word = get_word_of_day(dictionary);
    game_on(dictionary, word);

    return 0;
}
