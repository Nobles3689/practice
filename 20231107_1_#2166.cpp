//Beakjoon Online Judge #2166
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<double, double>> point;

double cal(int n){
    double res = 0;
    for(int i = 1; i<n; ++i){
        res += point[i-1].first*point[i].second - point[i-1].second*point[i].first;
    }
    res += point[n-1].first*point[0].second - point[n-1].second*point[0].first;
    if(res<0) res*=-1;
    return res/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for(int i = 0; i<num; i++){
        double x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }
    cout<<fixed;
    cout.precision(1);
    cout << cal(num);
    return 0;
}