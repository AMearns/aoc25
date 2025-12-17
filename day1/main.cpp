#include <iostream>
#include <fstream>
#include <cmath>

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

		for (int i = 0; i < abs(n); i++) {
			if (n < 0) {
				dial--;
		    	} else {
				dial++;
		    	}

			if (dial < 0) {
				dial += 100;
		    	} else if (dial >= 100) {
				dial -= 100;
		    	}

		    	if (dial == 0) {
				zeroCount++;
		    	}
		}
	}
	InputFile.close(); 
	cout << zeroCount << endl;

	return 0;
}
