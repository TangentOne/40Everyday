class Solution {
public:
    int getSum(int n) {
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 3;
        }
        return getSum(n-1)+n;
    }
    
};
