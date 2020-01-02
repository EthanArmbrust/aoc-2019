#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void decode(int input, int &m1, int &m2, int &m3, int &op){
	op = input % 100;
	input /= 100;
	m1 = input % 10;
	input /= 10;
	m2 = input % 10;
	m3 = input / 10;
}

void inc_amps(vector<int> &amps){
    int pos = 0;
    while(amps[pos] == 4){
        pos++;
    }
    amps[pos]++;
    while(pos > 0){
        pos--;
        amps[pos] = 0;
    }
    return;
}

int main(){

    ifstream infile("input/5.txt");
    string s;
    vector<int> list;
    string o;

    getline(infile,s);
    stringstream ss(s);

    while(getline(ss, o, ',')){
        list.push_back(stoi(o));
    }

    auto temp_list = list;
	int input = 0;
    
    vector<int> amps(5, 0);
    vector<int> MAX_AMPS(5, 4);


	int it = 0;
	while(true){
		int mode_1, mode_2, mode_3, opcode;
		decode(list[it], mode_1, mode_2, mode_3, opcode);
		if(opcode == 99){
			printf("Halting [%d]\n", it);
			break;
		}
		int p_count = 0;
		if(opcode == 1 || opcode == 2 || opcode == 7 || opcode == 8){
			p_count = 3;
		}
		else if(opcode == 3 || opcode == 4){
			p_count = 1;
		}
		else if(opcode == 5 || opcode == 6){
			p_count = 2;
		}

		int p1, p2, p3;
		if(mode_1){
			p1 = list[it + 1];
		}
		else{
			p1 = list[list[it + 1]];
		}
		if(p_count > 1){
			if(mode_2){
				p2 = list[it + 2];
			}
			else{
				p2 = list[list[it + 2]];
			}
		}
		if(p_count > 2){
			if(mode_3){
				p3 = list[it + 3];
			}
			else{
				p3 = list[list[it + 3]];
			}
		}

		if(opcode == 1){ //add
			list[list[it+3]] = p1 + p2;
		}
		if(opcode == 2){ //multiply
			list[list[it+3]] = p1 * p2;
		}
		if(opcode == 3 ){ //input
			list[list[it+1]] = input;
		}
		if(opcode == 4){ //output
			printf("Output[%d]: %d\n", it, p1);
		}
		if(opcode == 5){
			if(p1){
				it = p2 - (p_count + 1);
			}
		}
		else if(opcode == 6){
			if(!p1){
				it = p2 - (p_count + 1);
			}
		}
		else if(opcode == 7){
			list[list[it+3]] = p1 < p2;
		}
		else if(opcode == 8){
			list[list[it+3]] = p1 == p2;
		}

		it += 1 + p_count;
	}
    return 0;
}

