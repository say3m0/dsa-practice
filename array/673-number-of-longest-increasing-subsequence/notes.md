# Number of Longest Increasing Subsequence (LeetCode 673)

## Approach: Dynamic Programming (1D DP)

### 1. DP States

আমরা দুটি 1D DP array ব্যবহার করব:

- `t[i]` = Index `i`-তে শেষ হওয়া Longest Increasing Subsequence-এর maximum length।
- `count[i]` = Index `i`-তে শেষ হওয়া maximum-length Increasing Subsequence-এর সংখ্যা।

**Initialization:**

```cpp
vector<int> t(n, 1);
vector<int> count(n, 1);
```

প্রতিটি element নিজেই একটি increasing subsequence। তাই initial length এবং count উভয়ই `1`।

### 2. Transition

প্রতিটি `i`-এর জন্য আগের সব index `j` check করব।

Condition:

```cpp
if(nums[j] < nums[i])
```

অর্থাৎ `nums[j]`-এর পরে `nums[i]` বসানো সম্ভব।

এখন তিনটি situation হতে পারে।

**Case 1: নতুন LIS-এর length আগের maximum length-এর সমান।**

```cpp
if(t[i] == t[j] + 1)
    count[i] += count[j];
```

একই maximum length-এর আরেকটি subsequence পাওয়া গেলে count যোগ হবে।

**Case 2: নতুন LIS-এর length আগের maximum length-এর চেয়ে বড়।**

```cpp
else if(t[i] < t[j] + 1) {
    t[i] = t[j] + 1;
    count[i] = count[j];
}
```

এক্ষেত্রে নতুন maximum length পাওয়া গেছে। তাই length update হবে এবং count replace হবে।

**Case 3: নতুন LIS-এর length ছোট।**

কোনো update প্রয়োজন নেই।

### 3. Final Answer

প্রথমে maximum LIS length বের করব:

```cpp
int maxVal = *max_element(begin(t), end(t));
```

এরপর যেসব index-এ LIS length maximum, তাদের count যোগ করব:

```cpp
int result = 0;

for(int i = 0; i < n; i++) {
    if(t[i] == maxVal) {
        result += count[i];
    }
}
```

### 4. Complexity Analysis

- **Time Complexity:** O(n²)

  - Nested loop: O(n²)
  - Finding maximum and calculating result: O(n)

- **Space Complexity:** O(n)

  - Two DP arrays: `t` and `count`.

### 6. Key Takeaways

1. শুধু LIS length বের করলেই হবে না, প্রতিটি index-এ maximum-length LIS-এর সংখ্যাও track করতে হবে।
2. নতুন maximum length পাওয়া গেলে count replace করতে হবে।
3. একই maximum length-এর আরেকটি subsequence পাওয়া গেলে count যোগ করতে হবে।
4. Final answer পেতে maximum length-এর সব index-এর count যোগ করতে হবে.

**DP Pattern:** Two 1D DP Arrays + Nested Loop
**Time:** O(n²) | **Space:** O(n)
