#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Process {
    int id, at, bt, ct, tat, wt, remBT;
};
// bool cmp(const Process &a, const Process &b) {
//     return a.at < b.at;
// }
void rr() {
    int n, tq;
    cout << "enter n: ";
    cin >> n;

    cout << "enter time quantam: ";
    cin >> tq;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "enter at: ";
        cin >> p[i].at;
        cout << "enter bt: ";
        cin >> p[i].bt;
        p[i].id = i + 1;
        p[i].remBT = p[i].bt;
    }
    //sort(p.begin(), p.end(), cmp);
    sort(p.begin(), p.end(), []( Process &a,  Process &b) {
        return a.at < b.at;
    });

    int cnt = 0;
    float totTAT = 0.0;
    float totWT = 0.0;
    int CPUtime = 0;

    queue<int> q;
    int i = 0;

    while (cnt < n) {
        while (i < n && p[i].at <= CPUtime) {
            q.push(i);
            i++;
        }

        if (q.empty()) {
            CPUtime++;
            continue;
        }

        int cur = q.front();
        q.pop();

        int runTime = min(tq, p[cur].remBT);
        CPUtime += runTime;
        p[cur].remBT -= runTime;

        while (i < n && p[i].at <= CPUtime) {
            q.push(i);
            i++;
        }

        if (p[cur].remBT == 0) {
            p[cur].ct = CPUtime;
            p[cur].tat = p[cur].ct - p[cur].at;
            p[cur].wt = p[cur].tat - p[cur].bt;
            totTAT += p[cur].tat;
            totWT += p[cur].wt;
            cnt++;
        } else {
            q.push(cur);
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\n";
    }

    cout << "\nAverage TAT = " << (totTAT / n);
    cout << "\nAverage WT = " << (totWT / n) << endl;
}
int main() {
    rr();
    return 0;
}