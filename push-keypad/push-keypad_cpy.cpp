#include <string>
#include <vector>
#define RIGHT 1
#define LEFT 0

using namespace std;

int dis(int i1,int i2)
{
    // return (abs((i1/10)-(i2/10))+(abs((i1%10)-(i2%10))));
    return (abs(i1-i2)/10 +abs(i1-i2)%10);
}
void putHand(string *answer, int *hand_map, int mapped, string hand)
{
	(*answer)+=hand;
	*hand_map = mapped;
}

int whatIsCloser(int mapped, int left, int right, string hand)
{
	if(dis(mapped,left) == dis(mapped,right))
    {
        if (hand == "left")
            return (LEFT);
        else
            return (RIGHT);
    }
    else if (dis(mapped,left) < dis(mapped,right))
        return (LEFT);
    else
        return (RIGHT);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 30;
    int right = 32;
    int key_map[10] = {31,0,1,2,10,11,12,20,21,22};
    
    for (int i = 0 ; i < numbers.size(); i++)
    {
        int mapped = key_map[numbers[i]];
        int token =numbers[i] % 3;
        if (numbers[i] == 0)
            token = 2;
        switch(token)
        {
            case(0):
                putHand(&answer, &right, mapped, "R");
                break;
            case(1):
                putHand(&answer, &left, mapped, "L");
                break;
            case(2):
                if (whatIsCloser(mapped,left,right,hand) == LEFT)
                    putHand(&answer, &left, mapped, "L");
				else
					putHand(&answer, &right, mapped, "R");
                break;           
        }
        
    }
    
    return answer;
}
