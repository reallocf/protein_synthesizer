TARGET  = main
SRC     = main.c
HEADERS = amino.h
CC = gcc

.PHONY: clean, run, default

default: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) ./*.o
	$(RM) ./$(TARGET)
	$(RM) ./$(TARGET)-debug
	$(RM) -rf ./$(TARGET)-debug.dSYM

debug: $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -g $< -o $(TARGET)-debug

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $< -o $(TARGET)

