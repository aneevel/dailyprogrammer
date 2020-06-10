#include <iostream>
#include <string>

bool matches(std::string necklaceOne, std::string necklaceTwo) {

	std::cout << "Comparing strings \"" << necklaceOne << "\" and \"" << necklaceTwo << "\"" << std::endl;
	
	// Strings of differing lengths will never match
	if (necklaceOne.length() != necklaceTwo.length()) {
		return false;
	}

	// Perform up to necklaceTwo.length() rotations
	for (int i = 0; i < necklaceTwo.length(); i++) {
		
		// Shift i letters 
		if (necklaceOne == (necklaceTwo.substr(i, necklaceTwo.length() - i) + necklaceTwo.substr(0, i))) {
			return true;
		}
	}

	return false;
}

int main(int argc, char** argv) {

	if (argc != 3) {
		std::cout << "Provide the system with 2 strings to compare." << std::endl;	
		return 1;
	}

	if (matches(argv[1], argv[2])) {
		std::cout << "\"" << argv[1] << "\" and \"" << argv[2] << "\" match" << std::endl;
	}

	return 0;
}
