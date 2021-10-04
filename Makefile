all: dequeaslistdriver.out


# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

dequeaslistdriver: dequeaslisttest.cpp Linked_List.cpp Node.cpp Website.cpp Deque.cpp
	g++ -std=c++11 -o dequeaslistdriver dequeaslisttest.cpp Linked_List.cpp Node.cpp Website.cpp Deque.cpp

# List all the executables under 'all:'
clean:
	rm *.o dequeaslistdriver