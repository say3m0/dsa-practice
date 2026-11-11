
**MINIMUM COST TO ACQUIRE REQUIRED ITEMS**

**Approach:** Greedy / Mathematical Comparison
---
**Idea:**

There are three possible ways to acquire the required items:
1. Buy all items individually.
2. Buy bundles for the common requirements and the remaining items individually.
3. Buy only bundles, even if some extra items are acquired.

---

**Steps ===>**

1. Calculate the total cost of buying all items individually.
2. Calculate the cost of buying only bundles. Since each bundle provides both types of items, we need `max(n1, n2)` bundles.
3. Calculate the Mixed Purchase cost:
   - Buy `min(n1, n2)` bundles to satisfy the common requirements.
   - Buy the remaining items individually for the type with higher requirements.
4. Return the minimum cost among these three approaches.

---


**TIME COMPLEXITY:** O(1)

**SPACE COMPLEXITY:** O(1)

---

**IMPORTANT OBSERVATION:**

Buying bundles is not always optimal, even when the bundle price is cheaper than buying both items individually.
We must consider all three possibilities: Individual, Mixed, and Only Bundle.