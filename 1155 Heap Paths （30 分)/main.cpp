#include<iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
int n;
int tree[1000+10];
int path[1000+10];


int get_left(int node) {
    return node *2 +1;
}
int get_right(int node) {
    return node *2 +2;
}
int is_exist(int node) {
    return node>=0 && node<n;
}
void print_tree( int node ,int index ) {
    
    path[index] = tree[node];
    int is_exist_left = 0 ;
    int is_exist_right = 0;
    if( is_exist(get_right(node)) ) {
        print_tree(get_right(node), index+1); // right
        is_exist_right = 1;
    }
    if( is_exist(get_left(node)) ) {
        print_tree(get_left(node), index+1); //left
        is_exist_left = 1;
    }
    if( is_exist_right == 0 && is_exist_left == 0  ) {
        for (int i =0;i<=index-1;i++) {
            printf("%d ",path[i]);
        }
        printf("%d\n",path[index]);
    }
}

/**
 * 我的堆判断写的复杂了（习惯性的递归）
 * 网上看到一个不错的堆判断的版本
 bool Minheap=true,Maxheap=true;
 
 for(int i=1;i<n;i++)
 {
    if(v[i]<v[(i-1)/2]) Minheap=false;
    if(v[i]>v[(i-1)/2]) Maxheap=false;
 }
 if(Minheap==true)
    printf("Min Heap");
 else
    printf("%s",Maxheap==true?"Max Heap":"Not Heap");
 
 ---------------------
 原文：https://blog.csdn.net/Imagirl1/article/details/85609678
 */
int  is_heapdef(int node,int type) {
    // type = 0 -> max , type = 1 ->min
    int is_exist_left = is_exist(get_left(node));
    int is_exist_right = is_exist(get_right(node));
    if( is_exist_left == 0 && is_exist_right ==0 )
        return 1; // 叶子节点，递归边界
    else if ( is_exist_left !=0 && is_exist_right == 0 ) {
        //有左结点，无右结点，倒数第二层
        if (type == 0)
            return tree[node]>=tree[get_left(node)];
        else
            return tree[node]<=tree[get_left(node)];
    }
    
    // 有左右节点
    int is_left_heap =  is_heapdef(get_left(node), type);
    int is_right_heap = is_heapdef(get_right(node), type);
    int l_data = tree[get_left(node)];
    int r_data = tree[get_right(node)];
    if(is_left_heap && is_right_heap) {
        if(type == 0)
            return tree[node] >=max(l_data, r_data);
        else
            return tree[node] <=min(l_data, r_data);
    }else {
        return 0;
    }
}
int main(){
    
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",tree+i);
    }
    print_tree(0, 0);
    int is_max = is_heapdef(0, 0);
    int is_min = is_heapdef(0, 1);
    if(is_max == 0 && is_min ==0) {
        printf("Not Heap\n");
    }else if(is_min) {
        printf("Min Heap\n");
    }else if(is_max) {
        printf("Max Heap\n");
    }
    return 0;
}
