CXX=g++
CXXFLAGS=-Wall -Wextra -Werror

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

exo8: exo8.o Date.o Personne.o Etudiant.o
	$(CXX) $^ -o $@

.PHONY: run clean

run: exo8 
	./$<

clean:
	rm -f *.o *~ *.core 
