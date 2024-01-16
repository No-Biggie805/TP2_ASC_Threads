CC = gcc
CFLAGS = -Wall -pthread

TARGET = exp

all: $(TARGET)

$(TARGET): main.c Sensores.c global.c SensoresLux.c
	$(CC) $(CFLAGS) -o $(TARGET)  main.c Sensores.c global.c SensoresLux.c

clean:
	rm -f $(TARGET)

.PHONY: all clean