class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> mpp;

        for (int num: hand)
            mpp[num]++;

        while (!mpp.empty()) {
            int prev = mpp.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                int cur = prev + i;
                
                if (mpp.find(cur) == mpp.end()) return false;
                mpp[cur]--;

                if (mpp[cur] == 0) mpp.erase(cur);
            }    
        }
        
        return true;
    }
};