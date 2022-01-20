#include <vector>
#include <iostream>

class Solution {
public:
	void setZeroes(vector< vector<int> >& matrix) {

	std::vector<int> zeroRow;
	std::vector<int> zeroCol;

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				zeroRow.push_back(i);
				zeroCol.push_back(j);
			}
		}
	}
	
	zeroRow.erase(std::unique(zeroRow.begin(),zeroRow.end()),zeroRow.end());
	zeroCol.erase(std::unique(zeroCol.begin(),zeroCol.end()),zeroCol.end());
	
	for (int i = 0; i < zeroRow.size(); i++)
		for (int j = 0; j < matrix[zeroRow[i]].size(); j++)
			matrix[zeroRow[i]][j] = 0;
			
	for (int j = 0; j < zeroCol.size(); j++)
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][zeroCol[j]] = 0;

	}
};
