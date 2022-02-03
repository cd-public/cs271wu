#include <stdlib.h>
#include <stdio.h>
 
// rip from https://rosettacode.org/wiki/Bitmap/Write_a_PPM_file#C
// try "convert olympic.ppm olympic.png" and follow the install instructions to get a png
 
 
// given a points x and y, a circles x and y center, the radius and thickness, see if p is in the circle
int in_circle(int px, int py, int cx, int cy, int r, int t)
{
	int d = (px - cx) * (px - cx) + (py - cy) * (py - cy);
	return d > (r - t) * (r - t) && d < r * r;
}

char **make_colors()
{
	// blue yellow black green red white
	char **ret = (char **)malloc(sizeof(char *) * 6);
	for ( int i = 0 ; i < 6 ; i++ ){
		ret[i] = (char *)malloc(sizeof(char) * 3);
	}
	ret[0][0] = 0, 	ret[0][1] = 0, 	ret[0][2] = 255;
	ret[1][0] = 255, 	ret[1][1] = 255, 	ret[1][2] = 0;
	ret[2][0] = 0, 	ret[2][1] = 0, 	ret[2][2] = 0;
	ret[3][0] = 0, 	ret[3][1] = 255, 	ret[3][2] = 255;
	ret[4][0] = 255, 	ret[4][1] = 0, 	ret[4][2] = 0;
	ret[5][0] = 255, 	ret[5][1] = 255, 	ret[5][2] = 255; 
	return ret;	
}

int **make_circles(int r, int t)
{
	int **ret = (int **)malloc(sizeof(int *) * 5), i, j;
	for ( i = 0 ; i < 5 ; i++ ) {
		j = i + 1;
		ret[i] = (int *)malloc(sizeof(int) * 2);
		ret[i][0] = (r + t / 2) * j - t / 2; 
		ret[i][1] = r + !( j & 1 ) * (r + t / 2);
	}
	return ret;
}

int get_color(int px, int py, int **circles, int height, int r, int t)
{
	int ret = 5, i;
	if (px < height >> 1)
	{
		for ( i = 0 ; i < 5 ; i++ )
		{
			if (in_circle(px, py, circles[i][0], circles[i][1], r, t))
			{
				ret = i;
			}
		}
	} else {
		for ( i = 4 ; i >= 0 ; i-- )
		{
			if (in_circle(px, py, circles[i][0], circles[i][1], r, t))
			{
				ret = i;
			}
		}
	}
	return ret;
}
 
// Given a radius and thickness of circles, construct the olympic flag.
void make_flag(int r, int t)
{
	// Calculate image size and global values
	int height = r * 3 + t / 2, width = r * 6 + 2 * t, x = 0, y = 0;
	char **colors = make_colors();
	int **circles = make_circles(r,t);

	//defaults
	FILE *fp = fopen("olympic.ppm", "wb"); /* b - binary mode */
	fprintf(fp, "P6\n%d %d\n255\n", width, height);
	
	// calculate pixels
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			fwrite(colors[get_color(x,y,circles,height,r,t)], 1, 3, fp);
		}
	}
	fclose(fp);
	return;
}

 
int main()
{
	make_flag(200,20);
	return 0;
}
