#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream infile("input/1.txt");
    string s;
    int sum = 0;
    while(getline(infile,s)){
        int i = stoi(s);
        int module_sum = 0;
        while(i >= 0){
            i = (i / 3) - 2;
            if(i > 0){
                module_sum += i;
            }
        }
        sum += module_sum;
    }

    cout << sum << endl;
    return 0;
}
