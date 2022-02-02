#include <string>
#include <vector>

using namespace std;

//문자열 비교함수 : n글자 비쿄 같으면  true 다르면 false
int check_str(string s1, string s2,int n)
{
    for (int i  = 0; i < n ; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

int solution(string s) {
    int s_len = s.length();
    int answer = s_len;
    // 임시로 해당 크기의 압충 결과를 저장하고 min()으로 선택
    int answer_tmp;
    
    //1에서 부터 문자열길이의 반 까지 압축을 시도해봅니다.
    for (int i = 1; i <= s_len / 2 ;i++)
    {
        answer_tmp = 0;
        // 문자열의 길이만큼 나누어 떨어질때 동안 j를 i(시도중인 크기)만큼 증가시키면서 반복합니다.
        for (int j = 0; j + i <= s_len; j += i)
        {
            answer_tmp += i;
            int count = 0;
            int x;
            x = j;
         //i만큼 문자열을 비교하여 같은 부분을 숫자로 바꿉니다.
            while (x + i < s_len && check_str(s.c_str() + x, s.c_str() + x + i ,i))
            {
                count++;
                x+=i;
            }
            if (x != j)
            {
                //count를 사용하여 10이상의 수를 처리해줍니다.
                answer_tmp += to_string(count + 1).size();
                j = x;
            }
		}
		//나머지는 그냥 냅다 넣어줍니다.
        answer_tmp += s_len % i;
		answer = min(answer, answer_tmp);
    }
    return answer;
}

