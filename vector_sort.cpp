#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    vector<int>v; 
    
    cin >> n;
    for (int ii=0; ii<n; ii++){
        cin >> m;
        v.push_back(m);
    }
    
    sort(v.begin(),v.end());
    
    for (int ii=0; ii<n; ii++){
        cout << v[ii] << " ";
    }
    return 0;
}
