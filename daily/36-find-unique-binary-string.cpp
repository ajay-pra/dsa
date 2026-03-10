// https://leetcode.com/problems/find-unique-binary-string/description/

// one way is by generating all the binary possiblity and check for the codition 
class Solution {
public:
    void generateBinaryStrings(vector<string> &ans, string s, int n, int i){
        if(i == n){
            ans.push_back(s);
            return;
        }

        generateBinaryStrings(ans, s + "0", n, i + 1);
        generateBinaryStrings(ans, s + "1", n, i + 1);
    }

    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();
        vector<string> ans;

        generateBinaryStrings(ans, "", n, 0);

        for(int i = 0; i < ans.size(); i++){
            if(find(nums.begin(), nums.end(), ans[i]) == nums.end()){
                return ans[i];
            }
        }

        return "";
    }
};



// another way if bu switiching the diagonal of the string
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();
        string ans = "";

        for(int i = 0; i < n; i++){
            if(nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }

        return ans;
    }
};