#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 

void lru(){
    int n, frames;
    cout << "\n=== LRU Page Replacement ===\n";
    cout << "Enter number of pages (reference string): ";
    cin >> n;
    
    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    cout << "Enter number of frames: ";
    cin >> frames;
    
    int fault=0,hit=0; 
    vector<int>frame;
    vector<int>lastUsedIndex;


    cout << "\nPage\tFrames\t\tStatus\n";
    cout << "----------------------------------\n";

    for(int i=0;i<n;i++){
        int page = pages[i];
        
        bool found = false;
        for(int j=0;j<frame.size();j++){
            if(frame[j] == page){
                found = true;
                hit ++;
                lastUsedIndex[j]=i;
                break;
            }
        }

            if(!found){
                fault++;

                if(frame.size() < frames){
                    frame.push_back(page);
                    lastUsedIndex.push_back(i);
                }else{
                    int lruIdx = 0;
                    int minTime = lastUsedIndex[0];
                    
                    for(int k = 1;k < lastUsedIndex.size(); k++){
                        if(lastUsedIndex[k] < minTime){
                            minTime = lastUsedIndex[k];
                            lruIdx = k;
                        }
                    }
                    frame[lruIdx] = page;
                    lastUsedIndex[lruIdx] = i;        
                }
            }
        
        cout<<page<<"\t";
        for(int k=0;k<frame.size();k++){
            cout<<frame[k]<<" ";
        }
        cout << "\t" << (found ? "HIT" : "FAULT") << "\n";
    }

    cout << "--------------------------------------------\n";
    cout << "Total Page Faults: " << fault << "\n";
    cout << "Total Page hits: " << hit << "\n";
    cout << "Page Fault Rate: " << (float)fault / n * 100 << "%\n";
    cout << "Hit Ratio: " << (float)hit / n * 100 << "%" << endl;
}
int main() {
 lru();
   return 0;
}