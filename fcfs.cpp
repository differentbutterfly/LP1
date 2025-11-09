#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process
{
    int id, at, bt, ct, tat, wt;
};

// fcfs

// bool cmp(const Process &a, const Process &b) {
//     return a.at < b.at;
// }
void fcfs()
{
    int n;
    cout << "enter no of process";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++)
    {
        cout << "enter arrival time:";
        cin >> p[i].at;
        cout << "enter burst time:";
        cin >> p[i].bt;

        p[i].id = i;
    }
    //sort(p.begin(), p.end(), cmp);
    sort(p.begin(), p.end(), [](Process &a, Process &b){
        if(a.at == b.at) return a.id < b.id;

        return a.at < b.at; 
    });

    int currentTime = 0;
    int totalTAT = 0;
    int totalWT = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentTime < p[i].at)
        {
            currentTime = p[i].at;
        }
        currentTime += p[i].bt;
        p[i].ct = currentTime;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }
    cout << "\n\n";
    cout << "P.ID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "-----------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\n";
    }

    cout << "-----------------------------------------------\n";

    cout << "Avg turn around time is: " << totalTAT << endl;
    cout << "Avg waiting around time is: " << totalWT << endl;
}

int main()
{
    fcfs();
    return 0;
}