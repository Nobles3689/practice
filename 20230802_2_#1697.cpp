//Beakjoon Online Judge #1697
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


bool visit[100001];

int main(){
    for(int i = 0; i<100001; i++){
        visit[i] = false;
    }
    queue<pair<int, int>> tmp_q;
    int subin, target;
    cin >> subin >> target;

    if(subin>=target){
        cout << subin-target;
        return 0;
    }else{
        tmp_q.push(make_pair(subin, 0));
        visit[subin] = true;
        int ans;
        while (!tmp_q.empty())
        {
            int tmp = tmp_q.front().first;
            int time = tmp_q.front().second;
            tmp_q.pop();
            if(tmp==target){
                ans = time;
                break;
            }
            if((tmp>0)&&(visit[tmp-1]==false)){
                tmp_q.push(make_pair(tmp-1, time+1));
                visit[tmp-1] = true;
            }
            if(tmp<100000&&visit[tmp+1]==false){
                tmp_q.push(make_pair(tmp+1, time+1));
                visit[tmp+1] = true;
            }
            if(tmp<=50000&&visit[tmp*2]==false){
                tmp_q.push(make_pair(tmp*2, time+1));
                visit[tmp*2] = true;
            }
            
        }
        cout << ans;
        return 0;

    }



}