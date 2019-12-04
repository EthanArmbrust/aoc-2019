#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <climits>
#include <cstdlib>

using namespace std;

struct Point{
	int x;
	int y;
	int dist;
};

bool operator==(const Point& lhs, const Point& rhs){
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator<(const Point& lhs, const Point& rhs){
	if(lhs.x == rhs.x){
		return lhs.y < rhs.y;
	}
	else return lhs.x < rhs.x;
}

bool operator>(const Point& lhs, const Point& rhs){
	if(lhs.x == rhs.x){
		return lhs.y > rhs.y;
	}
	else return lhs.x > rhs.x;
}

vector<Point> plot_wire(vector<string> &line){
	vector<Point> wire1 = {{0,0}};
	int distance = 0;
	for(auto s : line){
		int mag = stoi(s.substr(1));
		switch(s[0]){
			case 'U':
				for(int i = 0; i < mag; i++){
					auto prev = wire1.back();
					wire1.push_back({prev.x, prev.y + 1, ++distance});
				}
				break;
			case 'D':
				for(int i = 0; i < mag; i++){
					auto prev = wire1.back();
					wire1.push_back({prev.x, prev.y - 1, ++distance});
				}
				break;
			case 'L':
				for(int i = 0; i < mag; i++){
					auto prev = wire1.back();
					wire1.push_back({prev.x - 1, prev.y, ++distance});
				}
				break;
			case 'R':
				for(int i = 0; i < mag; i++){
					auto prev = wire1.back();
					wire1.push_back({prev.x + 1, prev.y, ++distance});
				}
				break;
		}
	}
	return wire1;
}

vector<Point> intersections(vector<Point> &wire1, vector<Point> &wire2){
	vector<Point> inter;
	sort(wire2.begin(), wire2.end());
	for(auto p : wire1){
		if(binary_search(wire2.begin(), wire2.end(), p)){
			int it = lower_bound(wire2.begin(), wire2.end(), p) - wire2.begin();
			Point temp = p;
			temp.dist += wire2[it].dist;
			inter.push_back(temp);
		}
	}

	return inter;
}

int main(){
	
	ifstream infile("input/3.txt");
	string s;
	vector<vector<string>> input;

	while(getline(infile,s )){
		vector<string> line;
		stringstream ss(s);
		string temp;

		while(getline(ss, temp, ',')){
			line.push_back(temp);
		}
		input.push_back(line);
	}


	Point center = {0,0};
	vector<Point> wire1 = plot_wire(input[0]);
	cout << "wire 1 made " << wire1.size() << endl;
	vector<Point> wire2 = plot_wire(input[1]);
	cout << "wire 2 made " << wire1.size() << endl;
	vector<Point> inter = intersections(wire1, wire2);
	cout << "intersections made" << endl;

	int min_dist = INT_MAX;
	int min_length = INT_MAX;
	for(auto p : inter){
		int dist = abs(p.x) + abs(p.y);
		if(dist < min_dist && !(p == center)){
			min_dist = dist;
		}
		if(p.dist < min_length && !(p == center)){
			min_length = p.dist;
		}
	}
	

	cout << min_dist << endl;
	cout << min_length << endl;

	return 0;
}
