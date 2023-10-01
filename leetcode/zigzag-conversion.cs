public class Solution {
    public string Convert(string s, int numRows) {
        if (numRows == 1) return s;
        char[] car = s.ToCharArray();
        bool zig = true;
        int currentRow = 0;
        int count = 0;
        string[] row = new string[numRows];
        string full = "";
        while (count < car.Length) {
            row[currentRow] += car[count];
            
            if (zig) currentRow++;
            else currentRow--;
            
            if (currentRow == row.Length - 1) zig = false;
            if (currentRow == 0) zig = true;
            count++;
        }
        
        for (int i = 0; i < row.Length; i++) {
            full += row[i];
        }
        return full;
    }
}