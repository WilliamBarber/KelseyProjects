all: quiz.out

quiz.out: quiz.c
	gcc -g -Wall -Werror -Wextra -o quiz.out quiz.c

clean:
	rm -rf *.o *.out

optimized:
	gcc -O2 -Wno-unused-result -o quiz.out quiz.c
