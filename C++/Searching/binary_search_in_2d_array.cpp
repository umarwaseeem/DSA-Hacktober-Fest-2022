//SOLUTION TO A FAMOUS LEETCODE PROBLEM , https://leetcode.com/problems/search-a-2d-matrix/ 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        int start = 0;
        int end  = row_size*col_size-1;
        
        int mid = start + (end-start)/2;
        
        while(start<=end) {
            
            int temp = matrix[mid/col_size][mid%col_size];
            
            if(temp == target) {
                return 1;
            }
            
            if(temp < target) {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
             mid = start + (end-start)/2;    
        }
        return 0;
    }
};