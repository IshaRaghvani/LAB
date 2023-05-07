#include <stdio.h>

int main(){

    int n=5;
    int m=3;
    int allocation[5][3]={ {0 ,1 ,0},
                           {2 ,0, 0}, 
                           {3 ,0, 2},
                           {2 ,1, 1},
                           {0, 0, 2}};

    int max_matrix[5][3] = { { 7, 5, 3 },   // P0 
                             { 3, 2, 2 },   // P1
                             { 9, 0, 2 },   // P2
                             { 2, 1, 2 },   // P3
                             { 4, 3, 3 } }; // P4


    int available[3]={3 ,3 ,2};
    int finish[5];
    int safeseq[5];

    //initailaize finish matrix
    for (int i = 0; i < n; i++)
    {
        finish[i]=0;
    }

    //make the need matrix
    int need[n][m];
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
           need[i][j]=max_matrix[i][j]-allocation[i][j];
        }
        
    }

    int count =0;
    int index=0;
    while(count<n){
        int found=0;
        for (int i = 0; i < n; i++)
        {
            
            if(!finish[i]){
                int enough=1;
                for (int j = 0; j <m; j++)
                {
                    if(need[i][j]>available[j]){
                        enough=0;
                        break;
                    }
                }
                if(enough){
                    for (int j = 0; j < m; j++)
                    {
                        available[j]+=allocation[i][j];
                    }
                    finish[i]=1;
                    safeseq[index++]=i;
                    found=1;
                    count++;

                }
                

            }
            
        
        }
        if(!found){
            printf("\nSystem is not safe");
            return 0;

        }
        
    }
    printf("\nSystem is safe!");
    printf("Safe sequence: ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ",safeseq[i]);
    }
    printf("\n");
    return 0;
}