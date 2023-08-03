//Beakjoon Online Judge #1931
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool comp(pair<int, int> left, pair<int, int> right)
    {
        if(left.second == right.second){
            return left.first < right.first;
        }else{
            return left.second < right.second;
        }
    }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, int>> timetable;
    int num;
    cin >> num;
    for(int i = 0; i<num; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        timetable.push_back(make_pair(tmp1, tmp2));
    }
    sort(timetable.begin(), timetable.end(), comp);
    int etime = 0;
    int result = 0;
    for(const auto& p : timetable){   
        if(p.first>=etime){
            result++;
            etime = p.second;
        }
    }

    cout << result;
    return 0;
}