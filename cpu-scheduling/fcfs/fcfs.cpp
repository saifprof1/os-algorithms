#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int pid[n],at[n],bt[n];
    int ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        pid[i]  = i+1;
        cout<<"Enter Arrival Time for p"<<pid[i]<<": ";
        cin>>at[i];
        cout<<"Enter Burst Time for p"<<pid[i]<<": ";
        cin>>bt[i];
    }

    int cTime = 0;
    for(int i=0;i<n;i++){
        if(cTime<at[i]){
            cTime = at[i];
        }
        cTime+=bt[i];
        ct[i]=cTime;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    double totalWT =0;
    double totalTAT =0;
    for(int i=0;i<n;i++){
        totalWT += wt[i];
        totalTAT += tat[i];
    }
    double avgWT = totalWT/n;
    double avgTAT = totalTAT/n;

    cout<<"\nFCFS Scheduling Rsult:\n";
    cout<<"PID\tAT\tBt\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<"p"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    cout<<"\nGantt Chart:\n";
    cout<<" ";
    for(int i=0;i<n;i++){
        cout<<"----------";
    }
    cout<<"-\n";

    cout<<"|";
    for(int i=0;i<n;i++){
        cout<<"   p"<<pid[i]<<"   |";
    }
    cout<<"\n";

    cout<<" ";
    for(int i=0;i<n;i++){
        cout<<"----------";
    }
    cout<<"-\n";

    cout<<at[0];
    for(int i=0;i<n;i++){
        cout<<"       "<<ct[i];
    }

    cout<<endl;

    cout<<"\nAverage Waiting Time: "<<avgWT <<endl;
    cout<<"Avarage Turnaround Time: "<<avgTAT<<endl;
    return 0;
}