

//
//  main.cpp
//  algro
//
//  Created by yxyyxy on 09/01/2019.
//  Copyright © 2019 yxy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#define MAX 1000000
using namespace std;
int tree[11][2];
int isChild[11];
int N ;
int K = 0;
//重要：写这个递归函数的时候，就要假设它是有效的,并且每个子问题相同
void invertTree( int node  ) {
    if (node == -1) {
        // 递归边界
        // 退化成一颗空树
        return ;
    }
    invertTree(tree[node][0]);// 翻转左子树，子问题
    invertTree(tree[node][1]);// 翻转右子树，子问题
    // 交换左右子树 ，合并
    int t = tree[node][0];
    tree[node][0] = tree[node][1];
    tree[node][1] = t ;
}
void print_bfs(int root){
    queue<int> que;
    que.push(root );
    int index = 0;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        ++index;
        if (index == N)
            printf("%d\n",cur);
        else
            printf("%d ",cur);
        if (tree[cur][0]!=-1)
            que.push(tree[cur][0]);
        if (tree[cur][1]!=-1)
            que.push(tree[cur][1]);
    }
}
void in_order_print(int node) {
    if (tree[node][0]!=-1)
        in_order_print(tree[node][0]);// 递归输出左树的中序
    ++K;
    if (K == N)
        printf("%d\n",node);// 输出根节点
    else
        printf("%d ",node);
    if (tree[node][1]!=-1)
        in_order_print(tree[node][1]);// 递归输出右树的中序
}
int main(int argc, const char * argv[]) {
    
    scanf("%d",&N);
    getchar();
    memset(isChild, 0, 11);
    char left ,right ;
    char ch[5];
    for (int i = 0 ; i< N; i++) {
        fgets(ch,5,stdin);
        left = ch[0];
        right = ch[2];
        if (left == '-' ) {
            tree[i][0] = -1;
        } else {
            int node = left - '0';
            tree[i][0] = node;
            isChild[node] = 1;
        }
        if (right == '-' ) {
            tree[i][1] = -1;
        } else {
            int node = right - '0';
            tree[i][1] = node;
            isChild[node] = 1;
        }
    }
    int root = -1;
    for(int i = 0; i<N;i++) {
        if(!isChild[i]) {
            root = i;
        }
    }
    invertTree(root);
    print_bfs(root);
    in_order_print(root);
    
    return 0;
}


