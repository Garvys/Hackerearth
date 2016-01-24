<h3>Problem Statement</h3>

You are converting an old code for a new version of the compiler.

In the old code we have used "->" for pointers. But now we have to replace each "->" with a ".". But this replacement shouldn't be done inside commments. A comment is a string that starts with "//" and terminates at the end of the line.

<h5>Input:</h5>

At max. 2000 lines of code.

Each line of code consists of at maximum 60 characters.

<h5>Output:</h5>

New code with required changes.

<h6>Sample Input</h6>

int t; //variable t
t->a=0;  //t->a does something
return 0;

<h6>Sample Output</h6>

int t; //variable t
t.a=0;  //t->a does something
return 0;

<h6>Explanation</h6>

"->" is not converted to "." inside comments.

<h5>Result</h5>

Work perfectly!