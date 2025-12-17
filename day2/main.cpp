#include <vector> 
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main() {

	//vector<string> numbers = {"11-22","95-115","998-1012","1188511880-1188511890","222220-222224","1698522-1698528","446443-446449","38593856-38593862","565653-565659","824824821-824824827","2121212118-2121212124"};

	ifstream file("input");
	string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

	vector<string> numbers;
    
	stringstream ss(data);
	string segment;

	while (getline(ss, segment, ',')) {
		numbers.push_back(segment);
	}

	long long invalidIDSum = 0;

	for (string range : numbers) {
		stringstream ss(range);
		long long start, end;
		char dash;

		ss >> start >> dash >> end; 

		for (long long i = start ; i <= end; i++) {
			string number = to_string(i);
			int numberLen = number.length(); 
	    
			if (numberLen % 2 == 0) {
				int half = numberLen / 2;
				string firstHalf = number.substr(0, half); 
				string secondHalf = number.substr(half); 
				if (firstHalf == secondHalf) {
					invalidIDSum += i;
				}
			}
		}
	}

	cout << invalidIDSum << endl;

	return 0;
}
