#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// ==================== FIFO (First In First Out) ====================
void fifo() {
    int n, frames;
    cout << "\n=== FIFO Page Replacement ===\n";
    cout << "Enter number of pages (reference string): ";
    cin >> n;
    
    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    cout << "Enter number of frames: ";
    cin >> frames;
    
    vector<int> frame;  // Current frames in memory
    queue<int> fifoQueue;  // Queue to track insertion order
    int pageFaults = 0,pageHit=0;
    
    cout << "\nPage\tFrames\t\t\n";
    cout << "--------------------------------------------\n";
    
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        
        // Check if page already exists in frame (Page Hit)
        bool found = false;
        for (int j = 0; j < frame.size(); j++) {
            if (frame[j] == page) {
                found = true;
                pageHit++;
                break;
            }
        }
        
        if (!found) {  // Page Fault occurs
            pageFaults++;
            
            // If frames are full, remove oldest page (FIFO logic)
            if (frame.size() == frames) {
                int oldestPage = fifoQueue.front();  // Get oldest page
                fifoQueue.pop();  // Remove from queue
                
                // Remove oldest page from frame
                for (int j = 0; j < frame.size(); j++) {
                    if (frame[j] == oldestPage) {
                        frame.erase(frame.begin() + j);
                        break;
                    }
                }
            }
            
            // Add new page to frame and queue
            frame.push_back(page);
            fifoQueue.push(page);
        }
        
        // Display current state
        cout << page << "\t";
        for (int j = 0; j < frame.size(); j++) {
            cout << frame[j] << " ";
        }
    }
    
    cout << "--------------------------------------------\n";
    cout << "Total Page Faults: " << pageFaults << "\n";
    cout << "Total Page hits: " << pageHit << "\n";
    cout << "Page Fault Rate: " << (float)pageFaults / n * 100 << "%\n";
    cout << "Hit Ratio: " << (float)pageHit / n * 100 << "%" << endl;
}

int main(){
    fifo();
    return 0;
}