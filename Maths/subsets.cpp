#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> valid;
void gS(vector<int> &subset, vector<int> &v, int i){
    if(i==v.size()){
        valid.push_back(subset);
        return;
    }
    gS(subset, v, i+1);
    subset.push_back(v[i]);
    gS(subset, v, i+1);
    subset.pop_back();
}



int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> subset;
    gS(subset, v,0);
    for (const auto& row : valid) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
    
}
