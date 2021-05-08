vector<vector<bool>> find_all_palindromes(const string& text) {
    int n = text.size();
    vector<vector<bool>> palindromes(n, vector<bool>(n, false));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                palindromes[i][j] = true;
            }
            else if(text[i] == text[j]) {
                if(j - i == 1) {
                    palindromes[i][j] = true;
                }
                else {
                    palindromes[i][j] = palindromes[i + 1][j - 1];
                }
            }
        }
    }

    return palindromes;
}

// Time - O(N^2), Space - O(N^2)
int Solution::minCut(string A) {
    int n = A.size();
    if(n == 0) {
        return 0;
    }

    vector<vector<bool>> palindromes = find_all_palindromes(A);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            cout<<palindromes[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> dp(n);

    for(int i = 0; i < n; i++) {
        dp[i] = INT_MAX;
        if(palindromes[0][i]) {
            dp[i] = 0;
        }
        else {
            //We fix the i and move with j backward 
            //and check the minimum cut position
            for(int j = i; j > 0; j--) {
                if(palindromes[j][i]) {
                    dp[i] = min(dp[j - 1] + 1, dp[i]);
                }
            }
        }
    }

    return dp[n - 1];
}






0 1 0 1 1 1 2 1 2 2 2 3 2 3
ababbbabbababa


O(N^3)
int Solution::minCut(string s) {
       int n = s.length();
       //Dp table to store minimum Length
       int dp[n][n];
       
       //To keep a track of index are they palindrome
       bool P[n][n];
       
       //Zero length is always palindrome
       for(int i=0;i<n;i++){
           dp[i][i]=0;
           P[i][i]=true;
       }
       
       //Length 2, if both character matches
       //then palindrome and give a cut
       for(int i=0;i<n-1;i++){
           int j=i+1;
           if(s[i]==s[j]){
               dp[i][j]=0;
               P[i][j]=true;
           }else{
               dp[i][j]=1;
               P[i][j]=false;
           }
       }
       
       //Length of string
       for(int diagonal=3;diagonal<=n;diagonal++){
           for(int start=0;start<n-diagonal+1;start++){
               int end = start+diagonal-1;
               P[start][end] = (s[start] == s[end]) && P[start + 1][end - 1];
               if(P[start][end]==true){
                   dp[start][end]=0;
               }else{
                  dp[start][end] = INT_MAX; 
                for (int k = start; k <= end - 1; k++) 
                    dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] + 1);
               }
           }
       }
    return dp[0][n-1];
}
