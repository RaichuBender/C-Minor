EXE		:= main
OBJECTS	:= obj/main.o obj/hello.o obj/goodbye.o obj/message.o

INCLUDE	:= include
CFLAGS	:= -O0 -g
#CFLAGS	:= -O2 -s -static

default:	clean
	$(MAKE) $(EXE)
	clear
	./$(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS)   $^ -o $@

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I$(INCLUDE)
obj/hello.o: src/hello.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I$(INCLUDE)
obj/goodbye.o: src/goodbye.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I$(INCLUDE)
obj/message.o: src/message.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I$(INCLUDE)

.PHONY:	clean
clean:
	-rm -vf $(EXE) $(OBJECTS)
