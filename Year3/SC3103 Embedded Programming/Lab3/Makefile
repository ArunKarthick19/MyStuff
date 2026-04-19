# Compiler
CC = gcc

# Compiler flags (debugging + profiling + warnings)
CFLAGS = -Wall -g -pg

# Object files
OBJS = mathlib.o

# Default targets
all: printFactorial printMultiplyBy100

# Build printFactorial target
printFactorial: printFactorial.o $(OBJS)
	$(CC) $(CFLAGS) printFactorial.o $(OBJS) -o printFactorial

# Build printMultiplyBy100 target
printMultiplyBy100: printMultiplyBy100.o $(OBJS)
	$(CC) $(CFLAGS) printMultiplyBy100.o $(OBJS) -o printMultiplyBy100

# Compile .c to .o and the -c flag tells the compiler to generate object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< 
#the $< is an automatic variable that represents the first prerequisite (the .c file in this case)?????

# Clean target
clean:
	rm -f *.o printFactorial printMultiplyBy100 gmon.out