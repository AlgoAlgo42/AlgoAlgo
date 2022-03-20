#include <algorithm>
#include <utility>
#include <queue>
#include <unistd.h>
#include <stdio.h>
//#include <fcntl.h>
//#include <sys/time.h>
using namespace std;
int	input[3];
int input2[3];

int	main(void)
{
	vector<pair<int, char> >			*way;
	priority_queue<pair<int, int> > 		que;
	int									*distance;
	int									fd;
	int	y, z = 0;
	//struct timeval	t, t1;

	//fd = open("testfile", O_RDONLY);
	//dup2(fd, 0);
	//close(fd);
	scanf("%d %d %d", input, input + 1, input + 2);
	--input[2];
	distance = new int[input[0]];
	way = new vector<pair<int, char> >[input[0]];
	//gettimeofday(&t, 0);
	for (int x = 0; x < input[1]; ++x)
	{
        scanf("%d %d %d", input2, input2 + 1, input2 + 2);
		--input2[0];
		--input2[1];
		way[input2[0]].push_back(make_pair(input2[1], static_cast<char>(input2[2])));
	}
	for (int x = 0; x < input[0]; ++x)
    {
		distance[x] = 30000000;
        if (x == input[2])
            distance[x] = 0;
    }
	for (int x = 0; x < way[input[2]].size(); ++x)
	{
		if (distance[way[input[2]][x].first] > way[input[2]][x].second)
			distance[way[input[2]][x].first] = way[input[2]][x].second;
	}
	for (int x = 0; x < input[0]; ++x)
		que.push(make_pair(distance[x] * -1, x));
	int n,m;
	while (que.empty() == false)
	{
		n = que.top().first;
		m = que.top().second;
		que.pop();
		if (n != -30000000 && n * -1 == distance[m])
		{
			for (int x = 0; x < way[m].size(); ++x)
			{
				if (way[m][x].second + distance[m] < distance[way[m][x].first])
				{
					distance[way[m][x].first] = way[m][x].second + distance[m];
					que.push(make_pair(distance[way[m][x].first] * -1, way[m][x].first));
				}
			}
		}
	}
	for (int x = 0; x < input[0]; ++x)
	{
		if (distance[x] == 30000000)
			printf("INF\n");
		else
			printf("%d\n", distance[x]);
	}
	//gettimeofday(&t1, 0);
	//cout <<"out " << (t1.tv_sec - t.tv_sec) * 1000 + (t1.tv_usec - t.tv_usec) / 1000 << "\n";
	delete []distance;
	delete []way;
	//close(0);
}
