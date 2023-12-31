//Beakjoon Online Judge #7562
#include <iostream>
#include <vector>
#include <queue>
using namespace std;



struct Coord
{
    int x = 0;
    int y = 0;
    int cnt = 0;

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

Coord movement[8] =
{
    Coord {1, 2, 0},
    Coord {1, -2, 0},
    Coord {-1, 2, 0},
    Coord {-1, -2, 0},
    Coord {2, 1, 0},
    Coord {2, -1, 0},
    Coord {-2, 1, 0},
    Coord {-2, -1, 0},

};

int BFS(int bSize, Coord start, Coord goal){
    if(start == goal) return 0;
    bool visit[bSize][bSize] = { false, };
    queue<Coord> q;
    q.push(start);
    visit[start.x][start.y] = true;

    while (!q.empty())
    {
        Coord now = q.front();
        q.pop();
        for(int i = 0; i<8; i++){
            Coord tmp = now + movement[i];
            
            if(tmp.x < 0 || tmp.x >= bSize || tmp.y < 0 || tmp.y >= bSize)
                continue;
            if(tmp==goal)
                return ++now.cnt;
            if(!visit[tmp.x][tmp.y])
            {
                tmp.cnt = now.cnt + 1;
                q.push(tmp);
                visit[tmp.x][tmp.y] = true;
            }
            
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int i = 0; i<testCase; i++){
        int boardSize;
        cin >> boardSize;
        
        Coord start, goal;
        cin >> start.x >> start.y;
        cin >> goal.x >> goal.y;

        cout << BFS(boardSize, start, goal) << '\n';
    }
    return 0;
}