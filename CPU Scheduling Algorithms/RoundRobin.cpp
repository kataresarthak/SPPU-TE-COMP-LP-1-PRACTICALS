#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int arr[20], awt[10], no, ch;
    int tat[30], pro[30], rr[30], pro1[30], bt[30], flag[15], flag1[20], gc[20];
    int i, j, k, at, sum, tq, rnd_up, a = 0;
    float avg, temp;
    at = sum = temp = 0;

    cout << "\nEnter the number of processes: ";
    cin >> no;

    cout << "\nEnter the time quantum: ";
    cin >> tq;

    for(i = 0; i < no; i++)
    {
        cout << "\nEnter the process number, burst time: ";
        cin >> pro[i] >> arr[i];
        flag[i] = flag1[i] = gc[i] = 0;
        bt[i] = arr[i];
        if(temp <= arr[i])
            temp = arr[i];
    }

    temp = temp / tq;
    rnd_up = ceil(temp);
    k = 0;
    rr[k] = 0;
    for(i = 0; i < rnd_up; i++)
    {
        for(j = 0; j < no; j++)
        {
            if(arr[j] != 0)
            {
                if(arr[j] >= tq)
                {
                    rr[++k] = tq;
                    pro1[k-1] = pro[j];
                    arr[j] = arr[j] - tq;
                }
                else
                {
                    rr[++k] = arr[j];
                    pro1[k-1] = pro[j];
                    arr[j] = 0;
                }
            }
        }
    }
    for(i = 1; i <= k; i++)
    {
        arr[i] = arr[i-1] + rr[i];
    }

    cout << "\nGANTT CHART";
    cout << "\n--------------------------------\n";
    for(i = 0; i < k; i++)
    {
        cout << "| P" << pro1[i];
    }
    cout << "|";
    cout << "\n--------------------------------\n";
    for(i = 0; i <= k; i++)
        cout << arr[i] << "   ";

    cout << "\n--------------------------------\n";
    for(i = 0; i < no; i++)
    {
        a = i;
        gc[i] = gc[i] + arr[a];
        for(j = i + 1; j < k; j++)
        {
            if(pro1[j] == pro1[i])
            {
                gc[i] = gc[i] + arr[j] - arr[a + 1];
                a = j;
                flag[i] = 1;
            }
        }
        tat[i] = arr[a + 1];
        a = 0;
    }

    for(i = 0; i < no; i++)
    {
        if(flag[i] == 0)
        {
            gc[i] = arr[i];
        }
    }
    cout << "\nProcess\tBurst time\tWaiting time\tTurnaround Time";
    for(i = 0; i < no; i++)
    {
        cout << "\nP" << pro[i] << "\t" << bt[i] << "\t" << gc[i] << "\t" << tat[i];
    }

    sum = 0;
    for(i = 0; i < no; i++)
    {
        sum = sum + gc[i];
    }
    avg = sum / (float)no; 
    cout << "\nAverage Waiting Time :" << fixed << setprecision(2) << avg;

    sum = 0;
    for(i = 0; i < no; i++)
    {
        sum = sum + tat[i];
    }
    avg = sum / (float)no;
    cout << "\nAverage Turnaround Time :" << fixed << setprecision(2) << avg;

    return 0;
}