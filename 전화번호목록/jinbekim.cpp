#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0, len = phone_book.size(); i < len - 1; ++i)
    {
        int j = 0;
        while (phone_book[i][j] && phone_book[i + 1][j])
        {
            if (phone_book[i][j] != phone_book[i + 1][j])
                break;
            j++;
        }
        if (phone_book[i].length() == j || phone_book[i + 1].length() == j)
            return false;
    }
    return answer;
}