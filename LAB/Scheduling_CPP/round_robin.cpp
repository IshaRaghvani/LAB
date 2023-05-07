#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 4;
    vector<int> id = {1, 2, 3, 4};
    vector<int> priority = {2, 4, 1, 0};
    vector<int> bt = {9, 2, 5, 7};
    int ts = 2;
    vector<int> ct(n+1);
    ct[0] = 0;
    vector<int> rem_bt = bt;
    int counter = 0, k = 0;
    while(counter<n){
        for(int i=0; i<n; ++i){
            if(rem_bt[i] == 0) continue; // Process over
            if(rem_bt[i] <= ts){ // Process time less than equal time slice
                k += rem_bt[i];
                rem_bt[i] = 0;
                counter++;
                ct[i+1] = k;
            }
            else{
                k += ts;
                rem_bt[i] -= ts;
            }
        }
    }
    vector<int> wt(n);
    for(int i=0; i<n; ++i){
        wt[i] = ct[i+1] - bt[i];
    }
    cout<<"Gantt Chart for Round Robin :"<<endl;
    cout<<"ID\tBT\tCT\tWT"<<endl;
    for(int i=0; i<n; ++i){
        cout<<id[i]<<"\t"<<bt[i]<<"\t"<<ct[i+1]<<"\t"<<wt[i]<<endl;
    }
    return 0;
}