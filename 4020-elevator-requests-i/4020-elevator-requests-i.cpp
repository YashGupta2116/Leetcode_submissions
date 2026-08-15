class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int currFloor = 0;
        int totalTime = 0;
        for (int& request: requests) {
            totalTime += abs(currFloor - request);
            currFloor = request;
        }

        return totalTime;
    }
};