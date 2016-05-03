
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/rendering

SRC= main.c init.c map.c quit.c lives.c logic.c events.c render.c gameWin.c gameOver.c collision.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   -lm -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c defs.h
init.o: init.c defs.h
map.o: init.c defs.h
quit.o: quit.c defs.h
lives.o: lives.c defs.h
logic.o: logic.c defs.h
events.o: events.c defs.h
render.o: render.c defs.h
gameWin.o: gameWin.c defs.h
gameOver.o: gameOver.c defs.h
collision.o: collision.o defs.h

