#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#define N 10000+10
using namespace std;
int preorder[1000+10];
typedef struct Node  {
    Node *left ;
    Node *right;
    int data;
}Node  ;
int cnt =0;
int n;
int isMirror ;
int isVaildTure = 1 ;

vector<int> out ;

int is_big_Eq(int root,int node ) {
    return node >= root;
}
int is_less(int root,int node) {
    return node < root;
}

int find_diff(int st,int end) {
    int root = preorder[st];
    for (int i=st+2;i<=end;i++) {
        int condi0 =  (is_big_Eq(root, preorder[i]) && is_less(root, preorder[i-1]) ); // 小 大
        int condi1 =  (is_less(root, preorder[i]) && is_big_Eq(root, preorder[i-1]) ) ;// 大 小
        if (condi0 || condi1)
            return i;
    }
    return -1;
}

int is_vaild_pre(int root,int st ,int end ) {
    
    int change = 0;
    isMirror = !is_less(root, preorder[st]) ;
    for (int i=st+1;i<=end;i++) {
        int condi0 =  (is_big_Eq(root, preorder[i]) && is_less(root, preorder[i-1]) ); // 小 大
        int condi1 =  (is_less(root, preorder[i]) && is_big_Eq(root, preorder[i-1]) ) ;// 大 小
        if (condi0 || condi1)
            change++;
    }
    return change <=1;
}
char tail(){
    return cnt==n?'\n':' ';
    
}
void printf_postByPre(int st,int end) {
    if (st>end)return;
    if (st == end) {
        cnt++;
        out.push_back(preorder[st]);
        return ;
    }
    int diff = find_diff(st, end);
    if (diff == -1) {
        printf_postByPre(st+1, end); //left
    } else {
        if (  st+1<n && diff <n && isVaildTure) {
            if (isMirror)
                isVaildTure = preorder[st+1]>=preorder[diff];
            else
                isVaildTure = preorder[st+1]<=preorder[diff];
        }
        
        printf_postByPre(st+1, diff-1); //left 中序列
        printf_postByPre(diff, end); // right
    }
    out.push_back(preorder[st]);
}
int main ()
{
    
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",preorder+i);
    }
    
    int is_vaild = is_vaild_pre(preorder[0], 1, n-1);
    if (is_vaild) {
        
        printf_postByPre(0, n-1);
        
        if (!isVaildTure) {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        for (int i=0;i<out.size();i++) {
            if (i==out.size()-1)
                printf("%d\n",out[i]);
            else
                printf("%d ",out[i]);
        }
    }
    else
        printf("NO\n");
    
    
    
    return 0;
}

