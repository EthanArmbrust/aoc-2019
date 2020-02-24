#include <iostream>
#include <vector>

using namespace std;

void update_vel(vector<vector<int>> &moon_pos, vector<vector<int>> &moon_vel){
	for(int i = 0; i < moon_pos.size(); i++){
	    for(int j = 0; j < moon_pos.size(); j++){
            for(int n = 0; n < 3; n++){
                if(moon_pos[i][n] < moon_pos[j][n]){
                    moon_vel[i][n]++;
                }
                else if(moon_pos[i][n] > moon_pos[j][n]){
                    moon_vel[i][n]--;
                }
            }
        }
	}
}
void update_pos(vector<vector<int>> &moon_pos, vector<vector<int>> &moon_vel){
    for(int i = 0; i < moon_pos.size(); i++){
        for(int j = 0; j < 3; j++){
            moon_pos[i][j] += moon_vel[i][j];
        }
    }   
}

void print_info(vector<vector<int>> &moon_pos, vector<vector<int>> &moon_vel){
    for(int i = 0; i < moon_pos.size(); i++){
        printf("pos=<x=%d, y=%d, z=%d>, vel=<x=%d, y=%d, z=%d>\n",
                moon_pos[i][0],
                moon_pos[i][1],
                moon_pos[i][2],
                moon_vel[i][0],
                moon_vel[i][1],
                moon_vel[i][2]
              );
    }
    cout << endl;
}

int main(){
    
    vector < vector < int > > moon_pos = {
        {17, -7, -11},
        {1, 4, -1},
        {6, -2, -6},
        {19, 11, 9}
    };
    vector < vector < int > > moon_vel {
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    const int steps = 1000;

    for(int i = 0; i < steps; i++){
        update_vel(moon_pos, moon_vel);
        update_pos(moon_pos, moon_vel);
    }

    int sum = 0;

    for(int i = 0; i < moon_pos.size(); i++){
        int p = 0, k = 0;
        for(int n = 0; n < 3; n++){
            p += abs(moon_pos[i][n]);
            k += abs(moon_vel[i][n]);
        }
        sum += p * k;
    }

    cout << sum << endl;

	return 0;
}


