CC = gcc
FLAGS = -Wall -g
DEPS = my_mat.h
OBJ = main.o my_mat.o

main : $(OBJ)
	$(CC) $(FLAGS) -o $@ $^
%.o : %.c $(DEPS)
	$(CC) $(FLAGS) -c -o $@ $<

.PHONY : clean

clean :
	rm -f *.o my_mat main