#The compiler
CC:=gcc
#The flags
CFLAGS:=-Wall -Wextra -std=gnu11 -g -fsanitize=address -fsanitize=leak -O3
LDFLAGS:=-lSDL2

rebuild: demo_player

demo_player: main.o player.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

player.o: ../player/player.c ../inc/player.h
	$(CC) -c $< $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o demo_player