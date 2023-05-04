CC = gcc
CFLAGS =  -W -Wall
TARGET = ledcal
OBJECTS = LedgerMain.c LedgerFunc.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean : 
	rm *.o ledcal
