#include <iostream>
#include <fstream>
#include <set>

int partOne() {
	std::ifstream inputFile;
	inputFile.open("AOC_Dec01_input.txt");
	long total = 0;
	long delta = 0;

	if (inputFile.is_open()) {
		while (inputFile >> delta) {
			total += delta;
		}
	}
	
	inputFile.close();
	return total;
}

int partTwo() {
	std::ifstream inputFile;
	inputFile.open("AOC_Dec01_input.txt");
	long total = 0;
	long delta = 0;
	std::set<int> freqs;
	bool found = false;

	if (inputFile.is_open()) {
		while (!found) {
			while (inputFile >> delta) {
				total += delta;
				if (freqs.find(total) == freqs.end()) { //not in set
					freqs.insert(total);
				}
				else {//repeated
					found = true;
					break;
				}
			}
			inputFile.clear();
			inputFile.seekg(0, std::ios::beg);
		}
	}
	
	inputFile.close();
	return total;
}

int main() {
	std::cout << partOne() << std::endl;
	std::cout << partTwo();

	std::cin.get();
	return 0;
}