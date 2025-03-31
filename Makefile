CC = gcc
TEST_F = dijkstra_test.c 
TEST = -o running_tests

run_tests: test
	./running_tests	
	rm running_tests
	
test: $(TEST_F)
	$(CC) $(TEST) $(TEST_F)  
