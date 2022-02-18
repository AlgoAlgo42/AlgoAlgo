#include <string>
#include <vector>
#include <iostream>

using namespace std;

void change(string &s)
{
    for (int i = 0 ; i < s.size() ; i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
}
string solution(string p) {
    string u = "",v = "";
    int l = 0, r = 0, open = 0;
    
    for (int i = 0; i < p.size();i++)
    {
        if (p[i] == '(')
        {
            open++;
            l++;
        }
        else if (p[i] == ')')
        {
            r++;
            if (open > 0)
                open--;
        }
        u +=p[i];
        if (l==r)
        {
            v = p.substr(i + 1,p.npos);
            if (!open)
                return (u + solution(v));
            else
            {
                u = u.substr(1,u.size() - 2);
                change(u);
                return ("(" + solution(v) + ")" + u);   
            }
        }
    }
    return u;
}

