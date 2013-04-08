# makefile
# calling:
# "make VPQueue" or "make HPQueue"

VEC_SOURCE = VMain.cpp 
VEC_OBJ = $(VEC_SOURCE:.cpp=.o)
VEC_TARGET = VPQueue 

H_SOURCE = HMain.cpp 
H_OBJ = $(H_SOURCE:.cpp=.o)
H_TARGET = HPQueue

.cpp.o:
	c++ -Wall -g -c $<

$(VEC_TARGET): $(VEC_OBJ)
	c++ -Wall -g $(VEC_OBJ) -o $@

$(H_TARGET): $(H_OBJ)
	c++ -Wall -g $(H_OBJ) -o $@

clean:
	/bin/rm -f *.o $(VEC_TARGET) $(H_TARGET)

