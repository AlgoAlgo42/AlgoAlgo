#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //  1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    
    //  2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    for (char i : new_id)
    {
        if (isalpha(i) || isdigit(i) || i == '-' || i == '_' || i == '.')
            answer.push_back(i);
    }
    
    //  3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    for (int i = 0, k = 0; i < answer.size(); i++, k++)
    {
        while (answer[i] == '.')
            i++;
        if (i != k)
        {
            answer.erase(k + 1, i - k - 1);
            i = k;
        }
    }
    
    //  4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if (answer[0] == '.')
        answer.erase(0, 1);
    if (answer[answer.size() - 1] == '.')
        answer.erase(answer.size() - 1, 1);
    
    //  5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if (answer.empty())
        answer.push_back('a');

    // 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    //  만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    answer = answer.substr(0, 15);
    if (answer[answer.size() - 1] == '.')
        answer.erase(answer.size() - 1, 1);
    
    // 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    int size = answer.size();
    if (size < 3)
    {    
        char c = answer[size - 1];
        while(size++ < 3)
        {
            answer.push_back(c);
        }
    }
    
    return answer;
}
