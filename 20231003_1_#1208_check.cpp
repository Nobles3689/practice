//Beakjoon Online Judge #1208
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(41);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num, goal;
    cin >> num >> goal;
    int mid = num / 2;
    vector<int> first;
    vector<int> second;
    for(int i = 0; i<num; i++){
        cin >> v[i];
    }
    //모든 부분집합(부분수열) 구하는법! -> 비트연산 활용!!
    //모든 부분집합의 개수 -> 1 << n = 2^n
    //i는 나올수 있는 2^n가지 경우의 수를 모두 지나기 때문에
    //1 << j 값이 부분수열에 들어갈 원소의 위치를 정해줌
    /*ex)
    i : 0
    i : 1 -> 0
    i : 2 -> 1
    i : 3 -> 0, 1
    i : 4 -> 2
    i : 5 -> 0, 2
    i : 6 -> 1, 2
    i : 7 -> 0, 1, 2
    i : 8 -> 3
    i : 9 -> 0, 3
    i : 10 -> 1, 3
    i : 11 -> 0, 1, 3
    i : 12 -> 2, 3
    i : 13 -> 0, 2, 3
    i : 14 -> 1, 2, 3
    i : 15 -> 0, 1, 2, 3
    */
    for(int i = 0; i<(1 << mid); i++){
        int sum = 0;
        for(int j = 0; j<mid; j++){
            if(i & (1 << j)) sum += v[j];
        }
        first.push_back(sum);
    }
    for(int i = 0; i<(1 << (num - mid)); i++){
        int sum = 0;
        for(int j = 0; j<(num-mid); j++){
            if(i & (1 << j)) sum += v[mid + j];
        }
        second.push_back(sum);
    }
    sort(second.begin(), second.end());
    long long ans = 0;
    for(int i = 0; i<first.size(); i++){
        auto it = equal_range(second.begin(), second.end(), goal - first[i]);
        ans += it.second - it.first;
    }
    if(goal == 0) ans--;
    cout << ans;
    return 0;

}