#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];

    Trie()
    {
        memset(trie,0,sizeof(trie));
        memset(endmark,0,sizeof(endmark));
        memset(pre,0,sizeof(pre));
        cout << "Object Created" << endl;
    }

    void Insert(string word)
    {
        int row = 1;
        for(int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';

            if(trie[row][ch] == 0)
            {
                trie[row][ch] = ++id;
            }

            row = trie[row][ch];
            pre[row]++;
        }

        endmark[row] = 1;

        cout << "Word Added" << endl;
    }

    bool Search(string word)
    {
        int row = 1;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if( word[i] == '.' )
            {
                row++;
            }

            else
            {
                int ch = word[i] - 'a';
                if(trie[row][ch] == 0)
                {
                    cout << "Word not found" << endl;
                    return false;
                }
                row = trie[row][ch];
            }


        }

        cout << "Word Found" << endl;
        return (endmark[row] == 1);
    }


    bool startsWith(string prefix)
    {
        int row = 1;
        for(int i = 0; i < prefix.size();i++)
        {
            int ch = prefix[i] - 'a';
            if(trie[row][ch] == 0)
            {
                cout << "Not Found" << endl;
                return false;
            }
            row = trie[row][ch];

        }

        cout << "Found" << endl;
        return (pre[row] >= 1);
    }

};


int main()
{

    Trie* obj = new Trie();

    obj->Insert("bad");
    obj->Insert("dad");
    obj->Insert("mad");

    obj->Search("pad");
    obj->Search("bad");

    obj->Search(".ad");
    obj->Search("b..");
    obj->Search(".a.");
    obj->Search("b.d");

   return 0;
}
