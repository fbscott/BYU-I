###############################################################
# Program:
#     Checkpoint 12a, Nonmember Operators
#     [instructor name obfuscated], CS165
# Author:
#     [student name obfuscated]
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : money.o check12a.o
	g++ money.o check12a.o

money.o : money.h money.cpp
	g++ -c money.cpp

check12a.o : money.h check12a.cpp
	g++ -c check12a.cpp

clean :
	rm *.o *.out
