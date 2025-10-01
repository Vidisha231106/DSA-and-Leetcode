//Recursive Fast Power Algo
double myPow(double x, int n) {
    if (n == 0) return 1.0;          // Base case
    if (n < 0) return 1.0 / myPow(x, -n);  // Handle negative powers
    
    // Divide-and-conquer
    double half = myPow(x, n / 2);
    if (n % 2 == 0) {
        return half * half;          // Even power
    } else {
        return x * half * half;      // Odd power
    }
}

//Brute Force
double myPow(double x, int n) {
    double ans = 1.0;
    for (int i = 0; i < n; i++) {
        ans = ans * x;
    }
    return ans;
}

//Iterative Binomial Exponentiation
double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;
    if (nn < 0) nn = -1 * nn;
    while (nn) {
        if (nn % 2) {
            ans = ans * x;
            nn = nn - 1;
        } 
        else {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}


