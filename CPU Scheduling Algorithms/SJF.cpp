#include <iostream>
using namespace std;

int main() {
    int p[10], bt[10], wt[10], tat[10];
    int i, j, n, temp;
    int sum, awt, att;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter burst time of process: ";
        cin >> bt[i];
        p[i] = i;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    cout << "\nProcess\tBurstTime\tWaitingTime\tTurnAroundTime";
    for (i = 0; i < n; i++) {
        cout << "\nP" << p[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i];
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
