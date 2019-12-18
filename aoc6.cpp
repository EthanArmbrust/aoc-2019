#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Planet{
	string name;
	vector<string> children;
	int count;
	string parent;
};

bool operator<(const Planet& lhs, const Planet& rhs){
	return lhs.name < rhs.name;
}
bool operator<(const Planet& lhs, const string& rhs){
	return lhs.name < rhs;
}
bool operator<(const string& lhs, const Planet& rhs){
	return lhs < rhs.name;
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

string findParent(vector<Planet> &planets, const string &child){
	for(auto &p : planets){
		for(auto &c : p.children){
			if(c == child){
				return p.name;
			}
		}
	}
	return "NO_PARENT_FOUND";
}

string commonAncestor(vector<string> lhs, vector<string> rhs){
	reverse(lhs.begin(), lhs.end());
	reverse(rhs.begin(), rhs.end());

	for(int i = 0; i < lhs.size(); i++){
		if(lhs[i] != rhs[i]){
			return lhs[i - 1];
		}
	}
}

vector<string> getAncestryTree(vector<Planet> &planets, const string &child){
	vector<string> ans;
	auto it = lower_bound(planets.begin(), planets.end(), child);
	while(it->parent != "NO_PARENT_FOUND"){
		ans.push_back(it->parent);
		it = lower_bound(planets.begin(), planets.end(), it->parent);
	}
	return ans;
}


void countOrbits(vector<Planet> &planets, const string& root, int &sum, int depth){
	auto it = lower_bound(planets.begin(), planets.end(), root);
	it->count++;
	set<string> st(it->children.begin(), it->children.end());
	it->children.assign(st.begin(), st.end());
	for(auto &c : it->children){
		sum += depth + 1;
		countOrbits(planets, c, sum, depth + 1);
	}
	return;
}

int main(){

	ifstream infile("input/6.txt");
	string s;
	vector<Planet> planets;
	while(getline(infile,s)){
		Planet p = {s.substr(0, 3), {s.substr(4,3)}, 0, ""};
		Planet p2 = {s.substr(4,3), {}, 0, ""};
		if(planets.size() > 0){
			auto it = lower_bound(planets.begin(), planets.end(), p);
			int idx = it - planets.begin();
			if(planets[idx].name == p.name){
				move(p.children.begin(), p.children.end(), back_inserter(planets[idx].children));
			}
			else{
				planets.insert(it, p);
			}
		}
		else{
			planets.push_back(p);
		}
		auto it = lower_bound(planets.begin(), planets.end(), p2);
		int idx = it - planets.begin();
		if(planets[idx].name == p2.name){
			move(p2.children.begin(), p2.children.end(), back_inserter(planets[idx].children));
		}
		else{
			planets.insert(it, p2);
		}
	}
	int sum = 0;
	string root = findRoot(planets);
	countOrbits(planets, root, sum, 0);

	cout << "Part 1: " << sum << endl;

	//add on parents
	for(auto &p : planets){
		p.parent = findParent(planets, p.name);
	}

	//get ancestry tree
	vector<string> you = getAncestryTree(planets, "YOU");
	vector<string> san = getAncestryTree(planets, "SAN");


	string com = commonAncestor(you, san);
	int you_dist = 0, san_dist = 0;
	for(int i = 0; i < you.size(); i++){
		if(you[i] == com){
			you_dist = i;
			break;
		}
	}
	for(int i = 0; i < san.size(); i++){
		if(san[i] == com){
			san_dist = i;
			break;
		}
	}
	
	cout << "Part 2: "<< you_dist + san_dist << endl;	
	
	return 0;
}
