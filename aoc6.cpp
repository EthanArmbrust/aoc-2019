#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Planet{
	string name;
	vector<string> children;
};

bool operator<(const Planet& lhs, const Planet& rhs){
	return lhs.name < rhs.name;
}

int main(){

	ifstream infile("input/6.txt");
	string s;
	vector<Planet> planets;
	while(getline(infile,s)){
		Planet p = {s.substr(0, 3), {s.substr(4,3)}};
		auto it = lower_bound(planets.begin(), planets.end(), p);
		if(*it->name == p.name){
			*it->children.push_back(p.children[0]);
		}
		else{
			planets.insert(it, p);
		}
	}

	for(auto p : planets){
		cout << p.name << endl;
	}
	
	return 0;
}
