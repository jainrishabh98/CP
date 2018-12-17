/*

First of all, for each closing bracket in our string let's define 2 values:
d[j] = position of corresponding open bracket, or -1 if closing bracket doesn't belong to any regular bracket sequence.
 c[j] = position of earliest opening bracket, such that substring s(c[j], j) (both boundaries are inclusive) is a regular bracket
  sequence. Let's consider c[j] to be -1 if closing bracket doesn't belong to any regular bracket sequence.
It can be seen, that c[j] defines the beginning position of the longest regular bracket sequence, which will end in position j. 
So, having c[j] answer for the problem can be easily calculated.

Both d[j] and c[j] can be found with following algorithm, which uses stack.
Iterate through the characters of the string.
If current character is opening bracket, put its position into the stack.
If current character is closing bracket, there are 2 subcases:
Stack is empty - this means that current closing bracket doesn't have corresponding open one. Hence, both d[j] and c[j] are
 equal to -1.
Stack is not empty - we will have position of the corresponding open bracket on the top of the stack - let's put it to d[j] 
and remove this position from the stack. Now it is obvious, that c[j] is equal at least to d[j]. But probably, there is a better
 value for c[j]. To find this out, we just need to look at the position d[j] - 1. If there is a closing bracket at this position,
  and c[d[j] - 1] is not -1, than we have 2 regular bracket sequences s(c[d[j] - 1], d[j] - 1) and s(d[j], j), which can be
   concatenated into one larger regular bracket sequence. So we put c[j] to be c[d[j] - 1] for this case.


*/