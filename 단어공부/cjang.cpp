#include <iostream>
#include <vector>
#include <string>

using namespace std;

int	main(void)
{
	vector<int>	v(27);
	string		s;
	vector<int>	max(2);	// max값, max값인 알파벳

	cin >> s;
	for (char c : s)
		++v[c % 32];

	for (int i = 1; i < 27; i++)
	{
		if (max[0] < v[i])
		{
			max[0] = v[i];
			max[1] = i + 64;
		}
		else if (max[0] == v[i])
			max[1] = '?';
	}

	cout << static_cast<char>(max[1]);
}
// 			a = 97 / z = 122 / A = 65 / Z = 90
// % 32->	a = 1 / z = 26 / A = 1 / Z = 26
// 출력시 -> +64
