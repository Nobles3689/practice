//Beakjoon Online Judge #14002, #14003
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;//수열내 원소 개수 입력
    vector<int> v(num);//문제의 수열
    vector<int> a;//부분수열
    vector<pair<int, int>> ans1(num);//수열의 몇번째에 해당값이 들어가는지 저장
    vector<int> ans2;//정답 출력용 벡터
    for(int i = 0; i<num; i++){
        cin >> v[i];
    }//수열 초기화


    for(int i = 0; i<num; i++){
        int index = lower_bound(a.begin(), a.end(), v[i]) - a.begin();//부분 수열 내 i번째 원소 위치 찾기
        if(index == a.size()) a.emplace_back(v[i]);//현재 확인한 부분수열의 마지막보다 큰 원소일 경우, 현재의 부분수열 뒤에 원소 붙이기
        else{
            a[index] = v[i];//아닌경우 맞는 위치에 원소 입력
        }
        ans1[i] = {v[i], index};//i번째 원소의 값과 부분수열내의 위치 입력

        
    }

    
    int cnt = a.size()-1;//부분수열내 원소 개수-1 = 마지막 원소의 부분수열내 위치

    for(int i = num-1; i>=0; i--){
        if(cnt == ans1[i].second){
            ans2.push_back(ans1[i].first);
            cnt--;
        }
    }//부분수열의 뒤에서부터 원소의 위치가 맞는 원소 찾기(이미 부분수열이 완성된 이후 수정된? 추가되는 원소 거르기 위함)
    //ex) 1 3 4 5 2 4 의 경우 ans1에서는 {1, 0} {3, 1} {4, 2} {5, 3} {2, 1} {4, 2}
    //second값을 뒤에서부터 부분수열의 마지막 인덱스부터 첫 인덱스까지 찾아가면 5 4 3 1
    //이후에 벡터a에 추가되는 {2, 1}과 {4, 2}를 제외하고 크기가 커지는 부분수열의 최대 길이에 해당하는 부분수열 출력가능

    cout << a.size() << '\n';//부분수열 최대 크기
    for(int i = ans2.size()-1; i>=0; i--){
        cout << ans2[i] << ' ';
    }//부분수열 출력(역순)
    return 0;
}