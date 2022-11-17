class Solution
{
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
        {
            int x1 = abs(ax1 - ax2);
            int y1 = abs(ay1 - ay2);
            int a1 = x1 * y1;
            int x2 = abs(bx1 - bx2);
            int y2 = abs(by1 - by2);
            int a2 = x2 * y2;

            int xOverlap = min(ax2, bx2) - max(ax1, bx1);
            int yOverlap = min(ay2, by2) - max(ay1, by1);
            
            int ovArea=0;
            if(xOverlap > 0 and yOverlap > 0)
                ovArea = xOverlap * yOverlap;

            return a1 + a2 - ovArea;
        }
};
