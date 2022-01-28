```cpp
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int id_size = id_list.size();
    vector<int> answer(id_size, 0);
    vector<string> temp;
    vector<string> id;
    string s;
    
    if (k < 1 || id_size < 1 || report.size() < 1)
        return answer;
    sort(report.begin(), report.end());                                   // 1
    report.erase(unique(report.begin(), report.end()), report.end());     // 2
    for (int i = 0; i < report.size(); i++)                               
    {                                                                     //
        istringstream ss(report[i]);                                      //
        while (getline(ss, s, ' '))                                       //     id(신고자)
        {                                                                 // 3
            if (!ss.eof())                                                //     temp(신고당한 자)
                id.push_back(s);                                          //
            else                                                          //
                temp.push_back(s);                                        //
        }
    }
    
    for (int i = 0; i < id_list.size(); i++)                                                     
    {                            
        if (count(temp.begin(), temp.end(), id_list[i]) >= k)                                 // 4-1(count 함수)
        {                                                                                     //
            auto iter = find(temp.begin(), temp.end(), id_list[i]);                           // 4-2
            int idx = iter - temp.begin();                                                    // 4-3
            int anweridx = find(id_list.begin(), id_list.end(), id[idx]) - id_list.begin();   // 4-4
            answer[anweridx] += 1;                                                            // 4-5
            if (iter != temp.end())                                                           // 4-6
            {                                                                                 // 
                while (iter != temp.end())                                                    //
                {                                                                             //
                    iter = find(iter + 1, temp.end(), id_list[i]);                            //
                    idx = iter - temp.begin();                                                //
                    anweridx = find(id_list.begin(), id_list.end(), id[idx]) - id_list.begin();//
                    if (anweridx < id_size)                                                   //
                        answer[anweridx] += 1;                                                //
                }
            }
        }
    }
    return answer;
}
```
같은사람이 같은사람을 신고하는 것은 1회만 허용된다 해서 (1,2)를 통해 중복 신고자들을 지워줬습니다.  
3번 for문을 이용하여 report에서 공백(' ')을 기준으로 신고자와 신고당한자를 나눠줬습니다.  
  >     ex)  
  >        id_list = {muzi, frodo, apeach, neo}  
  >        report  = {apeach frodo, apeach muzi, frodo neo, muzi frodo, muzi neo}   
  >        id(신고자) = {apeach, apeach, frodo, muzi, muzi}   
  >        temp(신고당한자) = {frodo, muzi, neo, frodo, neo}   
4번 for문을 이용하여 id_list size만큼 반복  
 (4-1)temp에 신고당한자가 k번이상 들어있다면  
 (4-2 ~ 4-3)temp에서 frodo의 idx를 찾고  
 (4-4 ~ 4-5)id[idx]로 apeach를 캐치해서 id_list에서 apeach인덱스를 찾아 리턴값 answer인덱스에 + 1을 해줍니다.  
 (4-6)부터는 frodo가 한번만 신고 된 것이 아닌 여러명에게 신고 당한경우를 찾아서 temp의 끝까지 다시 검색해봅니다.  
