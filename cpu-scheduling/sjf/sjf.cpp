#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;

    int pid[n], at[n], bt[n];
    int ct[n], tat[n], wt[n];
    bool comleted[n] = {false};

    for(int i=0;i<n;i++){
        pid[i]= i+1;
        cout<<"Enter Arrival Time and Burst Time for P"<<pid[i]<<": ";
        cin>> at[i]>> bt[i];
    }

    int currentTime=0;
    int completedCount =0;

    while(completedCount<n){
        int shortest = -1;

        for(int i=0;i<n;i++){
            if(!comleted[i] && at[i] <= currentTime){
            if(shortest == -1 || bt[i]<bt[shortest]){
                shortest =i;
            }
        }
        }
        if(shortest == -1){
            currentTime++;
            continue;
        }

        currentTime += bt[shortest];

        ct[shortest] = currentTime;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        comleted[shortest] = true;
        completedCount++;
    }

    double totalWt = 0;
    double totalTAT = 0;

    for(int i =0;i<n;i++){
        totalTAT += tat[i];
        totalWt += wt[i];
    }

    double avgWt = totalWt /n;
    double avgTAT = totalTAT/n;

    cout<<"\nSJF Scheduling Result:\n";
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i=0;i<n;i++){
        cout<<"p"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    cout<<"\nAvarage Waiting Time: "<<avgWt <<endl;
    cout<<"Avarage Turnaround Time: "<<avgTAT <<endl;
    return 0;
}