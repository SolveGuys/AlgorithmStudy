#include <string>
#include <vector>
#include <map>
//#include <iostream>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    map<string,string> pyramid;
    map<string,int> name_idxs;
    
    for(int i = 0; i < enroll.size(); i++)
    {
        pyramid[enroll[i]] = referral[i];
        name_idxs[enroll[i]] = i;
    }
    vector<int> answer(enroll.size());
    //bool bDebugFlag = false;
    for(int i = 0; i < seller.size(); i++)
    {
        string me = seller[i];
        /*
        if(me == "young" || me == "sam")
            bDebugFlag = true;
        else
            bDebugFlag = false;
        */
        int earned = amount[i] * 100;
        
        while(me != "-" && earned >= 1)
        {
            int sang_nap = earned / 10;
            int nae_ker = earned - sang_nap;
            answer[name_idxs[me]] += nae_ker;
            
            //if(bDebugFlag) cout << me << ":"  << earned << '\n';
            
            //if(me == "mary") cout << nae_ker << '\n';
            
            me = pyramid[me];
            earned /= 10;
            
        }
    }

    return answer;
}