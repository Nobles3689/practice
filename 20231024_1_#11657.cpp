//Beakjoon Online Judge #11657
#include <iostream>
#include <vector>
using namespace std;
#define INF 1e12
typedef pair<int, int> Nodes;

vector<pair<Nodes, long long>> edge;
vector<long long> node;

void Init(int n){
    node.clear();
    edge.clear();
    for(int i = 0; i<n; i++){
        int start, goal, cost;
        cin >> start >> goal >> cost;
        edge.push_back({{start, goal}, cost});
    }
}

bool Bellman_Ford(int n){
        
    for(int i = 0; i<=n; i++){
        node.push_back(INF);
    }
    node[0] = 1;
    node[1] = 0;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<edge.size(); j++){
            int start = edge[j].first.first;
            int goal = edge[j].first.second;
            long long cost = edge[j].second;
            if(node[start]==INF) continue;
            if(node[goal] > node[start] + cost){
                node[goal] = node[start] + cost;    
            }
        }
    }
    for(int j = 0; j<edge.size(); j++){
        int start = edge[j].first.first;
        int goal = edge[j].first.second;
        long long cost = edge[j].second;
        if(node[start]==INF) continue;
        if(node[goal] > node[start] + cost){
            return true;    
        }
    }
    return false;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    Init(m);
    bool ans = Bellman_Ford(n);
    if(ans)
        cout << -1 << '\n';
    else{
        for(int i = 2; i<=n; i++){
            if(node[i]==INF)
                cout << -1 << '\n';
            else
                cout << node[i] << '\n';
        }
    }
    return 0;
}