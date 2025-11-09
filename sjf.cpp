#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process{
    int id, at, bt, ct, tat, wt;
};


void sjf()
{   
    int n;
    cout << "enter no of process";
    cin >> n;

    vector<Process> p(n);
    vector<bool>isCompleted(n,false);
    
    for (int i = 0; i < n; i++){
        cout << "enter arrival time:";
        cin >> p[i].at;
        cout << "enter burst time:";
        cin >> p[i].bt;
        
        p[i].id = i;
    }
    
    int currentTime =0;
    int cnt=0;
    float totalTAT = 0.0;
    float totalWT = 0.0;
    
    
    while(cnt < n){
        int idx=-1;
        int minBT = 9999;
    
        for (int  i = 0; i < n; i++){
            if(!isCompleted[i] && p[i].at <= currentTime &&   p[i].bt < minBT ){
                minBT = p[i].bt;
                idx = i;
            }       
        }

        if(idx == -1){
            currentTime ++;
            continue;
        }

        currentTime+=p[idx].bt;
        p[idx].ct = currentTime;
        p[idx].tat = p[idx].ct - p[idx].at; 
        p[idx].wt = p[idx].tat - p[idx].bt; 

        totalTAT += p[idx].tat;
        totalWT += p[idx].wt;



        isCompleted[idx]  = true;
        cnt++;
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

    cout << "Avg turn around time is: " << totalTAT/(float)n << endl;
    cout << "Avg waiting around time is: " << totalWT/(float)n << endl;
}



int main()
{
 sjf();
    return 0;
}