#include <iostream>
#include <set>

using namespace std;

int main()
{
	int T, k;

	cin >> T;
	while (T--)
	{
		cin >> k;
		multiset<int> dq;
		char	type;
		int		num;
		while (k--)
		{
			cin >> type >> num;
			if (type == 'I')
				dq.insert(num);
			else if (dq.empty())
				continue;
			else if (type == 'D' && num == -1)
				dq.erase(dq.begin());
			else
				dq.erase(--dq.end());
		}
		if (!dq.empty())
			cout << *dq.rbegin() << " " << *dq.begin() << "\n";
		else
			cout << "EMPTY" << "\n";
	}
	return 0;
}
