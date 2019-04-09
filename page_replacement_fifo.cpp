#include<bits/stdc++.h> 
using namespace std; 

int faults(int pages[], int n, int capacity){
    unordered_set<int> s;
    queue<int> index;
    int fault = 0;

    for(int i = 0; i < n; i++){
        if(s.size() < capacity){
            if(s.find(pages[i]) == s.end()){
                s.insert(pages[i]);
                fault++;
                index.push(pages[i]);
            }
        } else {
            if(s.find(pages[i]) == s.end()){
                int temp = index.front();
                index.pop();
                s.erase(temp);
                s.insert(pages[i]);
                index.push(pages[i]);
                fault++;
            }
        }
    }

    return fault;
}

int main(){
    int pages[] = {8, 3, 2, 8, 0, 3, 0, 4, 3, 0}; 
    cout << faults(pages, 10, 3) << endl; 
    return 0; 
}