//Beakjoon Online Judge #2042
#include <bits/stdc++.h>
using namespace std;

long long num_arr[1000000];
long long seg_tree[4000000];

long long init(int node, int start, int end){
    if(start == end) return seg_tree[node] = num_arr[start];

    int mid = (end+start)/2;
    long long left = init(node*2, start, mid);
    long long right = init(node*2+1, mid+1, end);
    return seg_tree[node] = left + right;
}

long long sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return seg_tree[node];

    int mid = (end+start)/2;
    long long left_sum = sum(node*2, start, mid, left, right);
    long long right_sum = sum(node*2+1, mid+1, end, left, right);
    return left_sum + right_sum;
}

void swap(int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return;
    seg_tree[node]+=diff;

    if(start != end){
        int mid = (end+start)/2;
        swap(node * 2, start, mid, index, diff);
        swap(node*2+1, mid+1, end, index, diff);
    }

}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i =0; i<n; i++){
        long long tmp;
        cin >> num_arr[i];
    }
    init(1, 0, n-1);
    for(int i = 0; i<m+k; i++){
        int flag;
        cin >> flag;
        if(flag == 1){
            int index;
            long long tmp;
            cin >> index >> tmp;
            long long diff = tmp - num_arr[index-1];
            num_arr[index-1] = tmp;
            swap(1, 0, n-1, index-1, diff);
        }else if(flag == 2){
            int left, right;
            cin >> left >> right;
            cout << sum(1, 0, n-1,left-1, right-1) << '\n';
        }
    }
    return 0;
}