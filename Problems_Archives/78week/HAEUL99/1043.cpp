#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

int n, m; //사람의 수, 파티의 수
int k; //진실을 아는 사람의 수
int ak[52];//진실을 아는 사람의 번호
int ap[52]; //파티마다 오는 사람의 수와 번호
vector<int> adj[52];
//int np[52]; //파티에 몇번오는지 
int vis[52];
int pp; //파티 사람 수
unordered_set<int> trueGrp;
unordered_set<int> partyMem[52];
void bfs(int sv)
{
    queue<int> _queue;
    fill(vis+1, vis+n+1, 0);
    vis[sv] = 1;
    _queue.push(sv);
    trueGrp.insert(sv);

    while(!_queue.empty())
    {
        int cur = _queue.front();
        _queue.pop();

        for(auto m:adj[cur])
        {
            if(vis[m]==1) continue;
            vis[m] = 1;
            _queue.push(m);
            trueGrp.insert(m);
        }
    }

}
int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> k;

    for(int i = 0; i < k; i++)
    {
        cin >> ak[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> pp;
        fill(ap, ap+pp, 0);
        for(int j = 0; j < pp; j++)
        {
            cin >> ap[j];
            //np[ap[i]]++;
            partyMem[i].insert(ap[j]);
        }
        for(int j = 0; j < pp; j++)
        {
            for(int z = j+1; z <pp; z++)
            {
                adj[ap[j]].push_back(ap[z]);
                adj[ap[z]].push_back(ap[j]);
                //cout << ap[j] << ' ' << ap[z] << endl;
            }
        }


    }

    for(int i = 0; i < k; i++)
    {
        bfs(ak[i]);
        // cout << ak[i] << endl;
        // for(auto m: trueGrp)
        // {
        //     cout << m <<' ';
        // }
        // cout << endl;
    }

    
    
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        bool canLie = true;
        for(auto m:partyMem[i])
        {
            if(trueGrp.find(m) != trueGrp.end())
            {
                canLie = false;
            }
        }
        if(canLie) ans++;

    }

    cout << ans;


    

    
}
