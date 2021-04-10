###############################################################
# Program:
#     Checkpoint 07a, Static
#     [instructor name obfuscated], CS165
# Author:
#     [student name obfuscated]
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : icecream.o check07a.o
	g++ icecream.o check07a.o

icecream.o : icecream.h icecream.cpp
	g++ -c icecream.cpp

check07a.o : icecream.h check07a.cpp
	g++ -c check07a.cpp

clean :
	rm *.o
	rm a.out
