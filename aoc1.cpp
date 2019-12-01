#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream infile("input/1.txt");
    string s;
    int sum = 0;
    while(getline(infile,s)){
        int i = stoi(s);
        sum += (i / 3) - 2;

    }

    cout << sum << endl;

    return 0;
}
