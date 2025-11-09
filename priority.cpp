#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct process{
int id,at,bt,ct,tat,wt,pr;
};

void priority(){
    int n;
    cout<<"enter no.of process: ";
    cin>>n;

    vector<process>p(n);
    vector<bool>isCompleted(n,false);

    for(int i=0;i<n;i++){
        cout<<"enter arrival time: ";
        cin>>p[i].at;
        cout<<"enter burst time: ";
        cin>>p[i].bt;
        cout<<"enter priority (lower the num hihher priority): ";
        cin>>p[i].pr;
        p[i].id = i;
    }

    int cnt = 0, currTime = 0;
    double totalTAT = 0.0;
    double totalWT = 0.0;

    while (cnt < n) {
        int idx = -1;
        int highestPr = 9999;

        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && p[i].at <= currTime) {
                if (p[i].pr < highestPr) {
                    highestPr = p[i].pr;
                    idx = i;
                } else if (p[i].pr == highestPr && idx != -1 && p[i].at < p[idx].at) {
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            currTime++;
            continue;
        }

        currTime += p[idx].bt;
        p[idx].ct = currTime;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        totalTAT += p[idx].tat;
        totalWT += p[idx].wt;

        isCompleted[idx] = true;
        cnt++;
    }
    
    cout << "\n\n";
    cout << "P.ID\tAT\tBT\tCT\tTAT\tWT\tPR\n";
    cout << "-----------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\t"
             << p[i].pr << "\n";
    }

    cout << "-----------------------------------------------\n";

    cout << "Avg turn around time is: " << totalTAT << endl;
    cout << "Avg waiting around time is: " << totalWT << endl;


}

int main() {
 priority();
   return 0;
}