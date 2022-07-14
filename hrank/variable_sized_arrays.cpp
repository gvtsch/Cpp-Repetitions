#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;   
    cin >> n >> q;
    int* arr[n];
    // Eingabe der Arrays
    for (int i = 0; i < n; i++){
        int k, a;
        cin >> k;
        arr[i] = new int[k];
        for(int j = 0; j < k; j++){
            scanf("%d", &a);
            arr[i][j] = a;
        }
    }
    
    int i, j;
    for(int ii=0;ii<q;ii++){
        cin >> i >> j;
        cout << arr[i][j] << endl;
    }
}
