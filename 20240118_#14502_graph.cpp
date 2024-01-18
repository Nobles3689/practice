//Beakjoon Online Judge #14502
#include <iostream>
#include <vector>
#include <queue>
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

int n, m;
Coord movement[4] = 
{
    Coord{-1, 0}, Coord{1, 0}, Coord{0, -1}, Coord{0, 1}
};
int map[8][8];
int tmp_map[8][8];
vector<Coord> space;
vector<Coord> virus;

void init(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            tmp_map[i][j] = map[i][j];
        }
    }
}

void BFS(int y, int x){
    queue<Coord> q;
    q.push({y, x});
    while (!q.empty())
    {
        Coord now = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            Coord tmp = now + movement[i];
            if(tmp.x < 0 || tmp.y < 0 || tmp.x >= m || tmp.y >= n)
                continue;
            if(tmp_map[tmp.y][tmp.x] == 0){
                q.push(tmp);
                tmp_map[tmp.y][tmp.x] = 2;
            }
        }
    }
}

int cnt(){
    int tmp = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(tmp_map[i][j] == 0)
                tmp++;
        }
    }
    return tmp;
}

int cal(){
    int max_safe = 0;
    for(int a = 0; a<space.size()-2; a++){
        for(int b = a+1; b<space.size()-1; b++){
            for(int c = b+1; c<space.size(); c++){
                init();
                tmp_map[space[a].y][space[a].x] = 1;
                tmp_map[space[b].y][space[b].x] = 1;
                tmp_map[space[c].y][space[c].x] = 1;
                for(int i = 0; i<virus.size(); i++){
                    BFS(virus[i].y, virus[i].x);
                }
                int safe = cnt();
                if(max_safe < safe) max_safe = safe;
            }
        }
    }
    
    return max_safe;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j]==0) space.push_back({i, j});
            if(map[i][j]==2) virus.push_back({i, j});
        }
    }
    
    cout << cal();
    return 0;
}