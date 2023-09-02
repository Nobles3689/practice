//Beakjoon Online Judge #1546
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int sub;
    vector<double> score;
    cin >> sub;
    double max = 0;
    for(int i = 0; i<sub; i++){
        double tmp;
        cin >> tmp;
        score.push_back(tmp);
        if(tmp>max){
            max = tmp;
        }
    }
    double sum = 0;
    for(int i = 0; i<sub; i++){
        double tmp = score[i]/max*100;
        sum += tmp;
    }
    cout << sum/(double)sub;
    return 0;

}
