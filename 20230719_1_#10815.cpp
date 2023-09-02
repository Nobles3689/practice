//Beakjoon Online Judge #10815
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int b_Search(vector<int> &s_list, int compare_Card){
    int front = 0;
    int end = s_list.size()-1;
    while (front<=end)
    {
        int mid = (end+front)/2;
        if(s_list[mid]==compare_Card){return 1;}
        else if(s_list[mid]>compare_Card){
            end = mid - 1;
        }else{
            front = mid + 1;
        }
    }

    return 0;
}

int main(){
    //-----------------------------
    ios::sync_with_stdio(false);
    //C와 C++의 버퍼를 분리함, 따라서 cin과 scanf, gets, getchar등을 같이 사용할수 없게되고, cout과 printf, puts, putchar등을 같이 쓸 수 없게됨
    cin.tie(0);

    cout.tie(0);
    //---------속도를 높여주는 코드--
    //cin의 수행에서 출력 버퍼를 지우는 과정을 없애준다(cin과 cout의 묶음을 풀어줌)
    //온라인 저지에서는 화면에 바로 보여지는 것이 중요하지 않기에 여러번 반복하여 입출력할 경우 필수
    int sc_num, g_num;
    int tmp;
    vector<int> sc;
    vector<int> res;
    cin >> sc_num;
    for(int i = 0; i<sc_num; i++){
        cin >> tmp;
        sc.push_back(tmp);
    }
    sort(sc.begin(), sc.end());

    cin >> g_num;
    for(int i = 0; i<g_num; i++){
        cin >> tmp;
        res.push_back(b_Search(sc, tmp));
    }

    for(int i = 0; i<res.size(); i++){
        cout << res[i] << ' ';
    }
    return 0;
}
