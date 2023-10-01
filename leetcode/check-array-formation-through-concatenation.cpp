class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        //sort(pieces.begin(), pieces.end(), [](vector<int>& a, vector<int>& b) {
        //    return a.size() < b.size();
        //});
        
        //for (const vector<int>& piece : pieces)
        //{
        //    for (int x : piece)
        //        cout << x << " ";
        //    cout << endl;
        //}
        
        
        // naive
        for (int i = 0; i < arr.size(); ++i)
        {
            bool found = false;
            for (const auto& piece : pieces)
            {
                if (arr[i] == piece[0])
                {
                    found = true;
                    for (int j = 0; j < piece.size(); ++j)
                        if (arr[i + j] != piece[j])
                            return false;
                    i += piece.size() - 1;
                    break;
                }
            }
            if (!found)
                return false;
        }
        
        return true;
    }
};