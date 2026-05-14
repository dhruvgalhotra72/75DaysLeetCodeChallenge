class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;

        for (int x : piles) {
            high = max(high, x);
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;

            for (int x : piles) {
                hours += (x + mid - 1) / mid;  // ceil(x / mid)
            }

            if (hours <= h) {
                ans = mid;
                high = mid - 1;   // try slower speed
            } else {
                low = mid + 1;    // need faster speed
            }
        }

        return ans;
    }
};