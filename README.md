# Project 2 - Circular Buffer

Contributors: Mohit Rane and Suman Hosmane

## In Linux
To execute the program
<pre>
> make
> ./proj2
</pre>

To clean the .o files
<pre>
> make clean
</pre>

To execute unit test file
<pre>
> make unit
> ./unit
</pre>

To clean the unit test file executable
<pre>
> make uclean
</pre>

###Functions
<pre>
Linux - Circular buffer has various functions associated with it.
Each source file has its own header file associated with it.

main.c
------
- Invokes the various functions asked by the user.
- Functions declared in this source file.
</pre>
Command | Arguments	| Description
-------	| ---------	| -----------
help | <none>	| Lists all available functions with syntax.
addbuff | <number_of_buffers> <buffer_size/s> | Allocate one or multiple circular buffer/s.
rembuff | <buffer_number> | Remove an existing buffer.
addchar | <buffer_number> <Character> | Add a character to existing buffer.
remchar | <buffer_number> | Remove oldest character in a buffer.
resize |	<buffer_number> <+/-> <# Memory locations> | Resize existing buffer.
stat | <none> | Get current statistic on the circular buffers.
exit | <none> | Exit the program.
<pre>
unittest.c
----------
-Checks assertions for each function of circular buffer.
</pre>
