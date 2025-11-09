#include <iostream>
#include <vector>
using namespace std;

void optimal() {
    int n, frameSize;
    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter frame size: ";
    cin >> frameSize;

    vector<int> frame;
    int faults = 0, hits = 0;

    // Loop through each page in the reference string
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;

        // Check if page already in frame
        for (int j = 0; j < frame.size(); j++) {
            if (frame[j] == page) {
                found = true;
                hits++;
                break;
            }
        }

        // If not found, replace optimally
        if (!found) {
            faults++;

            // If frame not full, just add it
            if (frame.size() < frameSize) {
                frame.push_back(page);
            } 
            else {
                // Find which page to replace
                int farthest = i + 1;
                int idx = -1;

                for (int j = 0; j < frame.size(); j++) {
                    int nextUse = -1;

                    // Find when this frame page will be used next
                    for (int k = i + 1; k < n; k++) {
                        if (pages[k] == frame[j]) {
                            nextUse = k;
                            break;
                        }
                    }

                    // If not used again, replace this immediately
                    if (nextUse == -1) {
                        idx = j;
                        break;
                    }

                    // Otherwise, track the page used farthest in the future
                    if (nextUse > farthest) {
                        farthest = nextUse;
                        idx = j;
                    }
                }
                frame[idx] = page;
            }
        }

        // Print current frame status
        cout << "Step " << i + 1 << " -> Page: " << page << " | ";
        for (int j = 0; j < frame.size(); j++)
            cout << frame[j] << " ";
        cout << "\t" << (found ? "HIT" : "FAULT") << endl;
    }

    cout << "\nTotal Page Faults: " << faults << endl;
    cout << "Total Page Hits: " << hits << endl;
    cout << "Fault Ratio: " << (float)faults / n * 100 << "%" << endl;
    cout << "Hit Ratio: " << (float)hits / n * 100 << "%" << endl;
}

int main() {
    optimal();
    return 0;
}
