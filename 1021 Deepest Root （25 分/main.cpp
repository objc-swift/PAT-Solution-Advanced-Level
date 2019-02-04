

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


vector<int> adjs[10001];

int colored[10001];
int n ;

void color(int node ){
    colored[node] = 1;
    for (int i =0 ; i<adjs[node].size();i++){
        int adj = adjs[node][i];
        if (!colored[adj]) {
            color(adj);
        }
    }
}

int  count_conn_compt() {
    int cnt = 0;
    for(int i = 1;i<=n ;i++) {
        if(!colored[i]) {
            ++cnt;
            color(i) ; // 开始染色
        }
    }
    return cnt;
}

void search_max (int origin , int node ,int deep ,int *max_ptr ) {
   // printf("node:%d \n",node);
    colored[node]=1;
    int isLevNode = 1 ;
    for(int i=0;i<adjs[node].size();i++) {
        int adj = adjs[node][i];
        if (!colored[adj]){
            isLevNode = 0;
            search_max(origin, adj,deep+1,max_ptr);
        }
    }
    if(isLevNode) {
        if(deep >*max_ptr){
            *max_ptr = deep;
        }
    }
}

int main(int argc, const char * argv[]) {
    memset(colored, 0, sizeof(colored));
    scanf("%d",&n);
    vector<int> max_s[10001];
    int a,b;
    for (int i = 0; i<n-1; i++) {
        scanf("%d%d",&a,&b);
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    int count = count_conn_compt();
    if (count == 1) {
       
        int b_max = 0;
        for(int i = 1;i<=n;i++) {
            int max=0;
            memset(colored, 0, sizeof(colored)); // 重置
            search_max(i,i,0,&max);
            if(max >=b_max) {
                b_max = max;
                max_s[b_max].push_back(i);
            }
        }
        
        for(int i = 0;i<max_s[b_max].size();i++) {
            printf("%d\n",max_s[b_max][i]);
            
        }
    }else {
        printf("Error: %d components\n",count );
    }
}


