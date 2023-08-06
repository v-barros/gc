SrcFiles=$(wildcard *.c)                                                                                                       
ObjFiles=$(patsubst %.c,%.o,$(SrcFiles))

gc:$(ObjFiles)
	gcc -O0 -o gc $(ObjFiles) -pg

%.o:%.c
	gcc -O0 -c $< -o $@ -pg 

.PHONY:clean all
clean:
	-rm -rf $(ObjFiles)