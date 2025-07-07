all:
	gcc main.c -o game -Iheaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

asm_files:
	rm -rf asm_f/asm_obj_f/*.o
	rm -rf asm_f/asm_obj_f/*.obj
	gcc asm_f/detec.c asm_f/exect.c -o asm_f/f 
	cd asm_f && ./f
	rm -rf asm_f/f

run:
	gcc main.c -o game -Iheaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	./game
	rm -rf game

clean:
	rm -rf game
