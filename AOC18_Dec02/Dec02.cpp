#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int partOne() {
		std::ifstream inputFile;
		inputFile.open("AOC_Dec02_input.txt");
		std::string boxID = "";

		long two = 0;
		long three = 0;

		while (inputFile >> boxID) {
			std::vector<char> letters(boxID.begin(), boxID.end());
			std::map<std::string, int> letterCounts;
			
			//for each letter of the string
			for (char c : letters) {
				//char to string
				std::string st = std::string(1, c);

				if (letterCounts.find(st) == letterCounts.end()) {
					letterCounts.emplace(st, 1);
				}
				else {//already in the map
					letterCounts.at(st) += 1;
				}
			}

			auto it = letterCounts.begin();
			bool twoFound = false;
			bool threeFound = false;

			while (it != letterCounts.end()) {
				if (it->second == 2 && !twoFound) {
					two++;
					twoFound = true;
				}
				if (it->second == 3 && !threeFound) {
					three++;
					threeFound = true;
				}
				it++;
			}
		}

		inputFile.close();
		return two * three;
}

std::string partTwo() {
	std::ifstream inputFile;
	inputFile.open("AOC_Dec02_input.txt");
	std::string word = "";
	std::vector<std::vector<char>> listOfWords;

	while (inputFile >> word) {
		std::vector<char> letters(word.begin(), word.end());
		listOfWords.push_back(letters);
	}
	
	for (auto eachWord : listOfWords) {
		auto wordIt = listOfWords.begin();
		
		while (wordIt != listOfWords.end()) {
			std::vector<char> currentWord = *(wordIt);
		
			bool offByOne = false;
			bool offByMore = false;

			for (int i = 0; i < eachWord.size(); i++) {
				if (eachWord[i] != currentWord[i] && !offByOne) {
					offByOne = true;
				}
				else if (eachWord[i] != currentWord[i] && offByOne) {
					offByMore = true;
					break;
				}
			}

			if (offByOne && !offByMore) {
				inputFile.close();
				return std::string(eachWord.begin(), eachWord.end()) 
					+ "\n" + std::string(currentWord.begin(), currentWord.end());
			}
			wordIt++;
		}
	}
}

int main() {
	std::cout << partOne() << std::endl;
	std::cout << partTwo();
	std::cin.get();
	return 0;
}