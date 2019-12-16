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

bool verify_two(vector<int> &v){
	if(v[0] == v[1] && v[0] != v[2]){
		return true;
	}
	if(v[4] == v[5] && v[4] != v[3]){
		return true;
	}
	for(int i = 1; i < 4; i++){
		if(v[i] == v[i+1] && v[i] != v[i-1] && v[i] != v[i+2]){
			return true;
		}
	}
	return false;
}

int main(){

	int min = 353096;
	int max = 843212;

	int count = 0;

	for(int i = min; i < max; i++){
		vector<int> split = split_int(i);
		bool adj = false, inc = true;
		for(int x = 0; x < 5; x++){
			if(split[x] > split[x+1]){
				inc = false;
				break;
			}
		}
		adj = verify_two(split);
		if(adj && inc){
			count++;
		}
	}
	
	cout << count << endl;

	return 0;
}
