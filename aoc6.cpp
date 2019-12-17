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

string findRoot(vector<Planet> &planets){
	for(auto p : planets){
		bool foundParent = false;
		for(int i = 0; i < planets.size(); i++){
			for(auto c : planets[i].children){
				if(p.name == c){
					foundParent = true;
					break;
				}
			}
			if(foundParent){
				break;
			}
		}
		if(!foundParent){
			return p.name;
		}
	}
	return "NO_ROOT_FOUND";
}

int main(){

	ifstream infile("input/6.txt");
	string s;
	vector<Planet> planets;
	while(getline(infile,s)){
		Planet p = {s.substr(0, 3), {s.substr(4,3)}};
		if(planets.size() > 0){
			auto it = lower_bound(planets.begin(), planets.end(), p);
			int idx = it - planets.begin();
			if(planets[idx].name == p.name){
				planets[idx].children.push_back(p.children[0]);
			}
			else{
				planets.insert(it, p);
			}
		}
		else{
			planets.push_back(p);
		}
	}
	cout << findRoot(planets) << endl;
	
	return 0;
}
