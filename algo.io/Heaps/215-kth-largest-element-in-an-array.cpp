class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // create max heap
        priority_queue<int> maxHeap(nums.begin(), nums.end());

        // pop the elements untill the kth element
        for(int i = 0; i < k - 1; i++) maxHeap.pop();

        // return the top element
        return maxHeap.top();
    }
};
