#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 4;
    vector<int> at = {0, 1, 2, 3};
    vector<int> bt = {9, 2, 5, 7};
    vector<int> ct(n+1);
    ct[0] = 0;
    for(int i=1; i<=n; ++i){
        ct[i] = ct[i-1] + bt[i-1];
    }
    vector<int> tat(n);
    for(int i=0; i<n; ++i){
        tat[i] = ct[i+1] - at[i];
    }
    vector<int> wt(n);
    for(int i=0; i<n; ++i){
        wt[i] = tat[i] - bt[i];
    }
    cout<<"Gantt Chart for FCFS :"<<endl;
    cout<<"ID\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(int i=0; i<n; ++i){
        cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i+1]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }
    return 0;
}