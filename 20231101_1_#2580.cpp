//Beakjoon Online Judge #2580
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int board[9][9] = {0, };
vector<pair<int, int>> v;

void print_board(){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}


void check(int n){
    if(n >= v.size()){
        print_board();
        exit(0);
    }
    set<int> s;
    bool f[10] = {0, };
    f[0] = true;
    int x = v[n].first;
    int y = v[n].second;
    int tmpx = (x/3)*3;
    int tmpy = (y/3)*3;
    for(int i = tmpx; i<tmpx+3; i++){
        for(int j = tmpy; j<tmpy+3; j++){
            if(board[i][j] != 0) f[board[i][j]] = true;
        }
    }

    for(int i = 0; i<9; i++){
        if(board[x][i] != 0) f[board[x][i]] = true;
        if(board[i][y] != 0) f[board[i][y]] = true;
    }
    
    for(int i = 1; i<10; i++){
        if(!f[i]){
            board[x][y] = i;
            check(n+1);
            board[x][y] = 0;
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if(tmp == 0) v.push_back({i, j});

        }
    }


    check(0);

    return 0;


}