//SW Expert Academy #1767
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 12

struct Coord
{
    int x = 0;
    int y = 0;

    bool operator==(Coord& other)
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(Coord& other){
        return !(*this == other);
    }

    Coord operator+(Coord& other)
    {
        Coord c;
        c.x = x + other.x;
        c.y = y + other.y;
        return c;
    }

    Coord& operator+=(Coord& other)
	{
        x += other.x;
		y += other.y;
		return *this;
	}


};


int board[12][12];
vector<Coord> chips;
int N;
int chip_num;
int cpu_cnt = 0;
int cable_length = MAX*MAX;

void init(){
    cpu_cnt = 0;
    cable_length = MAX*MAX;
    chips.clear();
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                if(i == 0 || j == 0 || i == N-1 || j == N-1) continue;
                chips.push_back({j, i});
            }  
        }
    }
    chip_num = chips.size();
}

bool check(int x, int y, int d){
    switch (d)
    {
    case 0:
        for(int i = 0; i<y; i++){
            if(board[i][x] != 0) return false;
        }
        break;
    case 1:
        for(int i = x + 1; i<N; i++){
            if(board[y][i] != 0) return false;
        }
        break;
    case 2:
        for(int i = y + 1; i<N; i++){
            if(board[i][x] != 0) return false;
        }
        break;
    case 3:
        for(int i = 0; i<x; i++){
            if(board[y][i] != 0) return false;
        }
        break;
    }
    return true;
}

int draw(int x, int y, int d, int flag){
    int ans = 0;
    switch (d)
    {
    case 0:
        for(int i = 0; i<y; i++){
            board[i][x] = (flag==0)?2:0;
            ans++;
        }
        break;
    case 1:
        for(int i = x + 1; i<N; i++){
            board[y][i] = (flag==0)?2:0;
            ans++;
        }
        break;
    case 2:
        for(int i = y + 1; i<N; i++){
            board[i][x] = (flag==0)?2:0;
            ans++;
        }
        break;
    case 3:
        for(int i = 0; i<x; i++){
            board[y][i] = (flag==0)?2:0;
            ans++;
        }
        break;
    }
    return ans;
}



void DFS(int cnt, int cpu, int cable){
    if(cnt == chip_num){
        if(cpu_cnt < cpu){
            cpu_cnt = cpu;
            cable_length = cable;
        }
        else if(cpu == cpu_cnt){
            if(cable_length > cable){
                cable_length = cable;
            }
        }
    }else{
        for(int i = 0; i<4; i++){
            if(check(chips[cnt].x, chips[cnt].y, i)){
                DFS(cnt + 1, cpu + 1, cable + draw(chips[cnt].x, chips[cnt].y, i, 0));
                draw(chips[cnt].x, chips[cnt].y, i, 1);
            }
        }
        DFS(cnt+1, cpu, cable);
    }
    
}

void cal(){
    init();
    DFS(0, 0, 0);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for(int i = 1; i<=TC; i++){
        cal();
        cout << '#' << i << ' ' << cable_length << '\n';
    }
    return 0;
}