#include <iostream>
using namespace std;

int main() {

    int n, frames;

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter number of frames: ";
    cin >> frames;

    int pages[n];
    int frame[frames];

    cout << "Enter page reference string: ";

    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "\nPage Reference String: ";

    for (int i = 0; i < n; i++) {
        cout << pages[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < frames; i++) {
    frame[i] = -1;
    }

    int pageFaults = 0;
    int pointer = 0;
    int pageHits = 0;
    for (int i = 0; i < n; i++) {

    bool found = false;

    for (int j = 0; j < frames; j++) {
        if (frame[j] == pages[i]) {
            found = true;
            break;
        }
    }

    if (!found) {

        frame[pointer] = pages[i];

        pointer = (pointer + 1) % frames;

        pageFaults++;

        cout << "Page " << pages[i] << " -> Page Fault";
    }
    else {
        pageHits++;
        cout << "Page " << pages[i] << " -> Page Hit";
    }

    cout << " | Frames: ";

    for (int j = 0; j < frames; j++) {

        if (frame[j] == -1)
            cout << "- ";
        else
            cout << frame[j] << " ";
    }

    cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
    cout << "Total Page Hits: " << pageHits << endl;

    double faultRatio = (double) pageFaults / n;
    double hitRatio = (double) pageHits / n;

    cout << "Fault Ratio: " << faultRatio << endl;
    cout << "Hit Ratio: " << hitRatio << endl;
    return 0;
}