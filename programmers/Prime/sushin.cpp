#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

vector<int> v; 
bool sel[10];
set<int> primeSet;

bool check(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
            return false;
    return true;
}

void recur(int cnt, int r, vector<int> num)
{ 
    if(cnt == r)
    { 
        int temp = 0;
        for (int d : v)  
            temp = temp * 10 + d;
        if(check(temp))
            primeSet.insert(temp);
        return; 
    } 
    for(int i = 0; i < num.size(); i++)
    { 
        if(sel[i] == true) 
            continue; 
        sel[i] = true; 
        v.push_back(num[i]); 
        recur(cnt+1, r, num); 
        v.pop_back(); 
        sel[i] = false; 
    } 
}


int solution(string numbers) {
    int answer = 0;
    vector<int> nums;
    
    for (int i = 0; i < numbers.size(); i++)
        nums.push_back(numbers[i] - 48);
    for (int i = numbers.size(); i > 0; i--)
        recur(0, i, nums);
    
    answer = primeSet.size();
	
    
    return answer;
}
