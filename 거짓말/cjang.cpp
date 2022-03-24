#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void	TalkTruethCheck(int num, set<int> & s, vector<int> v, vector<set<int> > & vs)
{
	for (int i : vs[num])
	{
		if (v[i] == 0)
		{
			v[i] = 1;
			s.insert(vs[i].begin(), vs[i].end());
			TalkTruethCheck(i, s, v, vs);
		}
	}
	return ;
}

int main(void)
{
	set<int>			s_trueth;
	set<int>			s_truethFinal;
	vector<set<int> >	vs_invitedParty;
	vector<int>			v(51);
	vector<set<int> >	vs(51);

	// 정보 얻는 부분
	int		n, m, pNum, p1, p2;
	cin >> n >> m >> pNum;

	for (int i = 0; i < pNum; i++)
	{
		cin >> p1;
		s_trueth.insert(p1);
	}

	s_truethFinal.insert(s_trueth.begin(), s_trueth.end());

	for (int i = 0; i < m; i++)
	{
		cin >> pNum;
		set<int>	s_tmp;
		p1 = 0;
		p2 = 0;
		for (int i = 0; i < pNum; i++)
		{
			if (p2 > 0)
				p1 = p2;
			cin >> p2;

			if (p1 > 0)
			{
				vs[p1].insert(p2);
				vs[p2].insert(p1);
			}
			s_tmp.insert(p2);
		}
		vs_invitedParty.push_back(s_tmp);
	}

	// 진실을 아는자와 관련된 사람 추적
	for (int num : s_trueth)
		TalkTruethCheck(num, s_truethFinal, v, vs);
	
	// 거짓말 할 수 있는지 판단 -> 파티 참여 가능 수 세기
	for (set<int> ss : vs_invitedParty)
	{
		vector<int>::iterator	it;
		vector<int>	v_tmp(51);

		it = set_union(ss.begin(), ss.end(), s_truethFinal.begin(), s_truethFinal.end(), v_tmp.begin());
		v_tmp.resize(it - v_tmp.begin());
		if (v_tmp.size() != ss.size() + s_truethFinal.size())
			--m;
	}
	cout << m;
	return 0;
}

