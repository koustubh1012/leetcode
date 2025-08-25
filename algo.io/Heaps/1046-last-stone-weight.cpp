class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // create max heap
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        // do while the max heap size is grater than 1
        while(maxHeap.size() > 1){
            // get the greates element
            int y = maxHeap.top();
            maxHeap.pop();

            // get the second greatest element
            int x = maxHeap.top();
            maxHeap.pop();

            // check if the weights are unequal
            if(x != y) maxHeap.push(y - x);
        }

        // return 0 if empty 
        if(maxHeap.empty()) return 0;

        // return the weight of remaining stone
        return maxHeap.top(); 
    }
};
