class Solution {
public:
     int numJewelsInStones(string J, string S) {
        vector<int> map(128, 0);
        int res = 0;        
        for (char& c : J) map[c]++;
        for (char& c : S) if (map[c]) res++; 
        return res;
    }
};