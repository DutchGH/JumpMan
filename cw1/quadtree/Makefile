
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/quad

SRC= quadtreeMain.c quadtreeFunctions.c QTLinkedListFunctions.c valueTree.c

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

quadtreeMain.o:	quadtreeMain.c quadtree.h QTLinkedList.h valueTree.h
quadtreeFunctions.o: quadtreeFunctions.c quadtree.h
QTLinkedListFunctions.o: QTLinkedListFunctions.c quadtree.h QTLinkedList.h
valueTree.o: valueTree.c quadtree.h QTLinkedList.h valueTree.h


