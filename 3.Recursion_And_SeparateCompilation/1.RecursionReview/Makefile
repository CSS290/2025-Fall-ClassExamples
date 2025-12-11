# DEBUG = "-DDEBUG"   # comment or uncomment:  for making debug version

all: clean ReverseDigits AttachLeft

debug:
	make clean
	make DEBUG="-DDEBUG"

ReverseDigits: ReverseDigits.o
	g++ -o $@ $^

AttachLeft: AttachLeft.o
	g++ -o $@ $^

%.o: %.cpp
	g++ -c $(DEBUG) $< -o $@

clean:
	rm -rf *.o ReverseDigits AttachLeft
