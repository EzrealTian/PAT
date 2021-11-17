//
//main.cpp
//~/Desktop/PAT/AdvancedLevel/A1101~A1150/A1119-Pre-order_and_Post-order_Traversals
//
//Created by Ezreal on 2020-06-06.
//Copyright © 2020年 Ezreal. All rights reserved.
//


#include <cstdio>
#include <vector>

using namespace std;
vector<int> pre, post, in;
bool is_unique = true;
void in_order_build(int pre_left, int pre_right, int post_left, int post_right) {
    if (pre_left == pre_right) {
        in.push_back(pre[pre_left]);
        return;
    }
    int i = pre_left + 1;
    while (i <= pre_right && pre[i] != post[post_right - 1]) i++;
    if (i - pre_left > 1) {
        in_order_build(pre_left + 1, i - 1, post_left, post_left + (i - pre_left - 1) - 1);
    } else {
        is_unique = false;
    }
    in.push_back(post[post_right]);
    in_order_build(i, pre_right, post_left + (i - pre_left - 1), post_right - 1);
}
int main() {
    int N;
    scanf("%d", &N);
    pre.resize(N);
    post.resize(N);
    for (int i = 0; i < N; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < N; i++) scanf("%d", &post[i]);
    in_order_build(0, N - 1, 0, N - 1);
    printf("%s\n", is_unique ? "Yes" : "No");
    for (int i = 0; i < N; i++) printf("%d%s", in[i], i == N - 1 ? "\n" : " ");
    return 0;
}