//Beakjoon Online Judge #25206
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, double> m;

string G[10] = { 
    "A+",
    "A0",
    "B+",
    "B0",
    "C+",
    "C0",
    "D+",
    "D0",
    "P",
    "F"};

void init_Map(){
    double t = 4.5;
    for(int i = 0; i<9; i++){
        m.insert({G[i], t});
        t-=0.5;
    }
}

vector<string> _split(string str, char D)
{
    int a = str.find(D);
    int b = 0;
    vector<string> v;
    while (a!=string::npos){
        string sub = str.substr(b, a-b);
        v.push_back(sub);
        b = a+1;
        a = str.find(D, b);
    }
    v.push_back(str.substr(b, a-b));
    return v;  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double sum = 0.0, credit_sum = 0.0;
    init_Map();
    for(int i = 0; i<20; i++)
    {
        string s;
        getline(cin, s);
        vector<string> v = _split(s, ' ');
        double credit = stod(v[1]);
        double grade = m[v[2]];
        if(grade != 0.5)
        {
            sum += (credit*grade);
            credit_sum += credit;
        }
        v.clear();
    }
    
    cout << fixed;
    cout.precision(6);
    double avg = sum / credit_sum;
    cout << avg;
    return 0;
}