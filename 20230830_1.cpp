//Beakjoon Online Judge #1967
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> edge[10001];
bool checked[10001];
int ans = 0;
int a_node = 0;


void DFS(int x, int c){
    int max = 0;
    checked[x] = true;
    if(ans<c){
        ans = c;
        a_node = x;
    }
    for(int i  = 0; i<edge[x].size(); i++){
        int t_node = edge[x][i].first;
        int t_cost = edge[x][i].second;
        if(!checked[t_node]){
            DFS(t_node, c + t_cost);
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;
    for(int i = 0; i<num-1; i++){
        int p_node, c_node, cost;
        cin >> p_node >> c_node >> cost;
        edge[p_node].push_back({c_node, cost});
        edge[c_node].push_back({p_node, cost});
    }
    DFS(1, 0);
    for(int i = 0; i<=num; i++)
        checked[i] = false;
    DFS(a_node, 0);
    cout << ans;
    return 0;

}