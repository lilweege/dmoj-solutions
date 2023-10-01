class Solution {
    int rectArea(int x1, int x2, int y1, int y2) {
        return (x2-x1) * (y2-y1);
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int total = rectArea(ax1, ax2, ay1, ay2) + rectArea(bx1, bx2, by1, by2);
        int xOverlap = 0, yOverlap = 0;
        if (bx1 <= ax2 && ax2 <= bx2) xOverlap = ax2 - max(bx1, ax1);
        else if (ax1 <= bx2 && bx2 <= ax2) xOverlap = bx2 - max(bx1, ax1);
        if (by1 <= ay2 && ay2 <= by2) yOverlap = ay2 - max(by1, ay1);
        else if (ay1 <= by2 && by2 <= ay2) yOverlap = by2 - max(by1, ay1);
        int intersect = xOverlap * yOverlap;
        return total - intersect;
    }
};