#include <iostream>
#include <vector>
#include <queue>

#define MAX 10000000
using namespace std;

int		V, E, K;


void	findShortestRoute(int start, vector<pair<int, int> > *vp, vector<int> & vecShort)
{
	int		cost;
	int		node;
	int		nextCost;
	int		nextNode;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >		pq;

	vecShort[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		cost = pq.top().first;
		node = pq.top().second;
		pq.pop();

		for (int i = 0; i < vp[node].size(); i++)
		{
			nextNode = vp[node][i].first;
			nextCost = vp[node][i].second;
			if (vecShort[nextNode] > cost + nextCost)
			{
				vecShort[nextNode] = cost + nextCost;
				pq.push( make_pair(vecShort[nextNode], nextNode) );
			}
		}
	}
	return ;
}

int main(void)
{
	int u ,v, w;
	cin >> V >> E >> K;

	vector<pair<int, int> >	vp[20001];
	vector<int>				vecShort(V+1, MAX);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		vp[u].push_back(make_pair(v, w));
	}

	findShortestRoute(K, vp, vecShort);
	for (int i = 1; i <= V; i++)
	{
		if (vecShort[i] == MAX)
			cout << "INF\n";
		else
			cout << vecShort[i] << "\n";
	}
	return 0;
}

