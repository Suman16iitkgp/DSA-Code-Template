/*
You are given a dictionary of N words (each word consists of lowercase characters) and Q query words. 
In each query, you will be given an integer K and a word S. We want to design a system that will suggest at 
most K words from the dictionary after each character of a query word is typed. Suggested words should have a common 
prefix with the query word. If there are more than K dictionary words with a common prefix return the K lexicographically 
minimum words. If there is no word with a common prefix print a blank line.
*/

#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;

lli n, m, q;

struct node
{
    node *child[26];
    lli pref=0;
    vector<string> wend;

    node(){
        for(lli i=0; i<26; i++ ){
            child[i] = NULL;
        }
    }  
};

struct trie{
    node *root;
    lli k_rem;
    vector<string> ans;
    trie(){
        root = new node;
    }

    void dfs( node *nn ){
        if(k_rem == 0){
            return;
        }
        for( auto v:nn->wend ){
            ans.push_back( v );
            k_rem--;
            if(k_rem <= 0){
                return;
            }
        }

        for(lli i=0; i<26; i++ ){
            if(nn->child[i] != NULL ){
                dfs( nn->child[i] ); 
            }
            
        }
    }
    void insert( string s, lli sz ){
        node *cur = root;
        for(lli i=0; i<sz; i++ ){
            lli id = s[i] - 'a';
            cur->pref++;
            if(cur->child[id] == NULL ){
                cur->child[id] = new node;
            }
            cur = cur->child[id];
        }
        // cout << cur->pref << "\n";
        cur->wend.push_back( s );
    }

    vector<string> find( string s, lli k, int sz ){
        ans.clear();
        k_rem = k;
        node *cur = root;
        for(lli i=0; i<sz; i++ ){
            lli id = s[i] - 'a';
            if( cur->child[id] == NULL ){
                return ans;
            }else{
                cur = cur->child[id];
            }
        }

        dfs( cur );

        return ans;
    }
};

void solve()
{
    cin >> n >> m >> q;

    trie tr;
    for(lli i=0; i<n; i++ ){
        lli ssize;
        string given;
        cin >> ssize;
        cin >> given;
        tr.insert( given, ssize ); 
    }

    for(lli i=0; i<q; i++ ){
        string qr;
        lli qrsize, qrk;
        cin >> qrsize;
        cin >> qr;
        cin >> qrk;

        string fnd="";
        for( lli i=0; i<qrsize; i++ ){
            fnd+=qr[i];
            // cout << fnd;
            vector<string> res = tr.find( fnd, qrk, i+1);
            for( auto it: res ){
                cout << it << " ";
            }
            cout << "\n" ;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    lli _t; 
    // cin >> _t;
    _t=1ll;

     clock_t begin=clock();
    while(_t--)
    {
        solve();
    }
    
     clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
    return 0;
}
