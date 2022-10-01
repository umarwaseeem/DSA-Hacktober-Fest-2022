// find the subset with the given sum, if exists
// count how many such subsets are there

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findways(string ans, vector<int> v, int idx, int target)
{
    // base case
    if (idx == v.size())
    {
        if (target == 0)
        {
            cout << ans << endl;
            ans = "";
            return 1;
        }
        return 0;
    }

    // recursive case
    int include = findways(ans + to_string(v[idx]) + ' ', v, idx + 1, target - v[idx]);
    int exclude = findways(ans, v, idx + 1, target);

    return include + exclude;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    string ans = "";
    cout << findways(ans, v, 0, 6);
}