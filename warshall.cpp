#include <bits/stdc++.h>
using namespace std;

struct process
{
    int id, alloc1,alloc2,alloc3,max1,max2,max3,need1,need2,need3;
};

int main(){
    process p[10];
    int n, avail1, avail2, avail3, work1, work2, work3;
    cout << "Enter no of productions: ";
    cin >> n;
    cout  << "Enter Avail";
    cin >> avail1 >> avail2 >> avail3;
    work1 = avail1;
    work2 = avail2;
    work3 = avail3;
    for(int i=0; i<n; i++){
        cout << "Enter id\n";
        cin >>p[i].id;
        cout << "alloc A, B, C\n";
        cin >> p[i].alloc1 >> p[i].alloc2 >> p[i].alloc3;
        cout << "max A, B, C\n";
        cin >> p[i].max1 >> p[i].max2 >> p[i].max3;
    }

    for(int i=0; i<n; i++){
        p[i].need1 = p[i].max1 - p[i].alloc1;
        p[i].need2 = p[i].max2 - p[i].alloc2;
        p[i].need3 = p[i].max3 - p[i].alloc3;
    }

    for(int i=0; i<n; i++){
        cout << p[i].need1 << " ";
        cout << p[i].need2 << " ";
        cout << p[i].need3 << endl;
    }
    

    int done_flag = 0, i = 0;
    int seq[10];
    
    while(done_flag < n+1){
        
        if(p[i].need1 <= work1 && p[i].need2 <= work2 && p[i].need2 <= work2){
            work1 += p[i].alloc1;
            work2 += p[i].alloc2;
            work3 += p[i].alloc3;
            seq[done_flag] = p[i].id;
            done_flag++;
        }
        
        if (i<n-1) {
            i++;
        }else{
            i=0;
        }
    }

    cout << "Seq : ";

    for(int j=0; j<n; j++){
        cout << "P " << seq[j] << "| ";
    }
    return 0;
}
