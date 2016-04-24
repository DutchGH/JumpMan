
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/sdl

SRC= main.c events.c map.c render.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   -lSDL2 -lSDL2_image

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

main.o:  main.c structs.h events.h render.h map.h
events.o:  events.c structs.h events.h render.h 
map.o: map.c structs.h events.h render.h 
render.o:  render.c structs.h events.h render.h map.h

