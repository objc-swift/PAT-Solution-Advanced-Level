#include<iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
typedef struct edge {
    int from ;
    int to;
} edge ;
int color[10000 +5];

int main(){
    int n,m,k;
    vector<edge> edges ;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        edge e  ;
        scanf("%d%d",&e.from,&e.to);
        edges.push_back(e);
    }
    scanf("%d",&k);
    for(int i= 0;i<k ; i++){
        int isVaild = 1 ;
        set<int> _set ;
        for (int j = 0; j<n ;j++) {
            scanf("%d",color+j);
            _set.insert(color[j]);
        }
        for(int y =0;y<edges.size();y++) {
            if( color[edges[y].from] == color[edges[y].to] ) {
                isVaild = 0 ;break;
            }
            // 判断结点
        }
        if (isVaild ){
            printf("%lu-coloring\n",_set.size());
        }else {
            printf("No\n");
        }
        
    }
    return 0;
}
