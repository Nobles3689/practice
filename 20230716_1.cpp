//Beakjoon Online Judge #18258
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
    //-----------------------------
    ios::sync_with_stdio(false);
    //C와 C++의 버퍼를 분리함, 따라서 cin과 scanf, gets, getchar등을 같이 사용할수 없게되고, cout과 printf, puts, putchar등을 같이 쓸 수 없게됨
    cin.tie(0);

    cout.tie(0);
    //---------속도를 높여주는 코드--
    //cin의 수행에서 출력 버퍼를 지우는 과정을 없애준다(cin과 cout의 묶음을 풀어줌)
    //온라인 저지에서는 화면에 바로 보여지는 것이 중요하지 않기에 여러번 반복하여 입출력할 경우 필수
    int cunt;
    int num;
    string cmd;
    queue<int> q;
    vector<int> result;
    int fIndex = 0;
    int bIndex = -1;
    cin >> cunt;
    for(int i = 0; i<cunt; i++){
        cin >> cmd;
        if(!cmd.compare("push")){
            cin >> num;
            q.push(num);
        }else if(!cmd.compare("pop")){
            if(q.empty()){
                result.push_back(-1);
            }else{
                result.push_back(q.front());
                q.pop();
            }
        }else if(!cmd.compare("size")){
            result.push_back(q.size());
        }else if(!cmd.compare("empty")){
            if(q.empty()){
                result.push_back(1);
            }else{
                result.push_back(0);
            }
        }else if(!cmd.compare("front")){
            if(q.empty()){
                result.push_back(-1);
            }else{
                result.push_back(q.front());
            }
        }else{
            if(q.empty()){
                result.push_back(-1);
            }else{
                result.push_back(q.back());
            }
        }
    }
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << '\n';
    }
    return 0;
}