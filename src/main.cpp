#include "../includes/wordle.hpp"
#include<iostream>
// app loop
// 	main menu
// 	load dictionary
// 	pick word of the day
// 	validate word of the day
// 	loop max 6 times:
// 		display guesses
// 		prompt input
// 		validate input
// 		colorize input
// 		if all right
// 			quit

int main()
{

    std::string word = load_word(DICTIONARY_PATH);
    game_on(word);
}
