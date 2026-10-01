# Valid Parentheses (LeetCode 20) – Code Note

## Problem Overview
Given a string containing characters `(`, `)`, `{`, `}`, `[`, and `]`, determine if the input string is valid. A string is valid if open brackets are closed by the same type of brackets and closed in the correct order.

---

## Code Approaches & Analysis

### 1. Basic Stack Approach (Explicit If-Else Conditions)

* **Concept:**
  * Iterate through the string. Push every opening bracket (`(`, `{`, `[`) onto the stack.
  * When a closing bracket is encountered, verify whether the stack is empty or if the top element matches the corresponding opening bracket. If it doesn't match, return `false`.
  * Pop the element if it matches. Finally, return `true` if the stack is completely empty.

* **Complexity:**
  * **Time Complexity:** $\mathcal{O}(n)$ — Processes each character in the string once.
  * **Space Complexity:** $\mathcal{O}(n)$ — In the worst-case scenario, the stack stores up to $n$ opening brackets.

---

### 2. Optimized Stack Approach (Using Hash Map)

* **Concept:**
  * Instead of writing multiple explicit `if-else` conditions, use an `unordered_map`.
  * Map each closing bracket as a **Key** and its corresponding opening bracket as its **Value** (e.g., `matching[')'] = '('`).
  * Use `matching.count(c)` to quickly identify whether a character is a closing bracket, resulting in cleaner and more maintainable code.

* **Complexity:**
  * **Time Complexity:** $\mathcal{O}(n)$ — String traversal takes $\mathcal{O}(n)$, while map lookups take average $\mathcal{O}(1)$ time.
  * **Space Complexity:** $\mathcal{O}(n)$ — Requires stack space plus $\mathcal{O}(1)$ auxiliary space for the map (as there are only 3 bracket pairs).

---

### 3. In-Place Custom Stack / Two-Pointer Approach (Space Optimized)

* **Concept:**
  * Emulate stack behavior using the input string `s` itself without allocating a separate `std::stack`.
  * Maintain a `top` index/pointer initialized to `-1` to represent the stack's top element.
  * For opening brackets, increment `top` (`top++`) and store the character at `s[top] = s[i]`.
  * For closing brackets, validate against `s[top]` and decrement `top` (`top--`) to simulate popping.
  * Check if `top == -1` at the end to confirm all brackets were matched.

* **Complexity:**
  * **Time Complexity:** $\mathcal{O}(n)$ — Traverses the string a single time.
  * **Space Complexity:** $\mathcal{O}(1)$ — Operates strictly in-place without additional data structures or dynamic allocations.

---

## Comparison Summary

| Approach | Time Complexity | Space Complexity | Pros | Cons |
| :--- | :--- | :--- | :--- | :--- |
| **1. Basic Stack** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | Straightforward logic | Verbose with multiple `if-else` checks |
| **2. Stack + Map** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | Clean, concise, and easy to read | Requires standard stack memory |
| **3. In-Place Stack** | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | Highly memory efficient | Mutates the original input string |