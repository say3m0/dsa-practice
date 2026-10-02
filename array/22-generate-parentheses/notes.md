# LeetCode 22: Generate Parentheses

## 💡 Key Approach: Backtracking & Pruning

সমস্যাটি সমাধানের জন্য **Brute Force** দিয়ে $2^{2n}$ টি সম্ভাব্য কম্বিনেশন বানিয়ে পরে validity check করার প্রয়োজন নেই। **Backtracking** ব্যবহার করে শুরু থেকেই কেবল Valid ব্র্যাকেট স্ট্রাকচার তৈরি করা সম্ভব।

### ব্যাকট্র্যাকিংয়ের ৩টি মূল নিয়ম:
1. **`(` যোগ করার শর্ত:** `open > 0` থাকা পর্যন্ত যেকোনো সময় একটি `(` যোগ করা যাবে।
2. **`)` যোগ করার শর্ত:** `close > 0` এবং অবশিষ্ট `open < close` হতে হবে (অর্থাৎ এর আগে ব্যবহৃত `(` এর সংখ্যা `)` এর চেয়ে বেশি ছিল)।
3. **Base Case:** যখন `open == 0` এবং `close == 0` হবে, তার মানে একটি পূর্ণাঙ্গ Valid String তৈরি হয়ে গেছে—সেটিকে রেজাল্ট লিস্টে যুক্ত করতে হবে।

---

## ⏱️ Complexity Analysis

* **Time Complexity:** $O\left(\frac{4^n}{\sqrt{n}}\right)$ — এটি $n$-তম **Catalan Number** নির্দেশ করে। প্রতিটি Valid String তৈরি করতেই কেবল এগোয়, কোনো বাজে স্টেট ট্রাই করে না।
* **Space Complexity:** $O(n)$ — Recursion Call Stack এর সর্বোচ্চ গভীরতা এবং Current String `s` এর সাইজ সর্বোচ্চ $2n$ পর্যন্ত হতে পারে।

---

## 🌳 Step-by-Step Execution Flow ($n = 2$)

### Execution Tree Diagram

```text
                           generate("", open=2, close=2)
                                       |
                                   push '('
                                       v
                           generate("(", open=1, close=2)
                                   /            \
                           push '('              push ')'
                             /                      \
       generate("((", open=0, close=2)      generate("()", open=1, close=1)
                      |                                    |
                   push ')'                             push '('
                      v                                    v
       generate("(()", open=0, close=1)     generate("()(", open=0, close=1)
                      |                                    |
                   push ')'                             push ')'
                      v                                    v
       generate("(())", open=0, close=0)    generate("()()", open=0, close=0)
              [ADDED TO RESULT]                    [ADDED TO RESULT]