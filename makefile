CC = g++

all:DisjointSetTest

DisjointSetTest:Test_Disjoint_Set.cpp Union_Find.cpp Union_Find.h
	$(CC) Test_Disjoint_Set.cpp Union_Find.cpp -o DisjointSetTest

clean:
	rm DisjointSetTest

