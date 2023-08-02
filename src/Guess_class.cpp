#include "../includes/wordle.hpp"
#include<iostream>

Guesses::Guesses(void) : guess(6)
{
	for (auto& member : this->guess)
	{
		member = "_ _ _ _ _ ";
	}
	return;
}
Guesses::~Guesses(void)
{
	return;
}