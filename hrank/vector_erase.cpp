#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m, o, p, q, l; 
    vector<int> v;
    
    cin >> n;
    for(int ii=0; ii<n; ii++){
        cin >> m;
        v.push_back(m);
    }

    cin >> p;
    //p -= 1;
    v.erase(v.begin()+p-1);
    
    cin >> o >> p;
    v.erase(v.begin()+o-1,v.begin()+p-1);
    
    cout << v.size() << "\n";
    
    for(int ii=0; ii<v.size(); ii++){
        cout << v[ii] << " ";
    }
    
    return 0;
}
