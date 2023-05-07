#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 4;
    vector<int> id = {1, 2, 3, 4};
    vector<int> bt = {9, 2, 5, 7};
    // Sorting the processes according to the Burst Time
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(bt[j]<bt[i]){
                // Swapping burst time
                int temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
                // Swapping process id
                temp = id[j];
                id[j] = id[i];
                id[i] = temp;
            }
        }
        
    }
    vector<int> ct(n+1);
    ct[0] = 0;
    for(int i=1; i<=n; ++i){
        ct[i] = ct[i-1] + bt[i-1];
    }
    vector<int> wt(n);
    for(int i=0; i<n; ++i){
        wt[i] = ct[i+1] - bt[i];
    }
    cout<<"Gantt Chart for SJF (Non-Preemptive) :"<<endl;
    cout<<"ID\tBT\tCT\tWT"<<endl;
    for(int i=0; i<n; ++i){
        cout<<id[i]<<"\t"<<bt[i]<<"\t"<<ct[i+1]<<"\t"<<wt[i]<<endl;
    }
    return 0;
}