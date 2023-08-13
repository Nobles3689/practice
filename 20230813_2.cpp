//Beakjoon Online Judge #12015, #12738
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;//배열원소 수 입력
    vector<int> v(num);//배열
    vector<int> a(num);

    for(int i = 0; i<num; i++){
        cin >> v[i];
    }
    int ans = 0;
    a[0] = v[0];

    for(int i = 1; i<num; i++){
        if(a[ans] < v[i]){//벡터 a중 가장 큰 값보다 새 값이 더 큰경우
            a[++ans] = v[i];//벡터 a에 새로운 값 추가
        }else{
            int index = lower_bound(a.begin(), a.begin() + ans, v[i]) - a.begin();
            //lower_bound : 이진탐색으로 원소를 탐색하는 함수
            //사용법 : 벡터 v에서 사용시 -> lower_bound(v.begin(), v.end(), n) - v.begin(), 배열 arr에서 사용시 -> lower_bound(arr, arr + 배열크기, n) - arr, 시작부터 끝가지 탐색하면서 n 이상의 숫자가 처음으로 나오는 위치의 인덱스 값을 반환
            a[index] = v[i];//v[i]보다 처음으로 큰 값에 넣기
        }
    }

    cout << ans+1;//벡터 a의 크기(부분 수열의 크기 최대값) 출력
    return 0;
}