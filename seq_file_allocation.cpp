#include <bits/stdc++.h>
using namespace std;

struct file {
    int name, start, size;
};

int main(){
     
    int n, current = 0,temp_no, temp_start, temp_size;
    file files[10];
    cout << "Enter the no of Files : ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the no of file, Start Block, Length : \n";
        cin >> temp_no >> temp_start >> temp_size;
        cout << temp_no << " " << temp_size << " " << temp_start << endl;
        files[i].name = temp_no;
        files[i].size = temp_size;
        files[i].start = temp_start;   
        current = temp_size + temp_start;
        
    }

    cout << "Fileno  Start  Length" << endl;
    for (int i = 0; i < n; i++) {
        cout << files[i].name << " " << files[i].start << " " << files[i].size;
        cout << endl; 
    }
    
    return 0;

}