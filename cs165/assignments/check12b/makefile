###############################################################
# Program:
#     Checkpoint 12b, Member Operators
#     Brother Walker, CS165
# Author:
#     Scott Currell
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : money.o check12b.o
	g++ money.o check12b.o

money.o : money.h money.cpp
	g++ -c money.cpp

check12b.o : money.h check12b.cpp
	g++ -c check12b.cpp

clean :
	rm *.o *.out
