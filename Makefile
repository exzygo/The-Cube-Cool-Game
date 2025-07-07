all:
	gcc main.c -o game -Iheaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run:
	gcc main.c -o game -Iheaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	./game
	rm -rf game

clean:
	rm -rf game
