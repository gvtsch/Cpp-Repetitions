#include <iostream>
#include <string>
using namespace std;

int main() {
    // Complete the program
    string a, b;
    cin >> a >> b;
    cout << a.length() << " " <<  b.length() << "\n";
    cout << a + b << "\n";
    cout << b[0] + a.substr(1) << " " << a[0] + b.substr(1);
    return 0;
}
