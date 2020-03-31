# Authors: Eslam HUMAID, Abrahim BAMATRAF.
# Groupe : 485L
# Git Repository  :  https://github.com/EslamHumaid/CNTP3.git

# Modèle de fichier Makefile, à adapter pour le TP
# Faire une copie de ce fichier, changer le nom pour "makefile" (sans extension .txt!!!) et l'adapter pour votre projet
# >cp makefile_model.txt makefile
# 
# Maintenant pour compiler il suffit d'écrire 
# >make


# options de compilation
CC = gcc
CCFLAGS = -Wall
LIBS = -lm	-lstdc++ 			# par exemple, -lm rajoute le libm standard
LIBSDIR = 

# fichiers du projet
SRC = main.cpp ticket.cpp storage.cpp
OBJ = $(SRC:.c=.o)
EXEC = run.out


# règle initiale
all: $(EXEC)

# dépendance des .h
ticket.o: ticket.hpp
storage.o: storage.hpp
storage.o: ticket.hpp
main.o: ticket.hpp 
main.o: storage.hpp
# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LIBSDIR)

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o