Problem
-------
You are given a string S consisting of characters 0, 1, and ?. You can replace each ? with either 0 or 1. Your task is to find if it is possible to assign each ? to either 0 or 1 such that the resulting string has no substrings that are palindromes of length 5 or more.

Input
-----
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case consists of two lines.
The first line of each test case contains an integer N, denoting the length of the string S.
The second line of each test case contains a string S of length N.

Output
------
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is POSSIBLE if there is a possible resulting string that has no palindromic substrings of length 5 or more, or IMPOSSIBLE otherwise.

Limits
------
Memory limit: 1 GB.
1≤T≤100.
S only consists of characters 0, 1 and ?.

Test Set 1
Time limit: 20 seconds.
1≤N≤15.
Test Set 2
Time limit: 90 seconds.
1≤N≤5×104.

Sample
------

::
  Input               Output
