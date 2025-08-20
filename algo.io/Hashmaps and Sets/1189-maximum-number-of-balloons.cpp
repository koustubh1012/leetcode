class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> dict;
        for(int i = 0; i < text.size(); i++){
            dict[text[i]]++;
        }
        if(dict.find('b') == dict.end() ||
           dict.find('a') == dict.end() ||
           dict.find('l') == dict.end() ||
           dict.find('o') == dict.end() ||
           dict.find('n') == dict.end()){
            return 0;
        }
        return min({dict['b'], dict['a'], dict['l']/2 ,dict['o']/2 ,dict['n']});
    }
};
