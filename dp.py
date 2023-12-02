def wordBreak(s, wordDict):
    n = len(s)
    dp = [False] * (n + 1)# Create a dynamic programming array to store if substrings can be segmented
    dp[0] = True  # An empty string can be segmented
    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in wordDict:
                print(s[j:i])
                dp[i] = True
                break
    return dp[n]  # True if the entire string can be segmented

# Example usage
s = "leetcode"
wordDict = ["leet", "code"]
result = wordBreak(s, wordDict)
print(result)  # This will print True in this example