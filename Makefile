SRC        = $(wildcard src/*.c)
HEADER     = $(wildcard src/*.h)
OBJ        = $(wildcard *.o)
OUT        = sscm
RAYLIB_PATH= ./deps/raylib/src
CFLAGS     = -Wall -Wextra -ggdb
LDFLAGS    = -L$(RAYLIB_PATH) -I$(RAYLIB_PATH) \
	     -lm -lraylib -lX11
all: build

build: $(OBJ) $(HEDAER) $(RAYLIB_PATH)/libraylib.a
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(OUT)

$(RAYLIB_PATH)/libraylib.a:
	$(MAKE) -C $(RAYLIB_PATH)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRC)
