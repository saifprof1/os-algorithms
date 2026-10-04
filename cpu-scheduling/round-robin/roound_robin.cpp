#include <iostream>
using namespace std;

int main() {

    int n, timeQuantum;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;

    int pid[n];
    int at[n];
    int bt[n];

    for (int i = 0; i < n; i++) {

        pid[i] = i + 1;

        cout << "Enter Arrival Time and Burst Time for P" << pid[i] << ": ";
        cin >> at[i]>> bt[i];
    }

    cout << "\nProcess Information:\n";

    cout << "PID\tAT\tBT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << endl;
    }

    int remaining[n];
    int ct[n];
    int tat[n];
    int wt[n];

    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
        ct[i] = 0;
        tat[i] = 0;
        wt[i] = 0;
        }

        int currentTime = 0;
        int completed = 0;
        int currentIndex = 0;

        while (completed < n) {
            int nextProcess = -1;

            for (int i = 0; i < n; i++) {
                int index = (currentIndex + i) % n;

                if (remaining[index] > 0 && at[index] <= currentTime) {
                    nextProcess = index;
                    break;
                    }
                }

                if (nextProcess == -1) {
                    currentTime++;
                    continue;
                 }
                currentIndex = nextProcess;

                int executionTime;

                if (remaining[currentIndex] > timeQuantum) {
                    executionTime = timeQuantum;
                    }
                else {
                    executionTime = remaining[currentIndex];
                     }

    cout << "P" << pid[currentIndex]
         << " executes from "
         << currentTime << " to "
         << currentTime + executionTime << endl;

    remaining[currentIndex] -= executionTime;

    currentTime += executionTime;

    if (remaining[currentIndex] == 0) {
        ct[currentIndex] = currentTime;
        completed++;
        }

    currentIndex = (currentIndex + 1) % n;
}
for (int i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
}
double totalWT = 0;
double totalTAT = 0;
for (int i = 0; i < n; i++) {
    totalWT += wt[i];
    totalTAT += tat[i];
}
double averageWT = totalWT / n;
double averageTAT = totalTAT / n;
cout << "\nCompletion Time:\n";

cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";

for (int i = 0; i < n; i++) {
    cout << "P" << pid[i] << "\t"
     << at[i] << "\t"
     << bt[i] << "\t"
     << ct[i] << "\t"
     << tat[i] << "\t"
     << wt[i] << endl;
}
cout << "\nAverage Waiting Time: "
     << averageWT << endl;

cout << "Average Turnaround Time: "
     << averageTAT << endl;

    return 0;
}