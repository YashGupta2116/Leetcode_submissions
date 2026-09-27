class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if (totalGas < totalCost) {
            return -1;
        }

        int currGas = 0;
        int resIdx = 0;
        for (int i = 0; i < gas.size(); i++) {
            currGas += gas[i];
            if (currGas < cost[i]) {
                currGas = 0;
                resIdx = i+1;
            } else {
                currGas -= cost[i];
            }
        }

        return resIdx;
    }
};