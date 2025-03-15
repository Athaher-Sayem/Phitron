#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin>>q;
    map<int,int> freq;
    map<int,set<int>> mp;
    
    while(q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int x;
            cin >> x;
            int prevFreq = freq[x];
            int newFreq = prevFreq + 1;
            freq[x] = prevFreq + 1;
            if (prevFreq > 0)
            {
                mp[prevFreq].erase(x);
                if (mp[prevFreq].empty())
                    mp.erase(prevFreq);
            }
            mp[newFreq].insert(x);
        }
        else if (ch == 2)
        {
            if (freq.empty())
                cout << "empty" << endl;
            else
            {
                auto it = mp.rbegin();
                int maxFreq = it->first;
                cout << *it->second.rbegin() << endl;
                freq[*it->second.rbegin()]--;
                mp[maxFreq].erase(*it->second.rbegin());
                if (mp[maxFreq].empty())
                    mp.erase(maxFreq);
                if (freq[*it->second.rbegin()] > 0)
                    mp[freq[*it->second.rbegin()]].insert(*it->second.rbegin());
            }
        }
    }
    return 0;
}
