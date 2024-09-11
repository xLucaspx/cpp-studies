# CXXFLAGS -> flags de compilação
# agora é possível chamar apenas "make + filename" e.g.: "make hangman"
# com a diretiva "-std=c++11" equivale ao comando "g++ -std=c++11 forca.cpp -o forca"
EXE=Hangman
OBJECTS=main.cpp app.cpp file.cpp hangman.cpp out.cpp
CC=g++
#CXXFLAGS=
FLAGS= -std=c++23

$(EXE): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(EXE)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
