
def numDecodings(A):
        if not A: return 0
        dp = [0 for x in range(len(A)+1)]
        dp[0] = 1
        for i in range(1,len(A)+1):
            if A[i-1] != '0':
                dp[i] += dp[i-1]
            if i!=1 and A[i-2:i] < "27" and A[i-2:i] > "09":
                dp[i] += dp[i-2]
        return dp[len(A)]

print numDecodings("323222")
