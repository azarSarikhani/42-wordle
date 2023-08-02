#include "../includes/wordle.hpp"
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
    char word[6] = "weary";
    word[6] = 0;
    game_on(word);
}
