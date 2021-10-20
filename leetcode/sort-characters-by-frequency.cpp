// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (const char& c : s)
            ++freq[c];
        multimap<int, char> multi;
        for (auto it = freq.begin(); it != freq.end(); ++it)
            multi.insert( { it->second, it->first } );
        string ret;
        for (auto it = multi.rbegin(); it != multi.rend(); ++it)
            for (int i = 0; i < (*it).first; ++i)
                ret += (*it).second;
        return ret;
    }
};