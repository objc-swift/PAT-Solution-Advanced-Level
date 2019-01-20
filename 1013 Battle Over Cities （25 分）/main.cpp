

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
int edge[1001][1001];
int vis[1001];
int n,m,k;
void dfs( int node ) {
    vis[node]=1;
    for(int i =1;i<=n;i++) {
        if( edge[node][i] && !vis[i] ) {
            dfs(i);
        }
    }
}
int main(int argc, const char * argv[]) {

    memset(vis, 0,sizeof(vis));
    memset(edge, 0,sizeof(edge));
    
    scanf("%d%d%d",&n,&m,&k);
    int res[1001];
    
    int a,b,ki;
    for(int i =0 ;i<m;i++) {
        scanf("%d%d",&a,&b);
        edge[a][b]=1;
        edge[b][a]=1;
    }
    for( int i =0; i<k;i++ ) {
        scanf("%d",&ki);
        memset(vis, 0, sizeof(vis)); // default
        vis[ki] = 1;
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(!vis[j]) {
                dfs(j);
                cnt++;
            }
            res[i] = cnt;
        }
    }
    for(int j=0;j<k;j++) {
        printf("%d\n",res[j]-1);
        
    }
}


