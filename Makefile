##### Source files and executable ############################################

SRCS            = piglatin.cpp

OBJECTS         = piglatin.o

EXECNAME        = piglatin

##### Libraries and paths ####################################################

LIBS            =
INCDIRS         =
LIBDIRS         =

##### Compiler information ###################################################

CPP             = g++
CPPFLAGS        =

##### Target compilation #####################################################

all: $(EXECNAME)

$(EXECNAME): $(OBJECTS)
        $(CPP) $(CPPFLAGS) $(LIBDIRS) $^ $(LIBS) -o $(EXECNAME)

.cpp.o:
        $(CPP) $(CPPFLAGS) $(INCDIRS) -c $<

.cc.o:
        $(CPP) $(CPPFLAGS) $(INCDIRS) -c $<

clean:
        rm -rf *~ *.o *.a $(EXECNAME)

##############################################################################
