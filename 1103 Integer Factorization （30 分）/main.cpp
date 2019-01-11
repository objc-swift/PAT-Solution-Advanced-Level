

//
//  main.cpp
//  algro
//
//  Created by yxyyxy on 09/01/2019.
//  Copyright © 2019 yxy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int>list;
vector<int>temp;
int maxs = -1;
int n1 ;

int kpow(int x, int y)
{
    int res = x;
    while(-- y)
        res *= x;
    return res;
}
void dfs(int step ,int N ,int K, int P,int sum) {
    
    if( step == K ) {
        int s = 0 ;
        if(sum != n1 ) return;
        for( int i = 0 ; i <temp.size();i++ ) {
            s+=temp[i];
        }
        if ( s > maxs ) {
            list = temp;
            maxs = s ;
        }
        // 结束的状态
        return;
    }
    int n = (int)sqrt((double)N) ;
    n = temp.size()>0?temp[temp.size()-1]:n;
    for( int i = n ; i >=1; i-- ) {
        int pow_n = kpow(i, P);
        if ( sum+pow_n > N ) continue;
        temp.push_back(i);
        dfs(step +1, N, K, P,sum+pow_n);
        temp.pop_back();
    }
}
int main(int argc, const char * argv[]) {
   
    
    int N,K,P;
    scanf("%d%d%d",&N,&K,&P);
    if( N==0 || K == 0 ) {
        printf("Impossible\n");
        return 0;
    }
    n1 = N;
    dfs(0, N, K, P,0);
    int len = (int)list.size();
    if( len == K ) {
        printf( "%d = ",N );
        for( int i = 0 ;i<len ;i++ ) {
            printf("%d^%d",list[i],P);
            if( i!=len-1 ) printf(" + ");
        }
    }else {
        printf("Impossible\n");
    }
    return 0;
}


