class Solution {
private:
    // Function to generate primes up to n using the Sieve of Eratosthenes
    vector<int> sieve(int n) {
        vector<int> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
        return primes;
    }

public:
    int nonSpecialCount(int l, int r) {
        // Generate primes up to sqrt(1e9)
        int limit = sqrt(1e9);
        vector<int> primes = sieve(limit);
        
        int specialCount = 0;
        
        // Count squares of primes in range [l, r]
        for (int prime : primes) {
            long long primeSquare = 1LL * prime * prime;
            if (primeSquare > r) break;   // If prime^2 exceeds r, stop
            if (primeSquare >= l) specialCount++;
        }
        
        // Total numbers in range [l, r]
        int len = r - l + 1;
        
        // Non-special count = total numbers - special numbers
        return len - specialCount;
    }
};
