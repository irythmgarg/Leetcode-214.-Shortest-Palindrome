# Leetcode-214.-Shortest-Palindrome
# 🧵 Shortest Palindrome using KMP

## 📘 Problem

Given a string `s`, you are allowed to add characters **in front** of it to make it a palindrome. Return the **shortest palindrome** you can construct.

---

## 💡 Approach: KMP (Knuth-Morris-Pratt)
We solve this by:

1. Reversing the string `s → rev`.
2. Appending them in a smart way: `combined = s + '*' + rev`.
3. Applying KMP's prefix function on this `combined` string.
4. Use the longest prefix match to avoid re-adding characters that are already palindromic.

---
⏱️ Time and Space Complexity
Time: O(N) — One pass for KMP prefix table.
Space: O(N) — For LPS (prefix) array and reverse string.

✨ Topics
KMP algorithm
String pattern matching
Palindrome construction
Prefix table (LPS)



---

## 🧠 Example

### Input:
```cpp
s = "aacecaaa"
Output:
"aaacecaaa"

