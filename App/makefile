LIBRARIES = -framework Cocoa -framework Quartz -framework OpenGL -lcocoawindowing_s -lpng
LIBDIR = -L ./bin
INCLUDEDIR = -I ./include

EXE = FlappyCorn

FlappyCorn: Background.o Barriers.o Flappy.o Menu.o Menu2.o main2.o olcFlappy.o
	clang++ -arch x86_64 -std=c++14 -Wall $(LIBRARIES) $(LIBDIR) $(INCLUDEDIR) Background.o Barriers.o Flappy.o Menu.o Menu2.o olcFlappy.o -o $(EXE)

Background.o: Background.cpp
	 clang++ -arch x86_64 -std=c++14 -Wall $(LIBRARIES) $(LIBDIR) $(INCLUDEDIR) Background.cpp

Barriers.o: Barriers.cpp
	clang++ -arch x86_64 -std=c++14 -Wall $(LIBRARIES) $(LIBDIR) $(INCLUDEDIR) Barriers.cpp

Flappy.o: Flappy.cpp
	clang++ -arch x86_64 -std=c++14 -Wall $(LIBRARIES) $(LIBDIR) $(INCLUDEDIR) Flappy.cpp

Menu2.o: Menu2.cpp
	clang++ -arch x86_64 -std=c++14 -Wall $(LIBRARIES) $(LIBDIR) $(INCLUDEDIR) Menu2.cpp

olcFlappy.o: olcFlappy.cpp
	clang++ -arch x86_64 -std=c++14 -Wall $(LIBRARIES) $(LIBDIR) $(INCLUDEDIR) Barriers.cpp

clean:
	-rm $(EXE) *.o
	
