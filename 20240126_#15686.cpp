//Beakjoon Online Judge #15686
#include <bits/stdc++.h>
using namespace std;
#define DIST_MAX 10001;

int n, m, h, c;
//int city[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> tmp_chicken;
int res = DIST_MAX;

int dist(pair<int, int> a, pair<int, int> b){
    int f = a.first - b.first;
    int s = a.second - b.second;
    return abs(f) + abs(s);
}

void cal(int a){
    if(tmp_chicken.size() == m){
        int sum = 0;
        for(int i = 0; i<h; i++){
            int min = DIST_MAX;
            for(int j = 0; j<m; j++){
                int tmp = dist(house[i], chicken[tmp_chicken[j]]);
                if(tmp < min) min = tmp;
            }
            sum += min;
        }

        if(sum < res) res = sum;
        return;
    }

    for(int i = a; i < c; i++){
        tmp_chicken.push_back(i);
        cal(i+1);
        tmp_chicken.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 1){
                house.push_back({i, j});
                h++;
            }
            else if(tmp == 2){
                chicken.push_back({i, j});
                c++;
            }
        }
    }
    cal(0);
    cout << res;
    return 0;
}