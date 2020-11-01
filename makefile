ED: main.o Editor.o ‫‪Document‬‬.o
	clang++-9  main.o Editor.o ‫‪Document‬‬.o -o ex

Editor.o: Editor.cpp Editor.hpp
	clang++-9 -c Editor.cpp

‫‪Document‬‬.o: ‫‪Document‬‬.cpp ‫‪Document‬‬.hpp
	clang++-9 -c ‫‪Document‬‬.cpp

main.o: main.cpp Editor.hpp
	clang++-9 -c main.cpp

clean:
	rm *.o ED

