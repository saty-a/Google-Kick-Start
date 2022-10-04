Problem
-------
Let us call an integer interesting if the product of its digits is divisible by the sum of its digits. You are given two integers A and B. Find the number of interesting integers between A and B (both inclusive).

Input
-----
The first line of the input gives the number of test cases, T. T lines follow.

Each line represents a test case and contains two integers: A and B.

Output
------
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of interesting integers between A and B (inclusive).

Limits
------
Time limit: 20 seconds.
Memory limit: 1 GB.
1≤T≤100.
Test Set 1
1≤A≤B≤105.
Test Set 2
1≤A≤B≤1012.

Sample
------

::

    Input                       Output
    4                           Case #1: 9
    1 9                         Case #2: 0
    91 99                       Case #3: 5
    451 460                     Case #1: 176
    501 1000
    
In Sample Case #1, since the product and the sum of digits are the same for single-digit integers, all integers between 1 and 9 are interesting.

In Sample Case #2, there are no interesting integers between 91 and 99.

In Sample Case #3, there are five interesting integers between 451 and 460:

#. 451 (product of its digits is 4×5×1=20, sum of its digits is 4+5+1=10).
#. 453 (product of its digits is 4×5×3=60, sum of its digits is 4+5+3=12).
#. 456 (product of its digits is 4×5×6=120, sum of its digits is 4+5+6=15).
#. 459 (product of its digits is 4×5×9=180, sum of its digits is 4+5+9=18).
#. 460 (product of its digits is 4×6×0=0, sum of its digits is 4+6+0=10).
