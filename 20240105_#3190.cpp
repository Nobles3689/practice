//Beakjoon Online Judge #3190
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

enum Dir
{
    Dir_UP = 0,
    Dir_RIGHT = 1,
    Dir_DOWN = 2,
    Dir_LEFT = 3,
    Dir_COUNT = 4,
};

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

Coord movement[4] =
{
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 },
};


int n, k, l;
int map[102][102];
vector<Coord> _apple;
deque<pair<int, char>> _rotate;
deque<Coord> _snake;

void init(){
    for(int i = 0; i<=n+1; i++){
        map[0][i] = -1;
        map[n+1][i] = -1;
        map[i][0] = -1;
        map[i][n+1] = -1;
    }
    for(int i = 0; i<k; i++){
        map[_apple[i].y][_apple[i].x] = 1;
    }
    _snake.push_back({1, 1});
    map[1][1] = 2;

}
/*void print(){
    for(int i = 0; i<=n+1; i++){
        for(int j = 0; j<=n+1; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}*/



int _play(){
    init();
    int direction = Dir_RIGHT;
    int cnt = 0;
    while (true)
    {
        //print();
        cnt++;
        Coord _head = _snake.front();
        Coord _next = _head + movement[direction];
        

        if(map[_next.y][_next.x] == -1 || map[_next.y][_next.x] == 2) break;
        else if(map[_next.y][_next.x] == 1)
        {
            _snake.push_front(_next);
            map[_next.y][_next.x] = 2;
        }
        else
        {
            _snake.push_front(_next);
            map[_next.y][_next.x] = 2;
            map[_snake.back().y][_snake.back().x] = 0;
            _snake.pop_back();
        }
        
        if(!_rotate.empty() && cnt == _rotate.front().first)
        {
            char flag = _rotate.front().second;
            if(flag == 'D')
            {
                direction = (direction+1) % Dir_COUNT;
            }
            else if(flag == 'L')
            {
                direction = (direction-1+Dir_COUNT) % Dir_COUNT;
            }
            _rotate.pop_front();
        }

    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    
    for(int i = 0; i<k; i++){
        Coord tmp;
        cin >> tmp.y >> tmp.x;
        _apple.push_back(tmp);
    }
    cin >> l;
    for(int i = 0; i<l; i++){
        pair<int, char> tmp;
        cin >> tmp.first >> tmp.second;
        _rotate.push_back(tmp);
    }

    cout << _play();
    return 0;

}