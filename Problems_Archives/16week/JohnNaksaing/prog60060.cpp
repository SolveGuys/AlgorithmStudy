#include <string>
#include <vector>

#if 0
std::vector<int> solution(std::vector<std::string> words, std::vector<std::string> queries) {
    int wssize = words.size();
    int qssize = queries.size();
    std::vector<int> answer(qssize,0);
    
    for(int i = 0; i < qssize; i++)
    {
        std::string query = queries[i];
        int qsize = query.size();
        
        bool bFront = false;
        int k = 0;
        if(query[0] == '?')
        {
            bFront = true;
            while(query[k] != '?') k++;
        }
        
        for(int j = 0; j < wssize; j++)
        {
            std::string word = words[j];
            
            if(word.size() != qsize) continue;
            
            //word vs query
            for(int k_ = k; k_ < qsize; k_++)
            {
                if(word[k_] != query[k_] && query[k_] != '?') break;
                
                if(bFront)
                {
                    if(k_ == word.size() -1) answer[i]++;        
                }
                else
                {
                    if(query[k_] == '?') {answer[i]++; break;}
                }
            }
        }
    }
    
    return answer;
}
#endif