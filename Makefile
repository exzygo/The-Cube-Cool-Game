all:
	gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 

clean:
	rm -rf game
