#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


#define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin


/*Write the class AddElements here*/
template <typename T>
class AddElements {
    public:
    T element; // Das Element, welches dann addiert / concatenated wird
    AddElements(T arg){ // Im ersten Aufruf wird das erste Element hier gesetzt
        element = arg;
        }; 
    T add(T arg){ // Hier werden Ints/floats addiert
        return element+arg;
        }; 
    T concatenate(T arg){ // Hier strings
        return element+arg;
        };
};



int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
