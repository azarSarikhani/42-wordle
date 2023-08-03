#include "../includes/wordle.hpp"
#include<iostream>

Wordle::Wordle(void)
	: guess(6),
	  keys(26, key_state::UNUSED),
	  info()
{

	for (auto& member : this->guess)
	{
		member = " _  _  _  _  _ ";
	}
	return;
}
Wordle::~Wordle(void)
{
	return;
}
