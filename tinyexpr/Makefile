CCFLAGS = -ansi -Wall -Wshadow -O2
LFLAGS = -lm


all: example2








example2: example2.o tinyexpr.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LFLAGS)



.c.o:
	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm example2
