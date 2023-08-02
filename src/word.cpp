#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>

bool word_is_valid(const std::string& word)
{
	if (word.size() != 5) {
		
		printf("Word too short\n");
		return false;
	}
	for (auto letter : word) {
		if (!std::isalpha(letter)) {
			printf("Invalid character\n");
			return false;
		}
	}
	return true;
}

bool word_is_in_dict(const std::string& word, const std::vector<std::string>& dictionary)
{
	for (const auto& entry : dictionary)
	{
		if (word == entry)
		{
			return true;
		}
	}
	std::cout << "Word is not in dict\n";
	return false;
}

std::vector<std::string>	load_dictionary(const std::string& path)
{
	std::ifstream file(path);
	std::vector<std::string> word_list(0);

	if (!file) {
		std::perror("Failed to load dictionary");
		return word_list;
	}

	std::string	line;
	while (std::getline(file, line)) {
		if (word_is_valid(line)) {
			word_list.push_back(line);
		} else {
			std::cerr << line << " is an invalid word.\n";
		}
	}

	return word_list;
}

std::string get_word_of_day(const std::vector<std::string>& dictionary)
{
	using days_t = std::chrono::duration<int, std::ratio<60 * 60 * 24>>;

	auto time_point = std::chrono::system_clock::now();
	auto days = std::chrono::duration_cast<days_t>(time_point.time_since_epoch());

	std::mt19937 random(static_cast<std::mt19937::result_type>(days.count()));

	std::uniform_int_distribution<int> distribution(0, dictionary.size());

	return dictionary[distribution(random)];
}
