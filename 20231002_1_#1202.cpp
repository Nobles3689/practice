//Beakjoon Online Judge #1202
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int>&a, pair<int, int>&b){
        if(a.first == b.first){
            return a.second > b.second;
        }else{
            return a.first < b.first;
        }
    }
};

bool com(pair<int, int>&a, pair<int, int>&b){
        if(a.first == b.first){
            return a.second < b.second;
        }else{
            return a.first > b.first;
        }
}

//priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> jq;
vector<pair<int, int>> jv;
multiset<int> bs;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int jew, bag;
    cin >> jew >> bag;
    for(int i = 0; i<jew; i++){
        int weight, value;
        cin >> weight >> value;
        //jq.push({value, weight});
        jv.push_back({value, weight});
    }
    for(int i = 0; i<bag; i++){
        int weight;
        cin >> weight;
        bs.insert(weight);
    }
    sort(jv.begin(), jv.end(), com);
    long long res = 0;
    //while (!jq.empty() || !bs.empty())
    for(int i = 0; i<jew; i++)
    {
        //pair<int, int> tmp = jq.top();
        //jq.pop();
        pair<int, int> tmp = jv[i];
        multiset<int>::iterator it;
        it = bs.lower_bound(tmp.second);
        if(it == bs.end()){
            continue;
        }else{
            bs.erase(it);
            res+=tmp.first;
        }
    }
    cout << res;
    return 0;
}