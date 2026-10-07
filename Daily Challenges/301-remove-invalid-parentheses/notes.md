# Problem : [Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)

Aro binno binno approach e korbe
# **REMOVE INVALID PARENTHESES**

## Approach ===>

---

### *Backtracking*

---

### Main Idea

We will use **Backtracking** to generate all possible strings by deciding for every parenthesis whether we:

* **Keep** it
* **Remove** it

But we don't need to generate every possibility blindly.

We can use some important conditions to **prune invalid branches**.

---

### 1. Maintain `count` to check parenthesis balance

`count` represents the current number of unmatched opening parentheses.

For every character:

```text
'('  → count + 1
')'  → count - 1
```

For normal characters:

```text
count remains unchanged
```

If at any point:

```text
count < 0
```

then the current string has more closing parentheses than opening parentheses.

So this branch can never become valid.

Therefore:

```cpp
if (count < 0)
    return;
```

This is our **pruning condition**.

---

### 2. At every parenthesis, we have two choices

For a parenthesis, we can either:

```text
Keep it
```

or

```text
Remove it
```

So we create two recursive branches.

#### Keep the current parenthesis

First add it to `curr`:

```cpp
curr.push_back(s[i]);
```

Then update `count`:

```cpp
count + (s[i] == '(' ? 1 : -1)
```

and recursively process the next character.

```cpp
solve(
    s,
    i + 1,
    curr,
    count + (s[i] == '(' ? 1 : -1),
    maxLen
);
```

After returning from recursion, remove it from `curr` because we need to backtrack:

```cpp
curr.pop_back();
```

---

#### Remove the current parenthesis

After backtracking, we don't add the current parenthesis.

We simply call:

```cpp
solve(s, i + 1, curr, count, maxLen);
```

So the two choices are:

```text
                 current parenthesis
                    /          \
                 Keep          Remove
                  /               \
             update count       same count
```

---

### 3. Normal characters

If the current character is neither `(` nor `)`:

```cpp
if (s[i] != '(' && s[i] != ')')
```

then there is no reason to remove it.

We simply add it to `curr`:

```cpp
curr.push_back(s[i]);
```

and continue recursion:

```cpp
solve(s, i + 1, curr, count, maxLen);
```

Then backtrack:

```cpp
curr.pop_back();
```

---

### 4. Check when we reach the end

When:

```cpp
i == n
```

we have processed the whole string.

A valid parenthesis string must have:

```text
count == 0
```

So:

```cpp
if (count == 0)
```

then `curr` is a valid string.

---

### 5. Why use `maxLen`?

The problem asks us to remove the **minimum number of parentheses**.

Since we only remove characters:

```text
minimum deletion
        ↓
maximum remaining length
```

Therefore, among all valid strings, we only keep the strings having the **maximum length**.

Suppose we first find:

```text
curr = "()()"
length = 4
```

Then:

```text
maxLen = 4
```

If later we find a valid string with length `5`:

```text
curr = "(())()"
length = 6
```

then this is better because fewer characters were removed.

So:

```cpp
if (curr.length() > maxLen) {
    maxLen = curr.length();
    st.clear();
}
```

We clear the previous answers because they required more removals.

---

### 6. Store all valid strings with maximum length

If:

```cpp
curr.length() == maxLen
```

then this string is one of the valid answers.

We insert it into:

```cpp
unordered_set<string> st;
```

Using a set also automatically removes duplicate strings.

```cpp
st.insert(curr);
```

---

## Complete Logic

```text
Start
  ↓
Process current character
  ↓
Is it normal character?
  ├── Yes → Keep it → Continue
  │
  └── No
       ↓
   Two choices
    /       \
 Keep       Remove
  ↓            ↓
Update       Same count
count
  ↓
If count < 0
  ↓
Prune branch
  ↓
Reach end?
  ↓
If count == 0
  ↓
Valid string
  ↓
Keep only maximum-length strings
```
---

# Complexity

For every parenthesis, we have two choices:

```text
Keep
Remove
```

So in the worst case, we may generate approximately:

```text
2^n
```

possible subsequences.

For each complete string, we may perform `O(n)` work.

Therefore, the worst-case time complexity is approximately:

```text
TIME COMPLEXITY : O(n × 2^n)
```

The recursion depth and current string require:

```text
O(n)
```

space.

However, the `unordered_set` stores all valid results, so if the output space is included:

```text
SPACE COMPLEXITY : O(n × number of valid answers)
```

Ignoring the output storage:

```text
AUXILIARY SPACE : O(n)
```

---

# Key Takeaways

1. **Backtracking:** Every parenthesis has two choices — keep or remove.

2. **`count`:** Tracks the balance of `(` and `)`.

3. **Pruning:** If `count < 0`, the current branch is already invalid, so stop exploring it.

4. **Valid string:** At the end, `count` must be `0`.

5. **Minimum removal:** Since we only remove characters, keep the valid strings having the **maximum length**.

6. **`unordered_set`:** Used to avoid duplicate valid strings.

7. **Backtracking:** After choosing `Keep`, use `pop_back()` to restore `curr` before exploring the `Remove` branch.
