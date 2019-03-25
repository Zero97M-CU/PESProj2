# Project 2 - Circular Buffer, UART and Interrupts

Contributors: Mohit Rane and Suman Hosmane

Description:

This project includes 
- Circular buffer implementation for Linux and FRDM-KL25Z.
- Driver code for UART.
- Application that receives characters from the UART, keeps track of the number of occurences of each of 256 possible characters and sends an updated ASCII formatted report back to the UART for display on a terminal.

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

### Functions

Linux - Circular buffer has various functions associated with it.
Each source file has its own header file associated with it.

#### main.c
- Invokes the various functions asked by the user.
- Functions declared in this source file.

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

#### unittest.c
- Checks assertions for each function of circular buffer.

### Linux Functioning Example


## In Kinetis Design Studio (for FRDM-KL25Z)
Installation Steps:
1. Add both projects present in the KDS folder.
2. Build ksdk_platform_lib_KL25Z4 first, and then hello_world_frdmkl25z.
