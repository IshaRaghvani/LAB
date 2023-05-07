#include <stdio.h>

int main()
{
    int p[10], burst_time[50], arrival_time[10], n, pos, temp;
    printf("=========================================================================\n");
    printf("FCFS - Isha Raghvani CS-B\n");
    printf("=========================================================================\n");
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter process_id: ");
        scanf("%d",&p[i]);
        printf("Enter arrival time for process P%d: ",p[i]);
        scanf("%d",&arrival_time[i]);
        printf("Enter burst time for process P%d: ",p[i]);
        scanf("%d",&burst_time[i]);
    }
    //sorting the burst time
    for(int i=0;i<n;i++){
        pos=i;
        for(int j=i+1;j<n;j++){
            if(arrival_time[j]<arrival_time[pos]){
                pos=j;
            }
        }
        //swapping the burst time
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
        
        //swapping the processes with ids
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

        //swapping the arrival time
        temp=arrival_time[i];
        arrival_time[i]=arrival_time[pos];
        arrival_time[pos]=temp;
    }
    int wait_time[10];
    wait_time[0]=0;
    
    for(int i=1;i<n;i++){
        wait_time[i]=0;
        for(int j=0;j<i;j++){
            wait_time[i]+=burst_time[j];
        }
    }
    
    printf("\n=========================================================================\n");
    printf("\nProcess \t Arrival Time \t Burst Time \t Wait time \t Turn Around time\t\n");
    printf("\n=========================================================================\n");
    for(int i=0;i<n;i++){
        printf("P%d",p[i]);
        printf("\t\t%d",arrival_time[i]);
        printf("\t\t%d",burst_time[i]);
        printf("\t\t%d",wait_time[i]);
        printf("\t\t%d", wait_time[i]+burst_time[i]);
        printf("\n");
    }
}
