#include<bits/stdc++.h>
using namespace std;

class Suggestions
{
    public:

    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)    ///  return type = a vector of vectors
    {
        int n = products.size();

        sort(products.begin(), products.end());   /// Sort by increasing lexicographically order of products

        vector<vector<string>> ans;              ///  to store the answer

        auto beginSearch = products.begin();     ///  from where we start looking for matching strings
        int insertIndex = 0;
        string prefix = "";

        for (char &c : searchWord)
        {
            prefix += c;

            beginSearch = lower_bound(beginSearch, products.end(), prefix);   /// finding the lower bound of the prefix

            insertIndex = beginSearch - products.begin();

            // cout << insertIndex << endl;

            ans.push_back({});    ///  adding an empty vector in the set of vectors

            for (int i = insertIndex; i < min(insertIndex + 3, n); ++i)
            {
                ans.back().push_back(products[i]);            ///  pushing back at the back of the vector of vectors
            }
        }

        return ans;
    }

};


int main()
{
   Suggestions s;

   vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad", "mould", "man"};

   vector<vector<string>> v = s.suggestedProducts(products, "mou");


   for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }


    return 0;

}
