

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
#include <stdlib.h>
#include <memory.h>
#define MAX 1000000
using namespace std;
long int vis[MAX];

vector<long int> list ;
int isPrime(long int x ,long int *factor ) {
    int  is = 1;
    long int m = (long int)sqrt(x)+1;
    for( long int i = 2 ; i< m ;i++)
    {
        if ( x % i == 0 ) {
            is = 0 ;
            *factor = i;
            break;
        }
    }
    return is;
}
long int  getMax (long int a , long int b ) {
    return a>b?a:b;
}
void de_split (long int value ) {
    long int factor ;
    int isValuePrime = isPrime(value, &factor);
    if( isValuePrime ) {
        list.push_back(value);
    }else{
        de_split(factor); //递归分解其中一个因子
        de_split(value/factor); //递归分解另一个因子
    }
}
int main(int argc, const char * argv[]) {
   
    memset(vis, 0, MAX);
    
    long int x ;
    scanf("%ld",&x);
    de_split(x);
    unsigned long real_size = list.size();
    for( int i = 0 ; i < list.size();i++ ){
        if( vis[list[i]] ) {
            real_size--;
        }
        vis[list[i]]++;
    }

    printf("%ld=",x);
    int cnt = 0;
    
    for(int i =0;i<MAX;i++) {
        if( vis[i]>=1 ) {
            if( vis[i] == 1  ){
                printf("%d",i);
            }else {
                printf("%d^%ld",i,vis[i]);
            }
            ++cnt;
            if( cnt !=real_size)
                printf("*");
        }
    }
    
    printf("\n");
    
    return 0;
}


