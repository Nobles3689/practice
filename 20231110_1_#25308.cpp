//Beakjoon Online Judge #25308
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double stat[8];
bool check[8];
vector<double> v;
double res = 0;
pair<double, double> coor[8] = {{0, 1}, {1/sqrt(2), 1/sqrt(2)}, {1, 0}, {1/sqrt(2), 1/sqrt(2)*-1}, {0, -1}, {1/sqrt(2)*-1, 1/sqrt(2)*-1}, {-1, 0}, {1/sqrt(2)*-1, 1/sqrt(2)}};

void Permutation(int n, int r)
{
    if (n == r)
    {   
        int i;
        for (i = 0; i < v.size(); i++)
	    {   
            pair<double, double> tmp_coor[2];
            
            tmp_coor[0].first = v[(i+1)%8]*coor[(i+1)%8].first - v[i%8]*coor[i%8].first;
            tmp_coor[0].second = v[(i+1)%8]*coor[(i+1)%8].second - v[i%8]*coor[i%8].second;
            tmp_coor[1].first = v[(i+2)%8]*coor[(i+2)%8].first - v[i%8]*coor[i%8].first;
            tmp_coor[1].second = v[(i+2)%8]*coor[(i+2)%8].second - v[i%8]*coor[i%8].second;
            double tmp = (tmp_coor[0].first*tmp_coor[1].second) - (tmp_coor[0].second*tmp_coor[1].first);
            if(tmp > 0) break;
	    }
        if(i == 8) res++;
        return;
    }
 
    for (int i = 0; i < 8; i++)
    {
        if (check[i] == true) continue;
        check[i] = true;
        v.push_back(stat[i]);
        Permutation(n+1 , r);
        v.pop_back();
        check[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i<8; i++){
        cin >> stat[i];
    }
    Permutation(0, 8);
    cout << res;
    return 0;
    
}