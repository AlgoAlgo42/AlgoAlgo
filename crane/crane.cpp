#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    basket.push(0);
    for (int i = 0; i < moves.size(); i++)
    {
        for (int j =0 ;j < board.size() ; j++)
        {
            int tmp = board[j][moves[i] - 1];
            if (tmp != 0)
            {
                if (tmp == basket.top())
                {
                    answer+=2;
                    basket.pop();
                }
                else
                    basket.push(tmp);
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}

