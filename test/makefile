CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?=  -w -I../src -I../include


EXEC     = test
#LDFLAGS ?= -L../../../../../pacs-examples/Examples/lib
#LIBS  ?= -lmuparser

all: $(EXEC)

%.o: %.cpp optimizer.hpp Utilities.hpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

$(EXEC): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< $(LIBS) -o $@

clean:
	$(RM) *.o
	$(RM) $(EXEC)
distclean: clean
	$(RM) *~
