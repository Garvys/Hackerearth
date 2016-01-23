<h3>Problem Statement</h3>

It's a fine sunny afternoon today in California. Looking at the pleasant weather, Sumit is all ready to go out and play with his friend Rohil. Unfortunately, Rohil is down with fever. Seeing that his friend is ill, Sumit decides not to go out - instead play with Rohil inside the house. Sumit loves math, on the contrary Rohil loves strings. Sumit decides to play a game that involves more of strings and less of Maths so that Rohil could be at ease and have fun playing it.

The game is simple and is played on a piece of paper. Sumit writes down a long list of names on that paper and passes it to Rohil. Rohil gets confused on seeing so many names on that paper and asks Sumit about the game. So, Sumit explains him the rules of the game. Rohil is supposed to partition the names into groups, such that:

Each name belongs to exactly one group.
Names that belong to the same group are pairwise anagrams.
The first character of all the names in the same group are equal.
The last character of all the names in the same group are equal.
The number of groups is minimum possible.
Note: Two strings are called anagrams if it's possible to form one string from the other by changing the order of its characters.

Rohil would have won the game easily, if he would have been fit and fine but since he is ill right now he needs your help in winning the game. So, help out Rohil and do give him your blessings.

<h5>Input:</h5>

The first line contains a single integer N indicating the size of the list. This is followed by N lines where each line contains a name listed by Sumit.

<h5>Output:</h5>

In a single line print minimum number of groups in a partition that satisfy above conditions

<h6>Constraints:</h6>

1<= N <=100
1 <= Length of a name <= 100

All names will consist of lowercase English alphabets(a-z).

<h6>Sample Input</h6>

6
vinay
vainy
vinit
viint
avinash
aasivnh

<h6>Sample Output</h6>

3

<h6>Explanation</h6>

There are 3 special groups

1) vinay and vainy

2) vinit and viint

3) avinash and aavsinh

<h5>Result</h5>

Work perfectly!