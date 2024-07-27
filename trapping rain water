class Solution {
public:
    int trap(vector<int>& height) {

        int leftmax = -1, rightmax = 0, count = 0, i = 0, ans = 0, countk = 0;
        while (i < height.size()) {
            count = 0;
            countk = 0;

            if (leftmax == -1) {
                if (height[i] == 0) {
                    i++;
                    continue;
                }
                leftmax = i;
                count = 0;
                i++;
                continue;
            }

            rightmax = i;
            int k = i;
            while (rightmax < height.size() &&
                   height[rightmax] < height[leftmax]) {
                count += height[rightmax];

                if (height[rightmax] >= height[k]) {
                    countk = count;
                    k = rightmax;
                }
                rightmax++;
            }
            if (rightmax < height.size() &&
                height[rightmax] >= height[leftmax]) {
                ans += ((rightmax - leftmax - 1) * height[leftmax]) - count;
                cout << ans << " ";
                leftmax = rightmax;
                i = rightmax + 1;
                continue;
            } else if (rightmax >= height.size()) {

                ans += ((k - leftmax - 1) * height[k]) - countk + height[k];
                cout << ans << " ";

                leftmax = k;
                i = leftmax + 1;
            }
        }

        return ans;
    }
};
