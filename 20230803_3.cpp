//Beakjoon Online Judge #2606
#include <iostream>
#include <queue>
using namespace std;
bool visit[101];

void s(int n){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for(int i = 1; i<num+1; i++){
        visit[i] = false;
    }
    int con;
    cin >> con;
    vector<pair<int, int>> v;
    for(int i = 0; i<con; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v.push_back(make_pair(tmp1, tmp2));
    }
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    int infection = -1;
    while (!q.empty())
    {   

        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(visit[a]==false){
            visit[a] = true;
            infection++;
            for(int i = 0; i<con; i++){
                if(v[i].first==a||v[i].second==a){
                    q.push(v[i]);
                }
            }
        }else if(visit[b]==false){
            visit[b] = true;
            infection++;
            for(int i = 0; i<con; i++){
                if(v[i].first==b||v[i].second==b){
                    q.push(v[i]);
                }
            }
        }
    }
    cout << infection;
    return 0;

}