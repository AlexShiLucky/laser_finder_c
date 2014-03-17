TARGET		= laser_finder_c
OBJECTS 	= laser_finder_c.o dots_img.o no_dots_img.o point.o memory.o 
#######################################################################################
CFLAGS   = -g -Wall
ASFLAGS  = -Wall
LDFLAGS  = -g -Wall

CC = gcc
AS = gcc
LD = gcc

########################################################################################
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

point.o: point.h memory.h
memory.o: memory.h
laser_finder_c.o: point.h
dots_img.o: memory.h
no_dots_img.o: memory.h

clean: 
	rm -f $(OBJECTS) $(TARGET)