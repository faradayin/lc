class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int i=0, j=numbers.size()-1;
        while(i < j)
        {
            if(numbers[i] + numbers[j] == target) return vector<int>{i,j};
            if(numbers[i] + numbers[j] > target) j--;
            else i++;


        }
        return vector<int>(2,0);
    }
};