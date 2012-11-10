all:
	gcc -Wall `pkg-config --libs x11 --cflags xft` -g xftmetric.c -o xftmetric
