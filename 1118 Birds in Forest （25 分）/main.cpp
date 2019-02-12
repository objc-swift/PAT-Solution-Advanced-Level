#include<iostream>
#include <stdio.h>
#define N 10000+10

int parent[N];
int rank[N];
void make_set (){
    for (int i=0;i<N;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int find_root(int node) {
    if (parent[node] == node) return node;
    parent[node] = find_root(parent[node]);
    return parent[node];
}
void union_set(int a,int b) {
    if (a==b) return; // 相同
    int root_a = find_root(a);//找到a的根结点
    int root_b = find_root(b);//找到b的根结点
    if (root_a == root_b)  return; //根结点相同
    int higher_root = rank[root_a]>rank[root_b] ?root_a:root_b;// 选出较高的树
    int lower_root = rank[root_a]<rank[root_b]?root_a:root_b;// 选出较低的树
    if( higher_root == lower_root ) {
        // 两颗树高度相等的情况
        parent[root_b] = root_a; //root_b.parent 指向 root_a (默认操作)
        ++rank[root_a];// 高度+1
    }else {
        parent[lower_root] = higher_root; // 较矮的树指向较高的树，不会改变整体高度
    }
}
int main(){
    make_set();
    int n,k,q,last,bi;
    int max =-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&k);
        if(k==0)continue;
        last=-1;
        for(int j=0;j<k;j++) {
            scanf("%d",&bi);
            if(bi>max) max=bi;
            if(last!=-1) {
                union_set(last, bi);
            }
            last=bi;
        }
    }
    int root_s = 0 ;
    for(int i =1;i<=max;i++) {
        if(parent[i]==i)root_s++;
    }
    printf("%d %d\n",root_s,max);
    
    scanf("%d",&q);
    int a,b;
    for(int i=0;i<q;i++) {
        scanf("%d%d",&a,&b);
        if(find_root(a) == find_root(b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

