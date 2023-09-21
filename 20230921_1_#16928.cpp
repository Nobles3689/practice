//Beakjoon Online Judge #16928
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 10000000

int ladder, snake;
bool b[101] = {false, };

void bfs(vector<vector<pair<int, int>>> &graph, vector<int> &chance){
    queue<pair<int, int>> q;
    q.push({1, 0});
    chance[1] = 0;
    int dice, ex;
    while (!q.empty())
    {
        ex = q.front().first;
        dice = q.front().second;
        q.pop();
        if(ex==100) continue;
        for(int i = 0; i<graph[ex].size(); i++){
            int tmp = graph[ex][i].first;
            int t_dice = dice + graph[ex][i].second;
            if(chance[tmp]>t_dice){
                chance[tmp] = t_dice;
                q.push({tmp, t_dice});
            }   
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> ladder >> snake;
    vector<vector<pair<int, int>>> graph(101);
    vector<int> chance(101, MAX);
    

    for(int i = 0; i<ladder; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back({end, 0});
    }
    for(int i = 0; i<snake; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back({end, 0});
    }
    for(int i = 1; i<100; i++){
        if(graph[i].empty()){
            for(int j = 1; j<=6; j++){
                if(i+j<=100)
                    graph[i].push_back({i+j, 1});
            }
        }
    }



    

    bfs(graph, chance);
    cout << chance[100];
    return 0;

}