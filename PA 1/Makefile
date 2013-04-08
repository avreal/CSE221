# makefile for Jars
# calling:
# "make" or "make jar_test"
# "make ll_jar_test"

VEC_SOURCE = marble.cpp vector_jar.cpp jar_test.cpp
VEC_OBJ = $(VEC_SOURCE:.cpp=.o)
VEC_TARGET = jar_test

LL_SOURCE = marble.cpp llist_jar.cpp ll_jar_test.cpp
LL_OBJ = $(LL_SOURCE:.cpp=.o)
LL_TARGET = ll_jar_test

.cpp.o:
	c++ -Wall -g -c $<

$(VEC_TARGET): $(VEC_OBJ)
	c++ -Wall -g $(VEC_OBJ) -o $@

$(LL_TARGET): $(LL_OBJ)
	c++ -Wall -g $(LL_OBJ) -o $@

clean:
	/bin/rm -f *.o $(VEC_TARGET) $(LL_TARGET)

 
