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

std::vector<int> solution(std::vector<std::string> words, std::vector<std::string> queries) {
    int wssize = words.size();
    int qssize = queries.size();
    
    std::vector<int> answer(qssize, 0);

    std::vector<std::string> words_reverse = words;
    for (auto& r_word : words_reverse) { std::reverse(r_word.begin(), r_word.end()); }

    std::sort(words.begin(), words.end(), compare_word() );
    std::sort(words_reverse.begin(), words_reverse.end(), compare_word() );
    
    //for (auto& r_word : words_reverse) { std::cout << r_word << ' '; }
    //for (auto& word : words) { std::cout << word << ' '; }

    int answer_idx = 0;
    for (auto& query : queries) 
    {
        int length = query.length();

        //???aaa
        if (query[0] == '?') 
        {
            std::reverse(query.begin(),query.end());
            
            std::string start(query);
            for (int i = 0; i < start.length(); i++)
                if (start[i] == '?')
                    start[i] = 'a';

            const auto start_where = std::lower_bound(words_reverse.begin(),words_reverse.end(),start,compare_word());
            
            std::string end(query);
            for (int i = 0; i < end.length(); i++)
                if (end[i] == '?')
                    end[i] = 'z';
            const auto end_where = std::lower_bound(words_reverse.begin(),words_reverse.end(),end,compare_word());
            
            answer[answer_idx++] = (end_where - start_where);
        }
        //aaa???
        else 
        {
            std::string start(query);
            for (int i = 0; i < start.length(); i++)
                if (start[i] == '?')
                    start[i] = 'a';

            const auto start_where = std::lower_bound(words.begin(), words.end(), start, compare_word());

            std::string end(query);
            for (int i = 0; i < end.length(); i++)
                if (end[i] == '?')
                    end[i] = 'z';
            const auto end_where = std::lower_bound(words.begin(), words.end(), end, compare_word());

            answer[answer_idx++] = (end_where - start_where);
        }
    }

    return answer;
}