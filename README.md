# Project 2 - Circular Buffer

## In Linux

-----------------------------------------------------------------------------------------------
To execute the program,
> make
> ./proj2

To clean the .o files,
> make clean

To execute unit test file
> make unit
> ./unit

To clean the unit test file executable
> make uclean
-------------------------------------------------------------------------------------------------

###Functions

Linux - Circular buffer has various functions associated with it.
Each source file has its own header file associated with it.

main.c
------
- Invokes the various functions asked by the user.
- Functions declared in this source file.

Command		Arguments									                    Description
-------		---------									                    -----------
help			<none>							                          Lists all available functions with syntax.
addbuff		<number_of_buffers> <buffer_size/s>			      Allocate one or multiple circular buffer/s.
rembuff		<buffer_number>								                Remove an existing buffer.
addchar		<buffer_number> <Character>					          Add a character to existing buffer.
remchar		<buffer_number>								                Remove oldest character in a buffer.
resize		<buffer_number> <+/-> <# Memory locations>	  Resize existing buffer.
stat		  <none>										                    Get current statistic on the circular buffers.
exit		  <none>										                    Exit the program.

unittest.c
----------
-Checks assertions for each function of circular buffer.
