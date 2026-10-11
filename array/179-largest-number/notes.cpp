## Approach & Logic

1. **Convert to Strings:** Since the goal is to arrange numbers to form the largest concatenated integer, we convert all numeric elements into string representations.
2. **Custom Comparator:** We sort the strings using a custom sorting rule. For any two strings `a` and `b`, we compare their concatenated outcomes:
   - Check if `(a + b) > (b + a)`.
   - If true, `a` comes before `b`. Otherwise, `b` comes before `a`.
3. **Edge Case Handling:** After sorting, if the largest element (the first element in the sorted array) is `"0"`, it means all numbers are zero, so we return `"0"` immediately to avoid leading zeros like `"00"`.
4. **Result Concatenation:** Finally, we join all the sorted strings together to form the result.

---

## Complexity Analysis

* **Time Complexity (TC):** $\mathcal{O}(N \log N \cdot K)$
  * Where $N$ is the number of elements in the array and $K$ is the maximum number of digits in an integer. Sorting takes $\mathcal{O}(N \log N)$ comparisons, and each comparison involves string concatenation taking $\mathcal{O}(K)$ time.
* **Space Complexity (SC):** $\mathcal{O}(N \cdot K)$
  * Required to store the converted string representation of all numbers in a separate vector.