
## Problem: Subarrays Distinct Element Sum of Squares I

### Approach 1: Ordered Set

**Idea:**
- Fix the starting index `i`.
- Extend the subarray using `j`.
- Use a `set` to store distinct elements.
- Add `s.size() * s.size()` to the answer.


**Time Complexity:** O(n² log n)  
**Space Complexity:** O(n)

---

### Approach 2: Frequency Hash Map

**Idea:**
- Fix the starting index `i`.
- Extend the subarray using `j`.
- Maintain the frequency of each element.
- If an element appears for the first time, increase `distinct`.
- Add `distinct * distinct` to the answer.


**Time Complexity:** O(n²) average  
**Space Complexity:** O(n)
  