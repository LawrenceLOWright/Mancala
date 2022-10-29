#Makes and cleans targets for Mancala                                           

TARGETS = prototype

all: $(TARGETS)

prototype: prototype.cc
        g++ -o prototype prototype.cc

clean:
        rm -f $(TARGETS)
