CC      = gcc
CFLAGS  = -Wall -Wextra -O2
TARGET  = bin/photon
SRC     = src/photon.c

all: $(TARGET)

$(TARGET): $(SRC) | bin
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

bin:
	@mkdir -p bin

run: $(TARGET)
	./$(TARGET)

install: $(TARGET)
	install -Dm755 $(TARGET) /usr/local/bin/photon

uninstall:
	rm -f /usr/local/bin/photon

clean:
	rm -rf bin

.PHONY: all run install uninstall clean