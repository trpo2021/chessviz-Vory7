

all: bin/chess

bin/chess: obj/chess.o obj/lib/chesslib.a
	g++ obj/chess.o -Wall -Werror -L. obj/lib/chesslib.a -o $@

obj/chess.o:src/chessviz/chess.cpp obj/lib/chesslib.a
	g++ -c src/chessviz/chess.cpp -include src/lib/bibl.h -I src/lib -Wall -Werror -o obj/chess.o

obj/src/bibl.o:src/lib/bibl.cpp
	g++ -c src/lib/bibl.cpp -Wall -Werror -o $@

obj/lib/chesslib.a:obj/src/bibl.o
	ar rcs $@ $^

run:
	./bin/chess

clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "chess" -exec rm -f '{}' \;
	find ./bin -type f -name "test" -exec rm -f '{}' \;
.PHONY: clean run all
