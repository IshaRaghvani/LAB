#include <stdio.h>

int main()
{

    int n, at[10], bt[10], pos, wt[10], tt[10], ct[10], pid[10], priority[10];
    printf("\n=========FCFS==========\n");
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter process_id: ");
        scanf("%d",&pid[i]);
        printf("Enter burst time for P%d :", pid[i]);
        scanf("%d", &bt[i]);
        printf("Enter priority for P%d :", pid[i]);
        scanf("%d", &priority[i]);
    }
    int temp;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i+1; j < n; j++)
        {
            if (priority[j] < priority[pos])
            {
                pos = j;
            }
        }
        temp=bt[pos];
        bt[pos]=bt[i];
        bt[i]=temp;

        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;


        temp=pid[pos];
        pid[pos]=pid[i];
        pid[i]=temp;

    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=0;
        for(int j=0;j<i;j++){
            wt[i]+=bt[j];
            
        }
    }
    for(int i=0;i<n;i++){
        tt[i]=bt[i]+wt[i];
    }
    printf("\nProcess_no\tBurstTime\t Waiting_Time\tTurn_Around_Time\tCompletion_Time\t\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\n",pid[i],bt[i],wt[i],tt[i],tt[i]);
        
    }
    return 0;

}
    


