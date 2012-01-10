,>,<            get the two values to #0 and #1
[>>+>+<<<-]	make a copy of #0 to #2 and #3 (#0 is now 0)
>>		goto #2
[<+>-]		add #2 to #1 (#2 is now 0)
>		goto #3
[<<<+>>>-]	copy #3 to #0 (#3 is now 0)
<<.		print #1
<.		print #0

