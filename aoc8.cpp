#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    string s;
    vector<string> layers;

    ifstream infile("input/8.txt");

    getline(infile,s);

    int x = 25;
    int y = 6;

    while(s.size() > 0){
        layers.push_back(s.substr(0, x * y));
        s = s.substr(x*y);
    }
    int min_zeros = INT_MAX; 
    int ans = 0;
    for(string &str : layers){
        if(count(str.begin(), str.end(), '0') < min_zeros){
            min_zeros = count(str.begin(), str.end(), '0');
            ans = count(str.begin(), str.end(), '1') * count(str.begin(), str.end(), '2');
        }
    }
    cout << ans << endl;
    return 0;
}
