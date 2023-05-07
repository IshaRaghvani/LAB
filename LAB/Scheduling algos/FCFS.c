#include <stdio.h>

int main(){

    int n,at[10],bt[10],pos,wt[10],tt[10],ct[10],pid[10];
    printf("\n=========FCFS==========\n");
    printf("Enter no. of processes: ");
    scanf("%d",&pid[n]);
    for(int i=0;i<n;i++){
        printf("Enter arrival time for P%d :",pid[i]);
        scanf("%d",&at[i]);
        printf("Enter burst time for P%d :",pid[i]);
        scanf("%d",&bt[i]);

    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=(wt[i-1]+bt[i-1]+at[i-1]-at[i]);
        
    }
    
    for(int i=0;i<n;i++){
        tt[i]=wt[i]+bt[i];
        ct[i]=tt[i]+at[i];
    }
    printf("\nProcess_no\tArrival_Time\tBurstTime\t Waiting_Time\tTurn_Around_Time\tCompletion_Time\t\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\t\n",pid[i],at[i],bt[i],wt[i],tt[i],ct[i]);
        
    }
    


    return 0;
}