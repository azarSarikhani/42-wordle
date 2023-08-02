#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>

bool word_is_valid(const std::string& word)
{
	if (word.size() != 5) {
		return false;
	}
	for (auto letter : word) {
		if (!std::islower(letter)) {
			return false;
		}
	}
	return true;
}

std::string load_word(const std::string& dictionary_path)
{
	std::ifstream file(dictionary_path);

	if (!file) {
		std::perror("Failed to load dictionary");
		return "";
	}

	std::string	line;
	std::vector<std::string> word_list;
	while (std::getline(file, line)) {
		if (word_is_valid(line)) {
			word_list.push_back(line);
		} else {
			std::cerr << line << " is an invalid word.\n";
		}
	}

	if (word_list.empty()) {
		return "";
	}

	using days_t = std::chrono::duration<int, std::ratio<60 * 60 * 24>>;

	auto time_point = std::chrono::system_clock::now();
	auto days = std::chrono::duration_cast<days_t>(time_point.time_since_epoch());

	std::mt19937 random(static_cast<std::mt19937::result_type>(days.count()));

	std::uniform_int_distribution<int> distribution(0, word_list.size());

	return word_list[distribution(random)];
}
