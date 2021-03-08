#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char pattern[] = "10101";

void fill_pattern (char * , char* );
char *check_bit_pattern (char * );

void init_zero (char * , char* );

int main(){
    char *start_addr;
    *start_addr='0';
    char *end_addr;
    end_addr+=5;
    fill_pattern(start_addr, end_addr);
    end_addr=check_bit_pattern(start_addr);

    printf("filled pattern is %s\n",start_addr);
    init_zero(start_addr, end_addr);
    printf("zeros filled pattern:%s\n",start_addr);
    return 0;
}


char *check_bit_pattern (char * start_addr){
    char *tmp;
    tmp=pattern;
    printf("\n\nchecking bit pattern");
    for(int i=0 ;i<strlen(pattern);i++){
        if(*start_addr!=*tmp)
        {
            return start_addr;
        }
        start_addr+=1;
        tmp+=1;
    }
    printf("\npattern match ..!!\n");
    return start_addr;

}
void fill_pattern (char * start_addr, char* end_addr){
    printf("Filling Pattern:\n");
    char *tmp;
    int i=0;
    tmp=pattern;
    for(;i<5;i++)
    {
     if(start_addr+i==end_addr){
         return ;
     }
     *(start_addr+i)=*(tmp+i);
    }
    printf("pattern:%s",start_addr);
    *(start_addr+i)='\0';

}
void init_zero (char * start_addr, char* end_addr){
    char *tmp;
    tmp=start_addr;
    printf("\n\nfilling all with zeros\n");
    while(start_addr!=end_addr){
        *(start_addr)='0';
        start_addr+=1;
    }
    *(start_addr-1)='\0';


}

/*
Output:
Filling Pattern:
pattern:10101

checking bit pattern
pattern match ..!!
filled pattern is 10101


filling all with zeros
zeros filled pattern:0000



*/


