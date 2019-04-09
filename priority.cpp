#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id, arrival_time, burst_time, priority, waiting_time;
};

bool cmp(process lhs, process rhs){
    return lhs.priority < rhs.priority;
}

int main(){
    process p[10];
    int n;
    cout << "Enter no of productions: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Enter id, burst time, priority\n";
        cin >>p[i].id>> p[i].burst_time >>p[i].priority;
        if (i==0) {
            p[i].waiting_time = 0;
        }
        
    }

    sort(p, p+n, cmp);

    p[0].waiting_time = 0;

    for(int i = 1; i < n; i++){
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
    
    cout << "Gantt Chart\n";
    for(int i = 0; i < n; i++){
        cout << "P" << p[i].id <<  " " << p[i].waiting_time << " " << p[i+1].waiting_time << endl;
    }
    
    return 0;
}
