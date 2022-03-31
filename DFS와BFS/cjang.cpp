#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int> >	vec(1001, std::vector<int>(1001));
std::vector<int>	check1(1001);
std::vector<int>	check2(1001);
std::vector<int>	answer1;
std::vector<int>	answer2;
std::queue<int>		q;

void	dfs(int max, int start)
{
	check1[start] = 1;
	for (int i = 1; i <= max; i++)
	{
		if (check1[i] == 0 && vec[start][i] == 1)
		{
			answer1.push_back(i);
			dfs(max, i);
		}
	}
}

void	bfs(int max, int start)
{
	q.push(start);
	check2[start] = 1;
	answer2.push_back(start);
	while (!q.empty())
	{
		for (int i = 1; i <= max; i++)
		{
			if (check2[i] == 0 && vec[q.front()][i] == 1)
			{
				q.push(i);
				check2[i] = 1;
				answer2.push_back(i);
			}
		}
		q.pop();
	}
}

int main(void)
{
	int		n, m, v, a, b;
	// 입력
	std::cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		std::cin >> a >> b;
		vec[a][b] = 1;
		vec[b][a] = 1;
	}
	answer1.push_back(v);
	dfs(n, v);
	bfs(n, v);
	for (int i = 0; i < answer1.size()-1; i++)
		std::cout << answer1[i] << " ";
	std::cout << answer1.back() << std::endl;
	for (int i = 0; i < answer2.size()-1; i++)
		std::cout << answer2[i] << " ";
	std::cout << answer2.back();
}
