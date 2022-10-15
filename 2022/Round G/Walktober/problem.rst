Problem
-------
John participates in an annual walking competition called Walktober. The competition runs for a total of N days and tracks the daily steps of the participants for all the N days. Each participant will be assigned a unique ID ranging from 1 to M where M is the total number of registered participants. A global scoreboard is maintained tracking the daily steps of each participant.

John is determined to win Walktober this year and his goal is to score the maximum daily steps on each of the N days among all the participants. Having participated in Walktober last year as well, he wanted to know how many steps he fell short of in achieving his goal. Given the previous year scoreboard, calculate the minimum additional steps he needed over his last year score in order to achieve his goal of scoring the maximum daily steps every day.

Input
-----
The first line of the input gives the number of test cases, T. T test cases follow.
The first line of each test case contains three integers M, N, and P denoting the total number of participants, the total number of days the competition runs, and the last year participant ID of John.
The next M lines describe the scoreboard of the previous year and contains N integers each. The j-th integer of the i-th line denotes the step count Si,j of the participant with ID i on the j-th day of the competition.

Output
------
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum total additional steps needed by John to achieve his goal.

Limits
------
Memory limit: 1 GB.
1≤T≤100.
1≤N≤31.
1≤Si,j≤60000 for all i and j.
1≤P≤M.

Sample
------

::

    Input                       Output
     1                  
   2 3 1                         Case #1: 500
 1000 2000 3000
 1500 1500 3000

    
In the Sample Case, the competition ran for 3 days and the participant ID of John was 1. On day 1, as the other participant has more steps, John needs 500 additional steps. On the rest of the days, as John already has the maximum steps, he needs no additional steps. So, he needs a total of 500 additional steps to achieve his goal.
