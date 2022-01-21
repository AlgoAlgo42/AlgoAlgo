class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         vector<int> index;

        for (int i = 0; i < matrix.size(); i++)
        {
            auto it = find(matrix[i].begin(), matrix[i].end(), 0);
            if (it != matrix[i].end())
            {
                while (it != matrix[i].end())
                {
                    index.push_back(it - matrix[i].begin());
                    it = find(it + 1, matrix[i].end(), 0);
                }
                matrix[i].assign(matrix[i].size(), 0);
            }
        }
        for (int k = 0; k < index.size(); k++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                if (matrix[i][index[k]] != 0)
                {
                    matrix[i][index[k]] = 0;
                }
            }
        }
    }
};