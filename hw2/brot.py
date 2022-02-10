# Buddhabrot

# s/o Melinda Green - https://en.wikipedia.org/wiki/Buddhabrot

# Imports - if you need these, use "pip install <name>"

from PIL import Image # instead of ppms
import numpy as np # instead of ppms

# Name:  Create Base
# In:  size, the side length of a square two dimensional array in pixels
# Out:  a two dimensional array size by size of pixels that are each a three list of zeroes [0,0,0]
# Description/Example:  Create a base similar to "pixels" shown here 
# https://stackoverflow.com/questions/46923244/how-to-create-image-from-a-list-of-pixel-values-in-python3
# Let create_base(20)[5][10] represent the 10th element in the 5th row (where indices start at 0)
# create_base(2) = [[[0,0,0,],[0,0,0]],[[0,0,0,],[0,0,0]]]
def create_base(size):
	return [[[0,0,0] for _ in range(size)] for _ in range(size)]
	
# Name:  Mandelbrot Sequence
# In:  two complex numbers a + bi as a complex(a,b), z_n and c 
# Out:  a complex number a + bi as a complex(a,b)
# Description:  Calculate z_(n+1) = z_n^2 + c and return the result
# m_seq(complex(1,1),complex(0,0)) = 2j
def m_seq(z_n, c):
	return z_n * z_n + c
	
# Name:  complex_to_base
# In:  a complex value c, a size
# Out:  a tuple (first,second) that gives the coordinates of the base pixel corresponding to the value c
# Description:  Figure out which pixel corresponds to a complex value
# Assume the base runs from [-2,2] in both real and complex values and c is in this space
# Assume positive real is down, positive imaginary is right
# Example c2b(complex(1,1), 2) = (1,1)
# we make sure x and y are in the range 0, size-1
def c2b(c,size):
	x = int((c.real + 2) * size // 4)
	y = int((c.imag + 2) * size // 4)
	x, y = min(x, size - 1), min(y, size -1)
	x, y = max(x, 0), max(y, 0)
	return (x,y)

# reverse c2b
def b2c(x,y,size):
	return complex((x * 4.0 / size - 2.0), (y * 4.0 / size - 2.0))
	
# Name:  Escapes?
# In:  a complex value c, a number of iterations i
# Out:  a boolean
# Description:  Find out if complex value c "escapes" or has absolute value greater than 2 w/i iters iterations
# abs(z_n) > 2 means that the Mandelbrot sequence will not converge
# each iteration is one application of m_seq
# Example escapes(complex(1,1), 1000) = True 
def escapes(c, iters):
	z_n = c
	for _ in range(iters):
		z_n = m_seq(z_n, c)
		if abs(z_n) > 2:
			return True
	return False

# Name:  One Value
# In:  A base, a number of iterations, a color in [0,1,2], a complex value c
# Out:  Nothing, but base may be updated.
# Description:
# Take a value c.
# If it escapes within iters
# Go through the escaping sequence and increment
# the pixel value for each location passed through by the 
# sequence for the given color. 
def one_val(base, iters, color, c):
	size = len(base)
	z_n = c # we save the starting value
	if not escapes(c, iters):
		return
	for i in range(iters):
		if abs(z_n) > 2:
			return base
		(x,y) = c2b(z_n, size)
		x = min(x, size - 1) # prevent overflow
		y = min(y, size - 1) # prevent overflow
		v = base[x][y][color]
		v += 25
		if v > 255:
			v = 255
		base[x][y][color] = v
		z_n = m_seq(z_n, c)
	return
	
# Name:  One Value
# In:  A base, a number of iterations
# Out:  Base as updated
# Description (example infeasible, so detailed):
# Take a value.  Mirror the value across all axes.
# The value will be randomly generated
# For the value and it's mirrors, check to see if the value
# escapes for each of the number of iterations in iter
# If it does, go through the escaping sequence and increment
# the pixel value for each location passed through by the 
# sequence for the given color.  
def get_colors(base, iters):
	i_lst = [iters, iters * 10, iters * 100]  # different iterations for each color
	size = len(base)
	for x in range(size):
		for y in range(size):
			for i in range(3):
				one_val(base, i_lst[i], i, b2c(x,y,size))
	return


def normalize(base):
	pass

# Name:  Buddhabrot
# In:  size (square size of the output image in pixels) iters (a base number of iterations)
# In, cont.:  vals, a base number of times to call one_val
# Out: nothing
# Description using one_val, Buddhabrot creates a an image by calling one_val many times
# on a create_base(size).  Once one_val has been called many times (vals/iter1)
# the image is saved using Image.fromarray and .save to "buddhabrot.png"
# The different iterations for different color bands are given as
# iters = [iter1, iter1*2, iter1*4]
# example:  buddhabrot(4001,[50,100,200],5000000) made buddhabrot.png
def buddhabrot(size, iters):

	# Make a base
	base = create_base(size) # odd values are cleaner around the axes
	
	# We'll do some large number of values
	get_colors(base, iters)
	
	# We can normalize to make it look good
	normalize(base)

	# Convert the pixels into an array using numpy
	array = np.array(base, dtype=np.uint8)
	
	# Use PIL to create an image from the new array of pixels
	new_image = Image.fromarray(array)
	new_image.save('buddhabrot.png')
	
buddhabrot(400,20)
