//Beakjoon Onling Judge #1865 벨만포드 알고리즘 변형
//참고자료 https://www.acmicpc.net/board/view/72995, https://yabmoons.tistory.com/365
#include <iostream>
#include <vector>
using namespace std;
#define INF 1e8
typedef pair<int, int> Nodes;

vector<pair<Nodes, int>> edge;
vector<int> node;

void Init(int n, int m, int w){
    node.clear();
    edge.clear();
    for(int i = 0; i<m; i++){
        int start, goal, cost;
        cin >> start >> goal >> cost;
        edge.push_back({{start, goal}, cost});
        edge.push_back({{goal, start}, cost});
    }
    for(int i = 0; i<w; i++){
        int start, goal, cost;
        cin >> start >> goal >> cost;
        edge.push_back({{start, goal}, -cost});
    }
}

bool Bellman_Ford(int n){
    
    
        
    for(int i = 0; i<=n; i++){
        node.push_back(INF);
    }
    node[1] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<edge.size(); j++){
            int start = edge[j].first.first;
            int goal = edge[j].first.second;
            int cost = edge[j].second;
            //if(node[start]==INF) continue;
            if(node[goal] > node[start] + cost){
                if(i == n) return true;
                node[goal] = node[start] + cost;    
            }
        }
    }
    return false;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    for(int l = 0; l<num; l++){
        int n, m, w;
        cin >> n >> m >> w;
        Init(n, m, w);
        bool ans = Bellman_Ford(n);
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

//오타확인 잘하기!!!!!!!!!!!!!!!!!!!!!!!!