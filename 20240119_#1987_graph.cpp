//Beakjoon Online Judge #1987
#include <iostream>
#include <vector>
using namespace std;

struct Coord
{
    int y = 0;
    int x = 0;

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

int n, m, ans = 0;
bool alphabet[26];
int board[20][20];
Coord movement[4] = 
{
    Coord{-1, 0}, Coord{1, 0}, Coord{0, -1}, Coord{0, 1}
};

void DFS(Coord coord, int cnt){
    alphabet[board[coord.y][coord.x]] = true;
    int flag = 0;
    for(int i = 0; i<4; i++){
        Coord tmp = coord + movement[i];
        if(tmp.x < 0 || tmp.x >= m || tmp.y < 0 || tmp.y >= n){
            flag++;
            continue;
        }
        if(alphabet[board[tmp.y][tmp.x]]){
            flag++;
            continue;
        }
        
        DFS(tmp, cnt+1);
        
    }
    if(flag == 4){
        if(ans < cnt) ans = cnt;
    }
    alphabet[board[coord.y][coord.x]] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char tmp;
            cin >> tmp;
            board[i][j] = tmp - 'A'; 
        }
    }
    DFS({0, 0}, 1);
    cout << ans;
    return 0;
}