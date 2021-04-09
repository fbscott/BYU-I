###############################################################
# Program:
#     Checkpoint 07b, Pointers and Minecraft
#     Brother Walker, CS165
# Author:
#     Scott Currell
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : voxel.o world.o check07b.o
	g++ voxel.o world.o check07b.o

voxel.o : voxel.h voxel.cpp
	g++ -c voxel.cpp

world.o : world.h voxel.h world.cpp
	g++ -c world.cpp

check07b.o : voxel.h world.h check07b.cpp
	g++ -c check07b.cpp

clean :
	rm *.o
	rm a.out
