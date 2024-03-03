//Beakjoon Online Judge #2357
#include <bits/stdc++.h>
using namespace std;

#define MIN_NUM -1
#define MAX_NUM 1000000001

int n, m;
int num_arr[100000];
int min_seg_tree[400000];
int max_seg_tree[400000];

int init_min(int node, int start, int end){
    if(start == end) return min_seg_tree[node] = num_arr[start];
    int mid = (end+start)/2;
    int left = init_min(node*2, start, mid);
    int right = init_min(node*2+1, mid+1, end);
    return min_seg_tree[node] = min(left, right);
}

int init_max(int node, int start, int end){
    if(start == end) return max_seg_tree[node] = num_arr[start];
    int mid = (end+start)/2;
    int left = init_max(node*2, start, mid);
    int right = init_max(node*2+1, mid+1, end);
    return max_seg_tree[node] = max(left, right);
}

int find_min(int node, int start, int end, int left, int right){
    if(left > end || right < start) return MAX_NUM;
    if(left <= start && end <= right) return min_seg_tree[node];
    int mid = (start+end)/2;
    int left_val = find_min(node*2, start, mid, left, right);
    int right_val = find_min(node*2+1, mid+1, end, left, right);
    return min(left_val, right_val);
}

int find_max(int node, int start, int end, int left, int right){
    if(left > end || right < start) return MIN_NUM;
    if(left <= start && end <= right) return max_seg_tree[node];
    int mid = (start+end)/2;
    int left_val = find_max(node*2, start, mid, left, right);
    int right_val = find_max(node*2+1, mid+1, end, left, right);
    return max(left_val, right_val);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> num_arr[i];
    }
    init_min(1, 0, n-1);
    init_max(1, 0, n-1);
    int left, right;
    for(int i = 0; i<m; i++){
        cin >> left >> right;
        cout << find_min(1, 0, n-1, left-1, right-1) << ' ' << find_max(1, 0, n-1, left-1, right-1) << '\n';
    }

    return 0;
}