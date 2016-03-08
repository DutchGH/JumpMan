
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/quad

SRC= quadtreeMain.c quadtreeFunctions.c 
# generic build details

CC=      cc
COPT=    -O
CFLAGS= -lm -std=gnu99

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

quadtreeMain.o:	quadtreeMain.c quadtree.h 
quadtreeFunctions.o: quadtreeFunctions.c quadtree.h



