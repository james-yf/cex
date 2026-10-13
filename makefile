CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

TARGET = cex

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(TARGET) $(OBJS)
