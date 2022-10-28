class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr.push_back(matrix[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size()+1;i++){
            if(i==k){
                return arr[i-1];
            }
        }
        return 0;
    }
};

// 1. Build an empty array
// 2. Access all the elementa from matrix and store them in the new array 'arr'
// 3. Sort the array arr in ascending order
// 4. Return the k-1th element (k-1 because counting of our array starts from 0)
