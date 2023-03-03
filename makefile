stringMe: khanAyeshaA2.o khanAyeshaA2Main.o
	gcc -Wall -std=c99 khanAyeshaA2.o khanAyeshaA2Main.o -o bin/stringMe
khanAyeshaA2.o: src/khanAyeshaA2.c include/khanAyeshaA2.h
	gcc -Wall -std=c99 -c src/khanAyeshaA2.c
khanAyeshaA2Main.o: src/khanAyeshaA2Main.c include/khanAyeshaA2.h
	gcc -Wall -std=c99 -c src/khanAyeshaA2Main.c
clean:
	rm *.o bin/stringMe
