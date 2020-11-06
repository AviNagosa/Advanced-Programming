ED: main.o Editor.o ‫‪Document‬‬.o
	clang++-9  main.o Editor.o ‫‪Document‬‬.o -o ed

Editor.o: Editor.cpp Editor.h
	clang++-9 -c Editor.cpp

‫‪Document‬‬.o: ‫‪Document‬‬.cpp ‫‪Document‬‬.h
	clang++-9 -c ‫‪Document‬‬.cpp

main.o: main.cpp Editor.h
	clang++-9 -c main.cpp

clean:
	rm *.o ed

