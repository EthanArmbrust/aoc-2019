#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

struct Asteroid{
    double angle;
    int x;
    int y;
};

#define CENTER_X 27
#define CENTER_Y 19

bool compareAst(const Asteroid &a, const Asteroid &b){
	if(a.angle == b.angle){
		return (abs(a.x - CENTER_X) + abs(a.y - CENTER_Y)) < (abs(b.x - CENTER_X) + abs(b.y - CENTER_Y));
	}
	else{
		return a.angle < b.angle;
	}
}

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

vector<Asteroid> list_asteroids(vector<string> &a, int x, int y){
    vector<Asteroid> as;
    for(int j = 0; j < a.size(); j++){
        for(int i = 0; i < a[j].length(); i++){
            if(a[j][i] == '#' && !(j == y && i == x)){
				Asteroid a = {atan2((double)(j - y), (double)(i - x)), i, j};
				as.push_back(a);
            }
        }
    }
    return as;
}

int main(){

    ifstream infile("input/10.txt");
    string s;
    vector<string> input;
    while(getline(infile,s)){
        input.push_back(s);
    }

    int center_x = CENTER_X;
    int center_y = CENTER_Y;
    int as_num = 200;

    vector<Asteroid> as = list_asteroids(input, center_x, center_y);
    sort(as.begin(), as.end(), compareAst);

    int destroyed = 0;
    int pos = 0;

    int destroy_x, destroy_y;
	double start = atan2(-1.0, 0.0);

    while(as[pos].angle < start){
		pos++;
    }

    while(destroyed < as_num){
		Asteroid current = as[pos];
		destroy_x = current.x;
		destroy_y = current.y;
		as.erase(as.begin() + pos);
		destroyed++;
		while(current.angle == as[pos].angle){
		   pos = (pos + 1) % as.size();
		}
    }

    cout << destroy_x << "," << destroy_y << endl;


    return 0;
}
