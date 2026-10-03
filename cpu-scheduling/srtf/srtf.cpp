#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int pid[n], at[n], bt[n], remaining[n], ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){
        pid[i] = i+1;
        cout<<"Enter Arrival Time and Burst Time for P"<<pid[i]<<": ";
        cin>>at[i]>>bt[i];

        remaining[i]= bt[i];
    }

    int currentTime = 0;
    int completed =0;
    int timeline[1000];
    int timelineSize = 0;

    while(completed<n){
        int shortest = -1;

        for(int i=0;i<n;i++){
            if(at[i]<= currentTime && remaining[i]> 0){
                if(shortest == -1 || remaining[i]<remaining[shortest]){
                    shortest =i;
                }
            }
        }
        if(shortest == -1){
            currentTime++;
            continue;
        }
        timeline[timelineSize] = shortest;
        timelineSize++;
        remaining[shortest]--;
        currentTime++;

        if(remaining[shortest] == 0){
            ct[shortest] = currentTime;

            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            
            completed++;
        }
    }

    double totalWt =0;
    double totalTAT =0;
    for(int i=0;i<n;i++){
        totalWt +=wt[i];
        totalTAT += tat[i];
    }

    double avgWt= totalWt/n;
    double avgTAT = totalTAT/n;

    cout<<"\nSRTF Scheduling Result\n";
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i=0; i<n; i++){
        cout<<"P"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    cout<<"\nGantt Chart:\n";
    cout<< "| P"<<pid[timeline[0]];

    for(int i=1;i<timelineSize;i++){
        if(timeline[i] !=timeline[i-1]){
            cout<<" | P"<< pid[timeline[i]];
        }
    }

    cout<<" |\n";
    cout<<"0";
    int time =0;
    for(int i=0;i<timelineSize;i++){
        time++;
        if(i== timelineSize -1 || timeline[i] != timeline[i+1]){
            cout<<"   "<<time;
        }
    }

    cout<<"\nAvarage Waiting Time: "<< avgWt<<endl;
    cout<<"Avarage Turnaround Time: "<<avgTAT <<endl;
    return 0;
}