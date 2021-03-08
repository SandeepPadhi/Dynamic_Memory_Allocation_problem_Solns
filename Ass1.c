#include<stdio.h>
#include<stdlib.h>

void * my_calloc (size_t nmemb, size_t size);
void my_free (void * ptr);
void * my_malloc(size_t size);
size_t free_space_in_my_heap (void);
void * my_realloc (void * ptr, size_t size);//Implementation is optional
void deframent_my_heap (void); //Implementation is optional
/*
1-my_calloc
2-my-free
3-my-malloc
4-my-relloc
*/

int main(){
    FILE *ptr;
    int *num,n;
    size_t sumtotal=0;
    size_t mem_size,mem_no;
    ptr=fopen("input_ass1.txt","r");
    fscanf(ptr,"%d",&n);
    while(n>0){
        int op_no;
        fscanf(ptr,"%d",&op_no);
        if (op_no==1)
        {   
            size_t ele,ele_size,sum,s;
            printf("my_malloc fn:\n");
            fscanf(ptr,"%zu %zu",&ele,&ele_size);
            num=(int*)my_malloc(ele*ele_size);
            mem_no=ele;
            mem_size=ele_size;
            printf("adding : ");
            for(int i=0;i<ele;i++)
            {
                fscanf(ptr,"%d",num+i);
                printf("%d ",*(num+i));
                sum += (size_t) *(num+i);
            }
            sumtotal=sum;
            printf("\nsum is %zu\n",sum);
        }
        else if(op_no==2){
            printf("my_free fn:\n");
            my_free(num);

        }
        else if (op_no==3)
        {
            size_t ele,ele_size,sum,s;
            printf("my_calloc fn:\n");
            fscanf(ptr,"%zu %zu",&ele,&ele_size);
            mem_no=ele;
            mem_size=ele_size;
            sum=0;
            num=(int *)my_calloc(ele,ele_size);
            printf("Adding : ");

            for(size_t i=0;i<ele;i++)
            {
                fscanf(ptr,"%d",num+i);
                printf("%d ",*(num+i));
                sum += (size_t) *(num+i);
            }
            sumtotal=sum;
            printf("\nsum is %zu\n",sum);
        }
        else if (op_no==4)
        {
            size_t extra,s;
            size_t size;
            printf("my_realloc fn:\n");
            fscanf(ptr,"%zu",&extra);
            num=(int *)my_realloc((void *)num,(int)(mem_no+extra)*(int)mem_size);
            printf("Adding : ");
            for(int i=(int)mem_no;i<(int)(mem_no+extra);i++){
                fscanf(ptr,"%d",num+i);
                printf("%d ",*(num+i));
                sumtotal += (size_t)*(num+i);

                
            }
            printf("\nnew sum is %zu",sumtotal);
        }
        n-=1;
        printf("\n");
    }
    fclose(ptr);

    return 0;
}
void * my_calloc (size_t nmemb, size_t size){
    void *ptr =(void *)calloc(nmemb,size);
    return ptr;
}

void my_free (void * ptr){
    free(ptr);
}

void * my_malloc(size_t size){
 return (void*)malloc(size);    
}

void * my_realloc (void * ptr, size_t size)//Implementation is optional
{
    return realloc(ptr,size);
}

/*

Output:
my_malloc fn:
adding : 1 2 3 4 5
sum is 15

my_free fn:

my_calloc fn:
Adding : 1 2 3 4
sum is 10

my_realloc fn:
Adding : 3 4
new sum is 17
my_free fn:

*/

