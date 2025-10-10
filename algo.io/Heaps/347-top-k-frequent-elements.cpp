class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> count;

        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;

        unordered_map<int, int> dict;
        for(auto num : nums){
            dict[num]++;
        }

        for(auto num_count : dict){
            maxHeap.push({num_count.second, num_count.first});
        }

        for(int i = 0; i < k; i++){
            count.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return count;
    }
};
