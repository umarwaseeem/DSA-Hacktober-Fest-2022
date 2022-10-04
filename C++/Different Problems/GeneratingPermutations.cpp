#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {4, 5, 1, 2, 3};

    // To generate all permutations, we first need to sort the array in non-decreasing order
    sort(arr.begin(), arr.end());
    do {
        cout << "{ ";
        for(auto &i: arr) cout << i << " ";
        cout << "}\n";
    } while (next_permutation(arr.begin(), arr.end()));
}