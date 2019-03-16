# Ensure that these targest always run
.PHONY: test clean

# DO NOT CHANGE THESE FLAGS
CC=gcc
CFLAGS= -g -Wall -Wextra -pedantic -Werror

#TODO add your netid here
NETID= 

OBJS=stack.o

all: stack.o

# If you name your .c file something other than kiosk.c, change it here
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c


stack: $(OBJS)
	$(CC) $(CFLAGS) -I./ main.c -o runstack.out $(OBJS)
	@echo "Running Stack File I/O"
	./runstack.out

test: $(OBJS)
	@echo "Building Instructor Tests"
	$(CC) $(CFLAGS) -I./ test-stack.c -o test-stack.out $(OBJS)
	@echo "Running Instructor Tests"
	./test-stack.out
	echo ""
	
	#TODO: If you have opted to write your own test, comment out
	#      the below lines
	#
	#@echo "Building User Tests"
	#$(CC) $(CFLAGS) -I./ test-stack-$(NETID).c -o test-stack-$(NETID).out $(OBJS)
	#@echo "Running User Tests"
	#./test-stack-$(NETID).out
	
	@echo "Done"

clean:
	# delete all compiled files
	rm -f stack.o
	rm -f test-stack.out
	rm -f test-stack-$(NETID).out
