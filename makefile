# authors: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
# date: 06/04/2020
# git: https://github.com/EslamHumaid/ASD2PROJ



# options de compilation
CC = gcc
CCFLAGS = -Wall
LIBS = -lm	-lstdc++ 			
LIBSDIR = 

# fichiers du projet
SRC = main.cpp ticket.cpp storage.cpp vstorage.cpp backbag.cpp
OBJ = $(SRC:.c=.o)
EXEC = run.out


# règle initiale
all: $(EXEC)

# dépendance des .h
ticket.o: ticket.hpp
storage.o: storage.hpp
storage.o: ticket.hpp
bagage.o: bagage.hpp
bagback.o : bagback.hpp
vstorage.o: vstorage.hpp
vstorage.o: ticket.hpp
vstorage.o: bagage.hpp
main.o: ticket.hpp 
main.o: storage.hpp
main.o: bagage.hpp
main.o: vstorage.hpp

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