class Solution {
public:

    int check_v(int i, int j ,std::vector<std::vector<char> >& grid)
    {
                // printf("%d : %d : %d : %d \n",i ,j, grid.size(), grid[i].size());

        if (i < 0 || j < 0 || i >= grid.size()|| j >= grid[i].size())//bound exception
        {
            return (-1);
        }
        else
        {
            return (grid[i][j]);
        }
    class Solution {
public:
    
    void DFStravel(int i,int j, vector<vector<char> > &grid){
    int rows = (int)grid.size();
    if(rows == 0)
        return;
    int cols = (int)grid[0].size();

    if(i<0 || i>=rows || j<0 || j>=cols)
        return;
    if (grid[i][j] != '1')
        return;
    grid[i][j] = '2';
    
    DFStravel(i+1,j,grid);
    DFStravel(i,j+1,grid);
    DFStravel(i-1,j,grid);
    DFStravel(i,j-1,grid);
}

    
    int numIslands(std::vector<std::vector<char> >& grid) {     
        int island = 2;
        for (int i = 0; grid.size() > i; i++)
        {
            for (int j = 0; grid[i].size() > j; j++)
            {
                if (grid[i][j] == '1')
                {
                    island ++;
                    DFStravel(i,j,grid);
                    
                }
            }
        }
        return (island-2);
        
    }
};

}
