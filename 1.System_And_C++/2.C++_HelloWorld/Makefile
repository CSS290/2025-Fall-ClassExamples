All: HelloWorld.o run

HelloWorld.o: HelloWorld.cpp
	g++ -c HelloWorld.cpp

run: HelloWorld.o
	g++ -o HelloWorld HelloWorld.o
	./HelloWorld

clean:
	rm -f HelloWorld.o HelloWorld