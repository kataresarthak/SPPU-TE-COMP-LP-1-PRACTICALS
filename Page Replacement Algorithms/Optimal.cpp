#include <iostream>
using namespace std;

void Optimal() {
    int flag1, flag2, flag3, i, j, k, position, max, faults = 0;
    int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int num_frames = 4;
    int frames[num_frames];
    int temp[num_frames];
    int num_pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    cout << "Incoming\tFrame1\tFrame2\tFrame3\tFrame4\n";
    for (i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < num_pages; i++) {
        flag1 = flag2 = 0;

        for (j = 0; j < num_frames; j++) {
            if (frames[j] == incomingStream[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < num_frames; j++) {
                if (frames[j] == -1) {
                    faults++;
                    frames[j] = incomingStream[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            flag3 = 0;

            for (j = 0; j < num_frames; j++) {
                temp[j] = -1;
            }

            for (j = 0; j < num_frames; j++) {
                for (k = i + 1; k < num_pages; k++) {
                    if (frames[j] == incomingStream[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < num_frames; j++) {
                if (temp[j] == -1) {
                    position = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0) {
                max = temp[0];
                position = 0;
                for (j = 1; j < num_frames; j++) {
                    if (temp[j] > max) {
                        max = temp[j];
                        position = j;
                    }
                }
            }

            frames[position] = incomingStream[i];
            faults++;
        }

        cout << incomingStream[i] << "\t\t";
        for (j = 0; j < num_frames; j++) {
            if (frames[j] != -1)
                cout << frames[j] << "\t";
            else
                cout << "-\t";
        }
        cout << endl;
    }

    cout << "\nNumber of Page Faults: " << faults << endl;
}

int main() {
    Optimal();
    return 0;
}
