
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row * col;

        // index initialization
        int startingrow = 0;
        int startingcol = 0;
        int endingrow = row - 1;
        int endingcol = col - 1;

        vector<int> ans;

        while (count < total) {

            // 1. Starting row → left to right
            for (int index = startingcol; index <= endingcol && count < total; index++) {
                ans.push_back(matrix[startingrow][index]);
                count++;
            }
            startingrow++;

            // 2. Ending column → top to bottom
            for (int index = startingrow; index <= endingrow && count < total; index++) {
                ans.push_back(matrix[index][endingcol]);
                count++;
            }
            endingcol--;

            // 3. Ending row → right to left
            for (int index = endingcol; index >= startingcol && count < total; index--) {
                ans.push_back(matrix[endingrow][index]);
                count++;
            }
            endingrow--;

            // 4. Starting column → bottom to top
            for (int index = endingrow; index >= startingrow && count < total; index--) {
                ans.push_back(matrix[index][startingcol]);
                count++;
            }
            startingcol++;
        }

        return ans;
    }
};

