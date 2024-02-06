CC = gcc
FLAGS = -Wall -g
DEPS = my_mat.h
GRAPH_OBJ = my_graph.o my_mat.o


all : my_graph my_Knapsack
my_graph : $(GRAPH_OBJ)
	$(CC) $(FLAGS) -o $@ $^
my_Knapsack : my_Knapsack.o
	$(CC) $(FLAGS) -o $@ $^

my_graph.o : my_graph.c $(DEPS)
	$(CC) $(FLAGS) -c -o $@ $<
my_mat.o : my_mat.c $(DEPS)
	$(CC) $(FLAGS) -c  -o $@ $<
my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c  -o $@ $<

.PHONY : clean all

clean :
	rm -f *.o my_graph my_Knapsack