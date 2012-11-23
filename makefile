OBJECTS=user_interface.o tvguide.o linked_list.o comparison.o file_io.o
OUTPUT=tvguide

$(OUTPUT): $(OBJECTS)
	gcc -g -o $(OUTPUT) $(OBJECTS)

%.o: %.c
	gcc -g -c  -o $@ $<
