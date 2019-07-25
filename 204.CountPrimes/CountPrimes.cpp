class Solution {
public:
    int countPrimes(int n) {
        /*
        if(n <= 2)
            return 0;
        if(n == 3)
            return 1;
        if(n <= 4)
            return 2;
        int count = 2;
        int i = 7;
        for(i; i < n; i += 6) {
            count += isPrime(i);
            count += isPrime(i-2);
        }
        if((i-2) < n)
            count += isPrime(i-2);
        return count;
        */
        if(n <= 1)
            return 0;
        vector<bool> vec(n-2, true);
        for(int i = 0; i < vec.size()/2; i++) {
            if(vec[i] == false)
                continue;
            int pos = (i+2)*(i+2) - 2;
            if(pos >= vec.size())
                break;
            else
                vec[pos] = false;
            for(int j = i+1; j < vec.size()/2; j++) {
                int pos = (i+2)*(j+2) - 2;
                if(pos < vec.size())
                    vec[pos] = false;
                else
                    break;
            }
        }
        int count = 0;
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == true)
                count++;
        }
        return count;
    }
    
    int isPrime(int x) {
        int n = sqrt(x);
        for(int i = 5; i <= n; i+=6) {
            if(x%i == 0 || x%(i+2) == 0)
                return 0;
        }
        return 1;
    }
};