**Problem :** [https://leetcode.com/problems/circle-and-rectangle-overlapping/description/](https://leetcode.com/problems/circle-and-rectangle-overlapping/description/?utm_source=gemini)
--
**Circle and Rectangle Overlapping**
--
## Approach ===>

**Optimal Approach** : CLAMPING TO CLOSEST POINT (EUCLIDEAN DISTANCE)
--
--
--
1. Find the point on or inside the rectangle that is closest to the circle's center `(xCenter, yCenter)`.
2. **Finding `closestX`:**
* If `xCenter` is between `x1` and `x2`, then `closestX = xCenter`.
* If `xCenter` is to the left of `x1`, then `closestX = x1`.
* If `xCenter` is to the right of `x2`, then `closestX = x2`.
* *(In C++ shortcut: `closestX = max(x1, min(x2, xCenter))`)*
--
--

3. **Finding `closestY`:**
* Similarly, clamp `yCenter` between `y1` and `y2`: `closestY = max(y1, min(y2, yCenter))`.
--
--
4. Calculate horizontal distance `distX = xCenter - closestX` and vertical distance `distY = yCenter - closestY`.
5. Compute the squared Euclidean distance: `distanceSquared = (distX * distX) + (distY * distY)`.
6. Compare `distanceSquared` with `radius * radius`. If `distanceSquared <= radius * radius`, return `true`; otherwise, return `false`.
--
--
**WHY CLAMPING LOGIC IS USED :**

* `max(x1, min(x2, xCenter))` automatically finds the nearest boundary point if `xCenter` is outside, or stays at `xCenter` if it is inside.
* If the circle center is strictly inside the rectangle, `distX = 0` and `distY = 0`, resulting in `distanceSquared = 0`, which correctly returns `true`.
* Using squared distances avoids floating-point precision errors from `sqrt()` and `pow()`.
--
--
**TIME COMPLEXITY : O(1)**
**SPACE COMPLEXITY : O(1)**
--