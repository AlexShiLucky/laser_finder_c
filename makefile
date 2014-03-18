TARGET		= laser_finder_c
OBJECTS 	= laser_finder_c.o dots_test2.o nodots_test2.o point.o memory.o 
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
dots_test2.o: memory.h
nodots_test2.o: memory.h

clean: 
	rm -f $(OBJECTS) $(TARGET)