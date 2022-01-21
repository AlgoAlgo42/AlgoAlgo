class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
    int rows = grid.size(), cols = grid[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            { 
                visitAdjLand(grid, i, j, rows, cols);
                islands++;
            }
        }
    }
    return islands;
    }
    void visitAdjLand(vector<vector<char>> &grid, int i, int j, int rows, int cols)
{
    if (i < 0 || j < 0 || i >= rows || j >= cols)
    {
        return;
    }
    else if (grid[i][j] == '2' || grid[i][j] == '0')
    { 
        return;
    }
    grid[i][j] = '2'; 
    visitAdjLand(grid, i+1, j, rows, cols);
    visitAdjLand(grid, i, j+1, rows, cols); 
    visitAdjLand(grid, i-1, j, rows, cols);
    visitAdjLand(grid, i, j-1, rows, cols); 

    return;
}
};