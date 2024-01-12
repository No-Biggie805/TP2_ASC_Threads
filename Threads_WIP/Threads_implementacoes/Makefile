CC = gcc
CFLAGS = -Wall -pthread

TARGET = exp

all: $(TARGET)

$(TARGET): th1.1_experimental.c Sensores.c global.c
	$(CC) $(CFLAGS) -o $(TARGET)  th1.1_experimental.c Sensores.c global.c

clean:
	rm -f $(TARGET)

.PHONY: all clean