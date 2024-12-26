all: tic_tac_toe

tic_tac_toe: main.o ui.o game_end.o check_move.o
	gcc -o tic_tac_toe main.o ui.o game_end.o check_move.o

main.o: main.c
	gcc -c main.c -o main.o

ui.o: ui.c
	gcc -c ui.c -o ui.o

game_end.o: game_end.c
	gcc -c game_end.c -o game_end.o

check_move.o: check_move.c
	gcc -c check_move.c -o check_move.o

clean:
	rm -f *.o tic_tac_toe