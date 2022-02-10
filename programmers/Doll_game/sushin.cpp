#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> doll;

    doll.push(101);
    for (int i : moves)
    {
        for (int k = 0; k < board.size(); k++)
        {
            if (board[k][i - 1] != 0)
            {
                if (doll.top() == board[k][i - 1])
                {    
                    answer += 2;
                    doll.pop();
                }
                else if (doll.top() != board[k][i - 1])
                {
                    doll.push(board[k][i - 1]);
                }
                board[k][i - 1] = 0;
                break;
            }
        }
    }
    return answer;
}
