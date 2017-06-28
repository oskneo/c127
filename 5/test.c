#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aa{
    int a[2];
    long c;
    int b;
    
};

int main(void){
    
    struct aa *aaa=malloc(sizeof(struct aa));
    aaa->a[0]=100000;
    aaa->a[1]=2;
    aaa->c=0xffffffff0;
    aaa->b=3;
    printf("show b=%ld,%ld\n",*(&(aaa->c)+1),sizeof(int*));
    
    return 0;
}