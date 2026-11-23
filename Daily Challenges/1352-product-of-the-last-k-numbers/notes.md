# LeetCode 1352. Product of the Last K Numbers

**Problem:** [https://leetcode.com/problems/product-of-the-last-k-numbers/](https://leetcode.com/problems/product-of-the-last-k-numbers/)

**Approach:** Prefix Product + Zero Handling

### Complexity Analysis

- **Time Complexity:** O(1) for both `add()` and `getProduct()`.
- **Space Complexity:** O(n).

### Key Idea

- Maintain cumulative products in a vector.
- Reset the vector when zero appears.
- Use prefix product division to calculate the product of the last `k` elements.
- If `k >= product.size()`, return `0` because the requested range contains a zero.
