class Solution {
public:
    int getSum(int a, int b) {
        /*
        int sum=a^b;
        int carry=((unsigned int)a&b)<<1;
        while(carry) {
            int tmp=sum^carry;
            carry=((unsigned int)sum&carry)<<1;
            sum=tmp;
        }
        return sum;
        */
        
        /*
        while(a&b){
            int m=a;
            int n=b;
            a=m^n;
            b=(unsigned int)(m&n)<<1;
        }
        return a^b;
        */
        
        /*
        if(a&b){
            return getSum(a^b, ((unsigned int)a&b)<<1);
        }
        return a^b;
        */
        
        do {
            int sum=a^b;
            b=((unsigned int)a&b)<<1;
            a=sum;
        } while(a&b);
        return a^b;
    }
};