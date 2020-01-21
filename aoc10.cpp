#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int compute_asteroids(vector<string> &a, int x, int y){
    set<double> angles;
    for(int j = 0; j < a.size(); j++){
        for(int i = 0; i < a[j].length(); i++){
            if(a[j][i] == '#'){
                angles.insert(atan2((double)(j - y), (double)(i - x)));
            }
        }
    }
    return angles.size();
}

int main(){

    ifstream infile("input/10.txt");
    string s;
    vector<string> input;
    while(getline(infile,s)){
        input.push_back(s);
    }

    int max_ass = 0;
    int x, y;
    for(int j = 0; j < input.size(); j++){
        for(int i = 0; i < input[j].length(); i++){
            if(input[j][i] == '#'){
		int temp = max_ass;
                max_ass = max(max_ass, compute_asteroids(input, i, j));
		if(max_ass != temp){
		    x = i; y = j;
		}
            }
        }
    }

    cout << max_ass << endl;
    cout << x << "," << y << endl;

    return 0;
}
