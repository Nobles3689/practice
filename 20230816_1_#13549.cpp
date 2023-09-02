//Beakjoon Online Judge #13549
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visit[100001] = { 0, };
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int subin, target;
    cin >> subin >> target;

    if(subin>=target){
        cout << subin - target;
    }else{
        q.push({0, subin});
        visit[subin] = true;
        int tp, w_f, w_b, n_time;
        while (!q.empty())
        {
            int time = q.top().first;
            int tmp = q.top().second;
            q.pop();
            tp = tmp*2;
            w_f = tmp+1;
            w_b = tmp-1;
            n_time = time+1;

            
            if(tmp == target){
                cout << time;
                break;
            }
            if((tp<=100000)&&(visit[tp]==false)){
                q.push({time, tp});
                visit[tp] = true;
            }
            if((w_b>=0)&&(visit[w_b]==false)){
                q.push({n_time, w_b});
                visit[w_b] = true;
            }
            if((w_f<=100000)&&(visit[w_f]==false)){
                q.push({n_time, w_f});
                visit[w_f] = true;
            }
            
        }
        
    }
    return 0;
}