CPP = g++
SFML = -g -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp


main: Carte.o CarteVictoire.o CarteRoyaume.o CarteTresor.o Joueur.o PlateformeGame.o main.o
	$(CPP) -o $@ $^ $(SFML)

%.o : %.cpp
	$(CPP) -o $@ -c $<

clean:
	rm -f *.o *~ *.core