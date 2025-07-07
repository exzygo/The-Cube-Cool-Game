all:
	# COMMAND WITHOUT GAME HEADERS
	#  gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
	gcc main.c -o game -Iheaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run:
	# COMMAND WITHOUT GAME HEADERS
	# gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
	gcc main.c -o game -Iheaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	./game
	rm -rf game

clean:
	rm -rf game
