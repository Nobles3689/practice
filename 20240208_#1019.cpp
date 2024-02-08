//Beakjoon Online Judge #1019
#include <bits/stdc++.h>
using namespace std;

int ans[10];

void cnt(int n, int digit){
    while (n > 0)
    {
        ans[n%10]+=digit;
        n/=10;
    }

}

void cal(int m, int n, int digit){
    while (m % 10 && m <= n) {
		cnt(m, digit);
		m++;
	}
    if(m>n) return;
    while (n % 10 != 9 && m <= n)
    {
        cnt(n, digit);
        n--;
        
    }
    int tmp = (n/10)-(m/10)+1;

    for (int i = 0; i < 10; i++) ans[i]+=tmp*digit;

    cal(m/10, n/10, digit*10);
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cal(1, n, 1);
    for (int i = 0; i < 10; i++) cout << ans[i] << ' ';
    return 0;
}