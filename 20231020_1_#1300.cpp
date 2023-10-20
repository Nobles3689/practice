//Beakjoon Online Judge #1300
#include <iostream>

using namespace std;
typedef long long ll;
ll N, K;

ll find(long long goal){
    ll sum = 0;
    for(ll i = 1; i<=N; i++){
        if((i*N)<goal) sum+=N;
        else{
            if(goal%i==0) sum += (goal/i) - 1;
            else sum += (goal/i);
        }
    }
    return sum + 1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    ll low = 1;
    ll high = (N*N) + 1;
    ll mid, tmp;
    while (low+1<high)
    {
        mid = (low + high) / 2;
        tmp = find(mid);
        if(tmp<=K) low = mid;
        else high = mid;
    }
    cout << low;
    return 0;
}