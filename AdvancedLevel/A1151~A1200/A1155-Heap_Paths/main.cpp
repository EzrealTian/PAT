//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1155-Heap_Paths
//
//Created by Ezreal on 2020-05-28.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int N;
void dfs(int index, int* arr) {
    v.push_back(arr[index]);
    if (index * 2 + 1 >= N && index * 2 + 2 >= N) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            i == v.size() - 1 ? cout << "\n" : cout << " ";
        }
        v.pop_back();
        return;
    }
    if (index * 2 + 2 < N) dfs(index * 2 + 2, arr);
    if (index * 2 + 1 < N) dfs(index * 2 + 1, arr);
    v.pop_back();
}
int main() {
    cin >> N;
    int *heap = new int[N];
    bool MAX = true;
    bool MIN = true;
    for (int i = 0; i < N; i++) cin >> heap[i];
    dfs(0, heap);
    for (int i = 1; i < N; i++) {
        if (heap[(i - 1)/2] > heap[i]) MIN = false;
        if (heap[(i - 1)/2] < heap[i]) MAX = false;
    }
    if (MAX) cout << "Max Heap" << endl;
    else MIN ? cout << "Min Heap\n" : cout << "Not Heap\n"; 
    return 0;
}