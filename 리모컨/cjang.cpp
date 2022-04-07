#include <iostream>
#include <vector>

using namespace std;
int		n, m, tmp;
int		answer, deep_size;
string	num_s;
vector<int>	vec(10);

void	dfs(int value, int deep)
{
	string	s;
	int		answer_tmp;

	// deep이 해당 위치에 왔을 때
	if (deep == deep_size)
	{
		// cout << value << endl;
		s = to_string(value);
		answer_tmp = s.size() + abs(value - n);
		if (answer > answer_tmp)
			answer = answer_tmp;
		return ;
	}

	for (int i = 0; i < 10; i++)
	{
		if (vec[i] == 0)
			dfs(value * 10 + i, deep + 1);
	}
}


void	dfs_prev(void)
{
	dfs(0, 0);
	if (deep_size > 1 && static_cast<int>(num_s[0]-'0') <= 5)
		dfs(0, 1);
	if (deep_size < 6 && static_cast<int>(num_s[0]-'0') > 5)
		dfs(0, -1);
}

int main(void)
{

	// 입력받는 파트
	cin >> n >> m;
	num_s = to_string(n);
	deep_size = num_s.size();
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		vec[tmp] = 1;
	}

	// 완전 탐색
	answer = abs(n - 100);
	dfs_prev();
	cout << answer;
	return 0;
}

