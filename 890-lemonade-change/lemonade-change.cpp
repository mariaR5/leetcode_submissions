class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(int amt: bills) {
            if (amt == 5) {
                five++;
                continue;
            }

            if (amt == 10) {
                ten++;
                if (five > 0)
                    five--;
                else return false;
            } 

            if (amt == 20) {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else return false;
            } 
        }
        return true;
    }
};