Our program was built using the makefile which compiled our code. That was ran by typing the make all command in the terminal, and we ran the program by typing ./project1 in the terminal. Initially we ran into the issue of obtaining information for each process because we weren't sure how to insert the differnt pids in the fopen("proc/pid/stat", "r") statement to pull info for each process. It was interesting to see that we had to scan the file for all of its contents as well. Something else that was troubling was printing out the information that would form the tree. We got a segmentation fault a few times, and we also couldn't get the output to print in a tree format even though we atempted.

We submitted 2 programs: project1.c and project1nonfunct.c. Project1 runs, but the information is not formatted in a tree. In project1nonfunct.c, we kept getting a segmentation fault when trying to save the data to a link lists. 


