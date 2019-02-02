

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
int n;
typedef  struct node {
    node *left;
    node *right;
    int data ;
    
}node ;

node * create(int *post,int *inorder,int post_from ,int post_to ,int inorder_from ,int inorder_to) {
    
    if(post_from >post_to ) return NULL;
    if(inorder_from >inorder_to) return NULL; // 递归边界
    
    node *root = (node *)malloc(sizeof(node));
    root->data = post[post_to]; // 取后序最后一个
    int rindex =-1;
    for (int i=inorder_from;i<=inorder_to;i++) {
        if (inorder[i] == post[post_to]) {
            rindex = i; // root 结点在中序序列中位置
            break;
        }
    }
    int sum_right = inorder_to - rindex;
    
    // 分解子问题，缩小问题规模
    root->left = create(post, inorder, post_from, post_to - sum_right - 1, inorder_from, rindex-1);
    root->right = create(post, inorder, post_to-sum_right, post_to-1, rindex+1, inorder_to);
    
    return root;
}

// bfs 遍历
void bfs(node *t ) {
    queue<node *> q;
    q.push(t);
    int index = 0;
    while (!q.empty()) {
        node *cur = q.front();
        q.pop();
        ++index;
        if(index == n)
            printf("%d\n",cur->data);
        else
            printf("%d ",cur->data);
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);

    }
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    int post[32];
    int inorder[32];
    for( int i = 0 ;i<n;i++ ){
        scanf("%d",post+i);
    }
    for(int i=0 ;i<n;i++) {
        scanf("%d",inorder+i);
    }
    
    node *t = create(post, inorder, 0, n-1, 0, n-1);
    bfs(t);
    
    
    
}


