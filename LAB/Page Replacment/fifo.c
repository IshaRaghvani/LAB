#include <stdio.h>

#define MAX 4
int main(){

    int pages[]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n=sizeof(pages)/sizeof(pages[0]);
    int frame[MAX];
    int next,pagefaults=0;

    for (int i = 0; i < MAX; i++)
    {
        frame[i]=-1;
    }
    
    next=0;
    for (int i = 0; i < n; i++)
    {
        int flag=0;
        for (int j = 0; j <MAX; j++)
        {
            if(frame[j]==pages[i]){
                flag=1;
                break;

            }
        }
       
        if(!flag){
            frame[next]=pages[i];
            next=(next+1)%MAX;
            
            pagefaults++;
            printf("Page fault\n");


        }
        for (int k = 0; k < MAX; k++)
        {
            if(frame[k]==-1){
                printf("- ");
            }
            else 
            printf("%d ",frame[k]);
        }
    printf("\n");  
    }
    
    
   printf("\nTotal page faults: %d\n",pagefaults);

    return 0;
}