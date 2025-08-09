// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code he
    vector<int> v {3,1,2};
    sort(v.begin(),v.end()-2);
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << endl;
    }
    return 0;
}