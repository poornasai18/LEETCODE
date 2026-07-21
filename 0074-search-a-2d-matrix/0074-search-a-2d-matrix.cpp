class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        //for binary search we need start and end;
        int start = 0;
        int end = (row*col)-1;     
          // n -1 hota h since here 2d matrix so total count of cell is end and its index is n*m -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(matrix[mid/col][mid%col] == target){
                return true;
                //mid nikalne vala part important. 
            }else if(matrix[mid/col][mid%col]  < target){
                start = mid+1;
            }else{
                end = mid -1;
            }
        }
        return false;
    }
};