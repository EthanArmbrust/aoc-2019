#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    string s;
    vector<vector<string>> layers;

    ifstream infile("input/8.txt");

    getline(infile,s);

    int x = 25;
    int y = 6;

    while(s.size() > 0){
        string lay = s.substr(0, x * y);
        vector<string> layer_grid;
        for(int i = 0; i < y; i++){
            layer_grid.push_back(lay.substr(0, x));
            lay = lay.substr(x);
        }
        layers.push_back(layer_grid);
        s = s.substr(x*y);
    }

    vector<string> final_grid;
    for(int j = 0; j < y; j++){
        string line;
        for(int i = 0; i < x; i++){
            int depth = 0;
            while(layers[depth][j][i] == '2'){
                depth++;
            }
            line.push_back(layers[depth][j][i]);
        }
        final_grid.push_back(line);
    }

    

    for(auto &str : final_grid){
        cout << str << endl;
    }

    return 0;
}
