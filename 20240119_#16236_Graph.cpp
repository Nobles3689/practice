//Beakjoon Online Judge #16236
#include <bits/stdc++.h>
using namespace std;

int Map[20][20], visited[20][20];
int n, ans, shark_size = 2, diet;
int now_x, now_y;
int dy[4] = { -1,0,0,1 }, dx[4] = { 0,-1,1,0 };

int BFS(){
    for(int i = 0; i<n; i++)
        memset(visited[i], 0, sizeof(int)*n);
    int dist = 0;
    queue<pair<int, int>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    q.push({now_y, now_x});
    visited[now_y][now_x] = 1;
    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        if(visited[ny][nx] == dist)
            break;
        for(int j = 0; j<4; j++){
            int ty = ny + dy[j];
            int tx = nx + dx[j];
            
            if(tx < 0 || tx >= n || ty < 0 || ty >= n)
                continue;
            if(visited[ty][tx])
                continue;
            if(!Map[ty][tx] || Map[ty][tx] == shark_size)
            {
                q.push({ty, tx});
                visited[ty][tx] = visited[ny][nx] + 1;
            }else if(Map[ty][tx] < shark_size){
                if(!dist) diet++;
                pq.push({ty, tx});
                visited[ty][tx] = visited[ny][nx] + 1;
                dist = visited[ty][tx];
            }
            
        }

    }
    if(pq.empty())
        return 0;
    now_y = pq.top().first;
    now_x = pq.top().second;
    Map[now_y][now_x] = 0;
    if(diet == shark_size){
        shark_size++;
        diet = 0;
    }
    return visited[now_y][now_x] - 1;
    
        
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				now_y = i;
				now_x = j;
				Map[i][j] = 0;
			}
		}
    }   
	while (true) {
		int timer = BFS();
		ans += timer;
		if (!timer)
			break;
	}
	cout << ans;
    return 0;
}