public class Solution {
    public bool IsNumber(string s) {
        bool failed = true;
        float f;
        long l;
        string[] e = null;
        if (s.Contains('e')) {
            e = s.Split('e');
        }
        
        for (int y = 0; y <= 1; y++) {
            for (int x = 0; x < 10; x++) {
                if (e == null) {
                    if (s.Contains(x.ToString())) {
                        failed = false;
                        break;
                    }
                }
                else {
                    if (e[y].Contains(x.ToString())) {
                        failed = false;
                        break;
                    }
                }
            }
        }
        if (failed) return false;
        
        if (e == null || !float.TryParse(e[0], out f) || !long.TryParse(e[1], out l) || e.Length > 2) {
            failed = !float.TryParse(s, out f);            
        }
        else {
            failed = !float.TryParse(e[0], out f);
            if (e[0] != "") if (e[0][e[0].Length-1].ToString() == " ") failed = true;
            if (e[1] != "") if (e[1][0].ToString() == " " ) failed = true;
        }
        
        return !failed;
    }
}