#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#if 0
using namespace std;

bool solution(vector<string>& phone_book)  {
    bool answer = true;
    if(phone_book.size() == 1) return true;
    sort(phone_book.begin(),phone_book.end());
    for(int i = 0; i < phone_book.size()-1; i++) {
        std::string small = phone_book[i];
        std::string big = phone_book[i+1].substr(0,small.size());
        if(0 == small.compare(big)){
            return false;
        }
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<string> phone_book(n);
        for(int i = 0; i < n; i++)
        {
            cin >> phone_book[i];            
        }
        if(solution(phone_book))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
#endif

class trie 
{
    trie* next[10];
    bool bLeaf;
public:
    trie() : bLeaf(false), next()
    {
        //for (int i = 0; i < 10; i++) next[i] = nullptr;        
    }
    ~trie() 
    {
        //https://stackoverflow.com/questions/2814188/c-array-of-pointers-delete-or-delete
        //delete[] next;
        for (int i = 0; i < 10; i++)
        {
            if (next[i]) delete next[i];
        }
    }

    void insert(const char* key);
    bool find(const char* key);
};

void trie::insert(const char* key) 
{

    if (*key == '\0')
    {
        bLeaf = true;
        return;
    }

   int cursor = *key - '0';

    if (next[cursor] == nullptr) 
    {
        next[cursor] = new trie();
    }
    next[cursor]->insert(key + 1);
}
bool trie::find(const char* key) 
{
    if (*key == '\0') { return false; }
    if (bLeaf) { return true; }


    int cursor = *key - '0';

    if (next[cursor] == nullptr) return false;

    return next[cursor]->find(key+1);
}

int main() 
{
    int t;
    std::cin >> t;
    while (t--) {

        int n;
        std::cin >> n;
        std::vector<std::string> input(n);
        trie* root = new trie();

        for (int i = 0; i < n; i++) {
            std::cin >> input[i];

            root->insert(input[i].c_str());
        }

        int i;
        for (i = 0; i < n; i++) {
            if (root->find(input[i].c_str())) {
                std::cout << "NO\n";
                break;
            }
        }
        if (i == n)
            std::cout << "YES\n";

        delete root;
    }
    return 0;
}
