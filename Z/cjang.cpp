#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int>	c_make(int n_tmp, int n, vector<int> v)
{
	if (n_tmp == n)
		return v;

	int	v_add = pow(2, n_tmp);
	int	val = pow(2, n_tmp+1);

	vector<int>	v_tmp(v);
	v_tmp.resize(val);

	for (int i = 0; i < v.size(); i++)
		v_tmp[i+v.size()] = v_tmp[i] + v_add * v_add;
	v_tmp = c_make(n_tmp+1, n, v_tmp);
	return v_tmp;
}

int main(void)
{
	int n, r, c;
	vector<int>	v(1);
	v[0] = 0;

	cin >> n >> r >> c;
	vector<int> c_map(c_make(0, n, v));
	cout << 2 * c_map[r] + c_map[c];
	return 0;
}
