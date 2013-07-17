========================================================================
			SimpleGame by I.Pirozhenko Project Overview (2013)
========================================================================

It is a simple game which simulates throwing of a ball, created for you by I. Pirozhenko.

The game uses winAPI to create a window, and gdi to draw. It also uses separate threads for userInteraction,
calculation of physics, and drawing.

Game structure is following:
 SimpleGame.cpp - main file which contains all stuff to initialize windows, and create game loop,
				  also it's handle user input
 physics folder - contains developed by me physics library, which simulating throwing of the object
	physics.h - main file of physics library, contains math for simulating behaviour of object
	IPhysicsObject.h - interface for physicsObject
 game folder - contains all files to realize game logic and draw game objects
	gameObject.h - abstract class for all game objects
	ball.h - realization ob ball in the game
	scene.h - class that handles all drawing stuff for objects
	game.h - core logic of the game
