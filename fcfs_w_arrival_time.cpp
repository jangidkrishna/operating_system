#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id, arrival_time, burst_time, service_time, waiting_time, turn_around;
} p[10];


void wait_time (int n){
    for(int i = 1; i < n; i++){
        p[i].service_time = p[i-1].service_time + p[i-1].burst_time;
        p[i].waiting_time = p[i].service_time - p[i].arrival_time;
        if (p[i].waiting_time < 0){
            p[i].waiting_time = 0;
        }
    }
}

void turn_around(int n){
    for (int i = 0; i < n; i++) {
        p[i].turn_around = p[i].burst_time + p[i].waiting_time;
    }
}

void print(int n){
    wait_time(n);
    turn_around(n);
    cout << "Gantt Chart\n";
    cout << "Processes " << " Burst Time " << " Arrival Time " << " Waiting Time " << " Turn-Around Time \n"; 
    for(int i = 0; i < n; i++){
        cout << "P" << p[i].id <<  "\t" << p[i].burst_time <<  "\t" << p[i].arrival_time <<  "\t" << p[i].waiting_time << "\t" << p[i].turn_around << endl;
    }
}

int main(){
    int n;
    cout << "Enter no of productions : ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Enter id, burst_time, arrival time\n";
        cin >>p[i].id>>p[i].burst_time >> p[i].arrival_time;
        if (i==0) {
            p[i].waiting_time = 0;
            p[i].arrival_time = 0;
            p[i].service_time = 0;
        }
        
    }
    print(n);
    return 0;
}
