//Beakjoon Online Judge $12865 배낭 알고리즘(knapsack problem)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dp[101][100001];//2차원 배열 사용하는 이유? -> line 28참조
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
        for(int j = 1; j<=m_weight; j++){
            if(j>=list[i].first){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-list[i].first]+list[i].second);
                //만약 1차원 배열로 진행한다면 앞에서 수정되었을 경우 뒤에서 한번더 i번째 가치를 적용한 값이 들어갈 수 있다.
                //따라서 참조 및 수정을 뒤에서부터 진행하면 1차원 배열로 구현할 수 있다.->20230818_2.cpp
                //수정 결과 - 사용 메모리 : 41476KB -> 2412KB, 소요 시간 : 32ms -> 20ms
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[num][m_weight];
    return 0;

}
