#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> split_int(int i){
	vector<int> digits;
	while(i > 0){
		digits.push_back(i % 10);
		i /= 10;
	}
	reverse(digits.begin(), digits.end());
	return digits;
}

int main(){

	int min = 353096;
	int max = 843212;
	//int min = 355555;
	//int max = 355556;  

	int count = 0;

	for(int i = min; i < max; i++){
		vector<int> split = split_int(i);
		bool adj = false, inc = true;
		for(int x = 0; x < 5; x++){
			if(split[x] == split[x+1]){
				adj = true;
			}
			if(split[x] > split[x+1]){
				inc = false;
				break;
			}
		}
		if(adj && inc){
			count++;
		}
	}
	
	cout << count << endl;

	return 0;
}
