CXX = g++
RM = rm -f
CPPFLAGS = -g -Wall
LDLIBS=

SRCS = main.cpp rock.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

all: tp02

tp02: $(OBJS)
	$(CXX) $(CPPFLAGS) -o tp02 $(OBJS) $(LDLIBS)

depend: .depend
.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	@$(RM) *~ .depend tp02 *.o

include .depend