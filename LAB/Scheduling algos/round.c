#include <stdio.h>

int main()
{

    int n, at[10], bt[10], pos, tt[10], ct[10], pid[10], time, y, temp_bt[10];
    printf("\n=========round robin==========\n");
    printf("Enter no. of processes: ");

    scanf("%d", &n);
    y = n;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter arrival time and burst time for P%d :", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        temp_bt[i] = bt[i];
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &time);
    int sum=0; // store sum of all bts
    int i;
    int comp_process=0;

    printf("\nProcess_id\t\tArrival Time\tBurst Time\t TurnAroundTime\t\tWaiting Time\n");
    for (sum = 0, i = 0; y != 0;)
    {

        // check if bt<time
        if (temp_bt[i] <= time && temp_bt[i] > 0)
        {

            sum = sum + temp_bt[i];
            temp_bt[i] = 0;
            comp_process = 1;
        }
        // else check if bt>0
        else if (temp_bt[i] > 0)
        {
            temp_bt[i] = temp_bt[i] - time;
            sum = sum + time;
        }
        // if bt=0 that is process is completed print it
        if (temp_bt[i] == 0 && comp_process == 1)
        {

            y--;
            printf("P%d\t\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], sum - at[i], sum - at[i] - bt[i]);
            comp_process=0;
        }
        if(i==n-1){
            i=0;
        }
        else if(at[i+1]<=sum){
            i++;
        }
        else{
            i=0;
        }
    }
    printf("\n");
    return 0;
}