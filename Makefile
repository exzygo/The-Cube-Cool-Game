all:
	gcc -O3 main.c asm_f/ams_obj_f/*.o -o game -Iheaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

asm_files:
	rm -rf asm_f/asm_obj_f/*.o
	rm -rf asm_f/asm_obj_f/*.obj
	gcc asm_f/detec.c asm_f/exect.c -o asm_f/f 
	cd asm_f && ./f
	rm -rf asm_f/f

asm_arm64:
	rm -rf asm_f/asm_obj_f/*.o
	rm -rf asm_f/asm_obj_f/*.obj
	cd asm_f/
	gcc detec.c exect.c -o f 
	./f
	rm -rf asm_f/f

run:
	gcc -O3 main.c asm_f/asm_obj_f/*.o -o game -Iheaders -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	./game
	rm -rf game

clean:
	rm -rf game
