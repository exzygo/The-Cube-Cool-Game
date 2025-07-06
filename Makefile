all:
	gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 

run:
	gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
	./game

clean:
	rm -rf game
