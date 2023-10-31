//Beakjoon Online Judge #2565
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, int>> cable;
    vector<vector<int>> tmp(101);
    vector<int> DP(101, 0);
    int line;
    cin >> line;
    cable.push_back({0, 0});
    for(int i = 0; i<line; i++){
        int a, b;
        cin >> a >> b;
        cable.push_back({a, b});
    }
    sort(cable.begin(), cable.end());

    int ans = -1;
    for (int i = 1; i <= line; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (cable[i].second > cable[j].second)
                DP[i] = max(DP[i], DP[j] + 1);
		}
        ans = max(ans, DP[i]);
	}
    
    cout << line - ans;
    return 0;

}