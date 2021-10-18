filter:
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm -o filter filter.c helpers.c

CMD:
	./filter -<first letter of filter> input.bmp output.bmp

	avaliable filters
	1) -g greyscale {black and white image}
	2) -r reflect {flip the image}
	3) -e edges {highlights the edges}
	4) -b blur {blur the whole image}
	5) -s sepia {convert image into old school image}
