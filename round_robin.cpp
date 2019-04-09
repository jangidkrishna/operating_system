#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id, arrival_time, burst_time, priority, waiting_time, done;

};

int main(){
    process p[10];
    int n,quantum;
    cout << "Enter no of productions: ";
    cin >> n;
    cout << "Enter quantum: ";
    cin >> quantum;

    for(int i=0; i<n; i++){
        cout << "Enter id, burst time : \n";
        cin >>p[i].id>> p[i].burst_time ;
        p[i].done = 0;
        if (i==0) {
            p[i].waiting_time = 0;
        }     
    }

    int total = 0,done = 0,i = 0;

    for(int i = 0; i < n; i++){
        total += p[i].burst_time;
    }
    
    while(done < total){
        
        cout << done <<" | P" << p[i].id << " | ";
        
        if (p[i].done + quantum < p[i].burst_time) {
            p[i].done += quantum;
            done += quantum;
        }else{
            done = done + (p[i].burst_time-p[i].done);
            p[i].done = p[i].burst_time;
        }
        
        if (i<n-1) {
            i++;
        }else{
            i=0;
        }
    }
    cout << total << endl;
    
    return 0;
}
