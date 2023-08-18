//Beakjoon Online Judge $12865 배낭 알고리즘(knapsack problem)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dp[100001] = {0,};//1차원 배열 사용
vector<pair<int, int>> list;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num, m_weight;
    cin >> num >> m_weight;
    list.emplace_back(make_pair(0,0));

    for(int i = 0; i<num; i++){
        int weight, value;
        cin >> weight >> value;
        list.emplace_back(make_pair(weight,value));

    }


    for(int i = 1; i<=num; i++){
        for(int j = m_weight; j>=1; j--){
            if(j>=list[i].first){
                dp[j] = max(dp[j], dp[j-list[i].first]+list[i].second);
                
            }
        }
    }
    
    cout << dp[m_weight];
    return 0;

}
//수정 결과 - 사용 메모리 : 41476KB -> 2412KB, 소요 시간 : 32ms -> 20ms