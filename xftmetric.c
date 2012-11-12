#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>
#include <stdio.h>

void usage(char *argv[])
{
	printf("Usage: %s <font name> <size>\n", argv[0]);
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		usage(argv);
		return 1;
	}

	XftFont *font;
	Display *dpy = XOpenDisplay(NULL);
	int screen = 0;
	font = XftFontOpen (dpy, screen,
			XFT_FAMILY, XftTypeString, argv[1],
			XFT_SIZE, XftTypeDouble, atof(argv[2]),
			NULL);

	if (!font) {
		printf("No font: %s\n", argv[1]);
		return 1;
	}

	printf("XFTM_ASCENT=%d;\n", font->ascent);
	printf("XFTM_DESCENT=%d;\n", font->descent);
	printf("XFTM_HEIGHT=%d;\n", font->height);
	printf("XFTM_MAX_ADVANCE=%d;\n", font->max_advance_width);

	return 0;
}
