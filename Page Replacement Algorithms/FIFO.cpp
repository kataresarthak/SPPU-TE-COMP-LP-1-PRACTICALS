#include <iostream>
using namespace std;

void FIFO() {
    int incomingStream[] = {1, 3, 0, 3, 5, 6, 3};
    int pageFaults = 0;
    int frames = 3;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int temp[frames];

    cout << "Incoming \t Frame 1 \t Frame 2 \t Frame 3\n";
    for (int m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    for (int m = 0; m < pages; m++) {
        int s = 0;
        for (int n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s++;
                pageFaults--;
                break;
            }
        }

        pageFaults++;
        if ((pageFaults <= frames) && (s == 0)) {
            temp[pageFaults - 1] = incomingStream[m];
        }
        else if (s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        cout << incomingStream[m] << "\t\t";
        for (int n = 0; n < frames; n++) {
            if (temp[n] != -1)
                cout << temp[n] << "\t\t";
            else
                cout << "-\t\t";
        }
        cout << endl;
    }
    cout << "\nTotal Page Faults:" << pageFaults << endl;
}

int main() {
    FIFO();
    return 0;
}