class Solution {
public:
    string customSortString(string order, string str) {
        int charVal[26] = {0};
        for (int i = 0; i < order.size(); ++i)
            charVal[order[i]-'a'] = i;
        
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            int minIdx = i;
            for (int j = i+1; j < n; ++j) {
                if (charVal[str[minIdx]-'a'] > charVal[str[j]-'a']) {
                    minIdx = j;
                }
            }
            
            swap(str[i], str[minIdx]);
        }
        
        return str;
    }
};