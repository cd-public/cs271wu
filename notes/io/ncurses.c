#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

// debug
#define VERBOSE 1
#define BUFF 16

// gameplay
#define HIGH 10
#define WIDE 10

#define CHAR '@'

#define CMDS 7

#define REDO 'r'
#define QUIT 'q'
#define PAUS 'p'

#define FORE 'w'
#define BACK 's'
#define LEFT 'a'
#define RITE 'd'

void show(char *xety )
{
	char line[WIDE + 2]; // 80 printable characters + new line + null terminator
	
	line[0       ] = '|';
	line[WIDE - 1] = '|';
	line[WIDE    ] = '\n';
	line[WIDE + 1] = '\0';	
	
	putchar('\n');
	
	for ( int i = 0 ; i < HIGH ; i ++ ) 
	{
		for ( int j = 1 ; j < WIDE - 1 ; j ++ )
		{
			line[j] = ' ';
			if (i == 0 || i == HIGH - 1) { // top or bottom
				line[j] = '-';
			} else if (i == xety[0] && j == xety[1]) { // snak
				line[j] = CHAR;
			} else if (!(j % 8)) {
				line[j] = '.';
			}
		}
		printf("%s",line);
	}
	return;
}

int play()
{
	char dirc = 'w';
	char xety[2];
	xety[0] = WIDE / 2;
	xety[1] = HIGH / 2;
		initscr();
	while (1)
	{
		dirc = getch();
		if (REDO == dirc) {
			xety[0] = WIDE / 2;
			xety[1] = HIGH / 2;
		} else if (FORE == dirc) {
			xety[0]--;
		} else if (BACK == dirc) {
			xety[0]++;
		} else if (LEFT == dirc) {
			xety[1]--;
		} else if (RITE == dirc) {
			xety[1]++;
		} else {
			return 0; // quit || error case
			endwin();
		}
		show(xety);
		printf("(x,y) = %d, %d\n", xety[0], xety[1]);
		//printf("%c\n",dirc);
	}
}

int main()
{
    return play();
}
