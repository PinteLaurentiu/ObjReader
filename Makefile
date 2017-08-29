CPPFLAGS = -Wall -g -std=c++11

INCLUDES =

LFLAGS =

LIBS = #-lpng16 -lz

ODIR = bin/

MAKEDIR = mkdir -p

SRCS = main.cpp vector.cpp file_data.cpp model.cpp obj_parser.cpp

OBJS = $(join $(addsuffix $(ODIR), $(dir $(SRCS))), $(notdir $(SRCS:.cpp=.o)))

MAIN = $(ODIR)app

ARGS =

.PHONY: all preclean postclean run

all: preclean $(MAIN) postclean #run

$(MAIN): $(ODIR) $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

$(ODIR)%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $<  -o $@

$(ODIR):
	$(MAKEDIR) $(ODIR)

preclean:
	$(RM) $(ODIR)*.o

postclean:
	$(RM) $(ODIR)*.o

run:
	@./$(MAIN) $(ARGS)
