#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){

    ifstream infile("input/2.txt");
    string s;
    getline(infile,s);
    vector<int> list;
    string o;
    stringstream ss(s);
    while(getline(ss, o, ',')){
        list.push_back(stoi(o));
    }
    auto temp_list = list;

    for(int x = 0; x < 100; x++){
        for(int y = 0; y < 100; y++){
            list = temp_list;

            list[1] = x;
            list[2] = y;

            int it = 0;
            while(list[it] != 99){
                if(list[it] == 1){
                    list[list[it+3]] = list[list[it+1]] + list[list[it+2]];
                }
                else if(list[it] == 2){
                    list[list[it+3]] = list[list[it+1]] * list[list[it+2]];
                }
                it += 4;
            }
            if(list[0] == 19690720){
                cout << "Part 2: " << (100 * x) + y << endl;
            }
            if(x == 12 && y == 2){
                cout << "Part 1: " << list[0] << endl;
            }
        }
    }

    return 0;
}

