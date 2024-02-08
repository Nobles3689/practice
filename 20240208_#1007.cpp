//Beakjoon Online Judge #1007
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> coord;
#define MAX 9223372036854775807ll

vector<coord> node;
long long sum_x, sum_y;
long long m;
int n;

void cal_vec(long long tsx, long long tsy, int index, int cnt){
    tsx-=node[index].first*2;
    tsy-=node[index].second*2;
    if(cnt == n/2){
        long long tmp = tsx*tsx + tsy*tsy;
        m = min(m, tmp);
        return;
    }
    for(int i = index+1; i<n; i++){
        cal_vec(tsx, tsy, i, cnt+1);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for(int t = 0; t<tc; t++){
        sum_x = 0;
        sum_y = 0;
        m = MAX;
        node.clear();
        int tx, ty;
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> tx >> ty;
            node.push_back({tx, ty});
            sum_x+=tx;
            sum_y+=ty;
        }
        for(int i = 0; i<=n/2; i++){
            cal_vec(sum_x, sum_y, i, 1);
        }
        cout << fixed;
        cout.precision(12);
        cout << sqrt(m) << '\n';
        
    }
    return 0;
}