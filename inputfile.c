#include <stdio.h>

int main(){
    FILE *ptr;
    int num,n;
    ptr=fopen("input.txt","r");
    fscanf(ptr,"%d",&n);
    while(n>0){
        int i=3;
        while(i>0){
            fscanf(ptr,"%d",&num);
            printf("num:%d",num);
            i-=1;
        }
        n-=1;
        printf
    }
    fclose(ptr);

    return 0;
}