/ Binary Index Tree (Fenwick tree) is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.
//
// Time Complexity:
// * O(logn) for updating and querying
// * O(n) for building the tree
//


#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int getSum(int BITree[], int index)
{
    int sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
       BITree[index] += val;
       index += index & (-index);
    }
}

int *constructBITree(int arr[], int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    return BITree;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *BITree = constructBITree(arr, n);
    cout << "Sum of elements in arr[0..5] is " << getSum(BITree, 5);
    arr[3] += 6;
    updateBIT(BITree, n, 3, 6);
    cout << "Sum of elements in arr[0..5] after update is " << getSum(BITree, 5);
    return 0;
}
