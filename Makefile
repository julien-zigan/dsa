CC = gcc
TEST_F = dijkstra_test.c
OBJ = jz_unit.o dijkstra.o
TEST = -o running_tests

run_tests: test
	./running_tests	
	
test: $(TEST_F) $(OBJ)
	$(CC) $(TEST) $(TEST_F) $(OBJ)   

dijkstra_test.o: dijkstra.h jz_unit.h jz_unit.o dijkstra_test.c 
	$(CC) -c dijkstra_test.c jz_unit_o

jz_unit.o: jz_unit.h jz_unit.c 
	$(CC) -c jz_unit.c

dijkstra.o: dijkstra.h dijkstra.c 
	$(CC) -c dijkstra.c

cleanup: 
	rm running_tests *.o
