#include <vector>
#include <iostream>

class Solution {
public:
	void setZeroes(std::vector< std::vector<int> > & matrix)
	{
	
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
	std::vector<int>::iterator iter2;
    for(iter2 = zeroRow.begin(); iter2 != zeroRow.end() ; iter2++){
        std::cout << *iter2 << " ";
	
	std::vector<int>::iterator iter;
    for(iter = zeroCol.begin(); iter != zeroCol.end() ; iter++){
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
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



int main(){

	Solution s;
	 std::vector<int> a;
	 a.push_back(1);
	 a.push_back(1);
	 a.push_back(1);
	 std::vector<int> b;
	 b.push_back(1);
	 b.push_back(0);
	 b.push_back(1);

	 std::vector<int> c;
	 c.push_back(1);
	 c.push_back(1);
	 c.push_back(1);

	 std::vector< std::vector<int> > d ;
	 
	 d.push_back(a);
	 d.push_back(b);
	 d.push_back(c);
	 
		s.setZeroes(d);
		
	std::vector< std::vector<int> >::iterator iter;
	 std::vector<int> ::iterator iter2;
    for(iter = d.begin(); iter != d.end() ; iter++){
        for (iter2 = (*iter).begin(); iter2 != (*iter).end();iter2++)
            std::cout << *iter2 << " ";
std::cout << std::endl;
    }
}