#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::find;
using std::string;
using std::vector;

struct Query
{
    string type, s;
    size_t ind;
};

class QueryProcessor
{
private:
    int bucket_count;
    vector<string> elems;
    vector<vector<string>> mp = vector<vector<string>>(bucket_count);
    size_t hash_func(const string &s) const
    {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count) : bucket_count(bucket_count) {}

    Query readQuery() const
    {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const
    {
        cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query &query)
    {
        if (query.type == "check")
        {
            if (mp[query.ind].size() != 0)
                for (int i = static_cast<int>(mp[query.ind].size()) - 1; i >= 0; --i)
                    cout << mp[query.ind][i] << " ";
            cout << "\n";
        }
        else
        {
            size_t ind = hash_func(query.s);
            vector<string>::iterator it = find(mp[ind].begin(), mp[ind].end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != mp[ind].end());
            else if (query.type == "add" && it == mp[ind].end())
                mp[ind].push_back(query.s);
            else if (query.type == "del" && it != mp[ind].end())
                mp[ind].erase(it);
        }
    }

    void processQueries()
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}