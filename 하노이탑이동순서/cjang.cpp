#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> >	makeHanoi(vector<vector<int> > & v1)
{
	vector<vector<int> >	ret;
	vector<int> check;

   for (int i = 0; i< v1.size(); i++)
	{
		check = v1[i];
		for (int j = 0; j < check.size(); j++)
		{
			if (check[j] == 2)
				check[j] = 3;
			else if (check[j] == 3)
				check[j] = 2;
		}
		ret.push_back(check);
	}

	ret.push_back( {1, 3} );

	for (int i = 0; i< v1.size(); i++)
	{
		check = v1[i];
		for (int j = 0; j < check.size(); j++)
		{
			if (check[j] == 2)
				check[j] = 1;
			else if (check[j] == 1)
				check[j] = 2;
		}
		ret.push_back(check);
	}
	return ret;
}

void	printVector(vector<vector<int> > vec)
{
	string	s;
	s += to_string(vec.size()) + "\n";
	for (vector<int> v : vec)
		s += to_string(v[0]) + " " + to_string(v[1]) + "\n";
	cout << s;
	return ;
}

int main(void)
{
	int		n;
	cin >> n;
	vector<vector<int> > vHanoi;
	vHanoi.push_back( {1, 3} );
	for (int i = 1; i < n; i++)
		vHanoi = makeHanoi(vHanoi);
	printVector(vHanoi);
	return 0;
}
