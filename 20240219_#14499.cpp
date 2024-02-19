//Beakjoon Online Judge #14499
#include <bits/stdc++.h>
using namespace std;

int Dice[4][3];
int Dice_map[21][21];
int n, m;
pair<int, int> Dice_coord;

void move(int command){
    int tmp;
    switch (command)
    {
    case 1:
        if(Dice_coord.second+1 >= m) return;
        Dice_coord.second++;
        tmp = Dice[1][2];
        Dice[1][2] = Dice[1][1];
        Dice[1][1] = Dice[1][0];
        Dice[1][0] = Dice[3][1];
        Dice[3][1] = tmp;
        break;
    case 2:
        if(Dice_coord.second-1 < 0) return;
        Dice_coord.second--;
        tmp = Dice[1][0];
        Dice[1][0] = Dice[1][1];
        Dice[1][1] = Dice[1][2];
        Dice[1][2] = Dice[3][1];
        Dice[3][1] = tmp;
        break;
    case 3:
    if(Dice_coord.first-1 < 0) return;
        Dice_coord.first--;
        tmp = Dice[0][1];
        Dice[0][1] = Dice[1][1];
        Dice[1][1] = Dice[2][1];
        Dice[2][1] = Dice[3][1];
        Dice[3][1] = tmp;
        break;
    case 4:
        if(Dice_coord.first+1 >= n) return;
        Dice_coord.first++;
        tmp = Dice[3][1];
        Dice[3][1] = Dice[2][1];
        Dice[2][1] = Dice[1][1];
        Dice[1][1] = Dice[0][1];
        Dice[0][1] = tmp;
        break;
    }

    if(Dice_map[Dice_coord.first][Dice_coord.second] == 0){
        Dice_map[Dice_coord.first][Dice_coord.second] = Dice[3][1];
    }else{
        Dice[3][1] = Dice_map[Dice_coord.first][Dice_coord.second];
        Dice_map[Dice_coord.first][Dice_coord.second] = 0;
    }
    cout << Dice[1][1] << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int com;
    cin >> n >> m >> Dice_coord.first >> Dice_coord.second >> com;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Dice_map[i][j];
        }
        
    }
    for(int i = 0; i<com; i++){
        int tmp_com;
        cin >> tmp_com;
        move(tmp_com);
    }
    return 0;
}