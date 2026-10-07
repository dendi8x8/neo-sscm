SRC        = $(wildcard src/*.c)
HEADER     = $(wildcard src/*.h)
OBJ        = $(notdir $(SRC:.c=.o))
OUT        = sscm
RAYLIB_PATH= ./deps/raylib/src
CFLAGS     = -Wall -Wextra -ggdb -fsanitize=address -fsanitize-address-use-after-scope
LDFLAGS    = -L$(RAYLIB_PATH) -I$(RAYLIB_PATH) \
	     -lm -lraylib -lX11

.PHONY: all clean

all: build

build: $(OBJ) $(HEDAER) $(RAYLIB_PATH)/libraylib.a
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(OUT)

$(OBJ): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRC)

$(RAYLIB_PATH)/libraylib.a:
	$(MAKE) -C $(RAYLIB_PATH)

clean:
	@rm -f *.o
	@rm -f $(OUT)
