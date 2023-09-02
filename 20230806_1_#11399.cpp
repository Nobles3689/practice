//Beakjoon Online Judge #11399
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    int t_time = 0;
    vector<int> time;
    cin >> num;
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        time.push_back(tmp);
    }

    sort(time.begin(), time.end(), less());
    for(int i = 0; i<time.size(); i++){
        t_time+=time[i];
        for(int j = 0; j<i; j++){
            t_time+=time[j];
        }
    }
    cout << t_time;
    return 0;
}