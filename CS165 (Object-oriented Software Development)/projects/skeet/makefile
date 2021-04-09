###############################################################
# Program:
#     Project 09, Skeet
#     Brother Walker, CS165
# Author:
#     Scott Currell
# Summary:
#     Put your summary code here... 
# Above and Beyond
#     Added rounds fired, hits, and accuracy stats to screen. Don't know why
#		accuracy stat isn't working correctly :(
###############################################################

LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o flyingObject.o bird.o toughBird.o sacredBird.o bullet.o 
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o rifle.o flyingObject.o bird.o toughBird.o sacredBird.o bullet.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.o toughBird.o sacredBird.o
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp

flyingObject.o: flyingObject.h flyingObject.cpp point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

bird.o: bird.h bird.cpp flyingObject.h
	g++ -c bird.cpp

toughBird.o: toughBird.h toughBird.cpp bird.h
	g++ -c toughBird.cpp

sacredBird.o: sacredBird.h sacredBird.cpp bird.h
	g++ -c sacredBird.cpp

bullet.o: bullet.h bullet.cpp flyingObject.h
	g++ -c bullet.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
