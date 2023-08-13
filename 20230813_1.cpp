//Beakjoon Online Judge #11053
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int DP[1000] = { 0, };//이전까지 값저장(다이나믹 프로그래밍)


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //시간줄이기
    int num;
    cin >> num;//개수입력
    for(int i = 0; i<num; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }//배열 초기화
    int t_max = 0;//최대값

    for(int i = 0; i<num; i++){
        DP[i] = 1;//해당칸부터 시작인 경우(최소인 경우에도 1)
        for(int j = 0; j<i; j++){//i가 한칸씩 커짐에 따라 기존 계산해둔 부분과 다시 비교
            if(v[i]>v[j]){//새로운 값이 기존 값보다 큰 경우
                DP[i] = max(DP[j]+1, DP[i]);//j까지의 계산결과에 원소가 하나 추가된 경우와 이전 반복문에서 새 값이 더 클때의 결과중 더 큰 값
            }else{//새로운 값이 기존 값보다 작은경우
                t_max = max(t_max, DP[j]);//기존 최대길이와 j까지의 최대길이중 큰값
            }
        }
        t_max = max(t_max, DP[i]);//새로 계산한 값과 기존 최대길이중 더 큰값을 최대길이로
    }

    cout << t_max;

    return 0;

}