#include<iostream>
using namespace std;

int main() {
    int bt[10], wt[10], tat[10];
    int i, n;
    int sum, awt, att;

    cout << "Enter the no of processes: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter burst time of process: ";
        cin >> bt[i];
    }

    wt[0] = 0; 
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    cout << "\nProcess BurstTime WaitingTime TurnAroundTime";
    for (i = 0; i < n; i++) {
        cout << "\nP" << i << "\t\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i];
    }

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += wt[i];
    }
    awt = sum / n;
    cout << "\nAverage Waiting Time: " << awt;

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += tat[i];
    }
    att = sum / n;
    cout << "\nAverage Turnaround Time: " << att << "\n";

    return 0;
}
