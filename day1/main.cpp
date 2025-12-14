#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	string input;
	ifstream InputFile("input");
	int dial = 50;
	int zeroCount = 0;

	while (getline (InputFile, input)) {
		if (input[0] == 'L') {
			input.replace(0, 1, "-");
		} else {
			input.replace(0, 1, "");
		}

		int n = stoi(input);
		dial = (((dial + n) % 100) + 100) % 100;

		if (dial == 0) {
			zeroCount++;
		}
	}
	InputFile.close(); 

	cout << zeroCount << endl;

	return 0;
}
