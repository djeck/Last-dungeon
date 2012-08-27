CXX = g++
CXXFLAGS = -Wall -pedantic -g -O0
EXE = exe

all: $(EXE)

%.o: src/%.cpp includes/%.h
	$(CXX) -c $(CXXFLAGS) $<
$(EXE): Test.o Equipe.o Joueur.o Go.o Plateau.o Groupe.o
	$(CXX)  $(LDFLAGS)      $+ -o $@


Test.o : Equipe.o Go.o

Equipe.o : Joueur.o

Joueur.o : 

Go.o : Equipe.o Plateau.o

Plateau.o : Groupe.o

Groupe.o : Joueur.o

clean:
	rm -f *.o $(EXE)
