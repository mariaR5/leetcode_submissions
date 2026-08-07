class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int windowSize = n-k;
        int sum = 0;

        for (int i = 0; i < windowSize; i++)
            sum += cardPoints[i];

        int mini = sum;

        for (int i = windowSize; i < n; i++) {
            sum += cardPoints[i];
            sum -= cardPoints[i - windowSize];

            mini = min(mini, sum);
        }
                
        return total - mini;
    }
};