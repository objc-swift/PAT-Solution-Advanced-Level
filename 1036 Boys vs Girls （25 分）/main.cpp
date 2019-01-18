

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
typedef struct Student {
    char name[50];
    char gender[2];
    char id[20];
    int grade;
    
    
}Student ;

int main(int argc, const char * argv[]) {
    int N;
    Student max_fmale;
    Student min_male;
    max_fmale.grade = -1;
    min_male.grade = 101;
    Student temp;
    scanf("%d",&N);
    for (int i = 0;i<N;i++) {
        scanf("%s%s%s%d",temp.name,temp.gender,temp.id,&temp.grade);
        //printf("test:%s %s %s\n",temp.name,temp.gender,temp.id);;
        if (temp.gender[0] == 'M') {
            if( temp.grade < min_male.grade )
                min_male = temp;
        }
        if(temp.gender[0] == 'F') {
            if(temp.grade > max_fmale.grade){
                max_fmale = temp;
            }
        }
    }
    int existM =0;
    int existF =0 ;
    
    if(max_fmale.grade == -1)
        printf("Absent\n");
    else {
        existF = 1;
        printf("%s %s\n",max_fmale.name,max_fmale.id);
    }
    
    if(min_male.grade == 101 ) {
        printf("Absent\n");
    }else {
        existM = 1;
        printf("%s %s\n",min_male.name,min_male.id);
    }
    
    if( existM && existF ) {
        printf("%d\n",max_fmale.grade - min_male.grade);
    }else {
        printf("NA\n");
    }
    return 0;
}


