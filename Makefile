

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = src/main.o src/network.o
TARGET = tcp_post_client

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)