#include <iostream>
using namespace std;

void LRU() {
    int m, n, position, k, i;
    int a = 0, b = 0, page_fault = 0;
    const int total_frames = 4;
    int frames[total_frames];
    int temp[total_frames];
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int total_pages = sizeof(pages) / sizeof(pages[0]);

    for (m = 0; m < total_frames; m++) {
        frames[m] = -1;
    }

    cout << "\nIncoming\tFrame1\tFrame2\tFrame3\tFrame4\n";
    for (n = 0; n < total_pages; n++) {
        cout << pages[n] << "\t\t";
        a = 0;
        b = 0;

        for (m = 0; m < total_frames; m++) {
            if (frames[m] == pages[n]) {
                a = 1;
                b = 1;
                break;
            }
        }

        if (a == 0) {
            for (m = 0; m < total_frames; m++) {
                if (frames[m] == -1) {
                    frames[m] = pages[n];
                    b = 1;
                    page_fault++;
                    break;
                }
            }
        }

        if (b == 0) {
            for (m = 0; m < total_frames; m++) {
                temp[m] = 0;
            }

            for (k = n - 1, i = 1; i <= total_frames - 1; i++, k--) {
                for (m = 0; m < total_frames; m++) {
                    if (frames[m] == pages[k]) {
                        temp[m] = 1;
                    }
                }
            }

            for (m = 0; m < total_frames; m++) {
                if (temp[m] == 0) {
                    position = m;
                    break;
                }
            }

            frames[position] = pages[n];
            page_fault++;
        }

        for (m = 0; m < total_frames; m++) {
            if (frames[m] != -1)
                cout << frames[m] << "\t";
            else
                cout << "-\t";
        }
        cout << endl;
    }

    cout << "\nNumber of Page Faults:" << page_fault << endl;
}

int main() {
    LRU();
    return 0;
}