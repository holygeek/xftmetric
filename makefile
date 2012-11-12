all:
	gcc -Wall `pkg-config --libs x11 --cflags xft` xftmetric.c -o xftmetric
