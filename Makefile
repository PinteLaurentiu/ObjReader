CPPFLAGS = -Wall -g -std=c++11

INCLUDES =

LFLAGS =

LIBS = #-lpng16 -lz

ODIR = bin/

MAKEDIR = mkdir -p

SRCS = main.cpp #file_data.cpp bitmap.cpp png_hidder.cpp

OBJS = $(join $(addsuffix $(ODIR), $(dir $(SRCS))), $(notdir $(SRCS:.cpp=.o)))

MAIN = $(ODIR)app

ARGS =

.PHONY: all clean run

all: $(MAIN) clean #run

$(MAIN): $(ODIR) $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

$(ODIR)%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $<  -o $@

$(ODIR):
	$(MAKEDIR) $(ODIR)

clean:
	$(RM) $(ODIR)*.o

run:
	@./$(MAIN) $(ARGS)
