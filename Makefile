#Group Members: Nan Liu  liunan; Angela Sun sunangel
CPPFLAGS = -Wall -g -MMD
LDFLAGS = -g
CXX = g++

OBJS = main.o BubbleSort.o factory.o student.o employee.o
SOURCES = main.cpp BubbleSort.cpp factory.cpp student.cpp employee.cpp


all: test

test: $(OBJS)
	$(CXX) -o $@ $^

-include $(subst .cpp,.d,$(SOURCES))

%.d:%.cpp
	$(CXX) -M $(CPPFLAGS) -MF $@ $< -MT "$*.o $@"

clean:
	rm -f test $(OBJS) *.d*
