###############################################################################
#  MakeFile del compilador Menos C                                            #
#  Autores:                                                                   #
#        Pau Baquero Arnal       pabaar@inf.upv.es                            #
#        Axel Guzmán Godia       axguzgo@inf.upv.es                           #
#        Carlos Millán Soler     carmilso@inf.upv.es                          #
###############################################################################

CC_OPTIONS = -pedantic
CC_LIBRARY = -lfl -ltds -lgci
CC_LINKS_FLAGS = $(CC_LIBRARY) $(CC_OPTIONS)
OBJECTS = ./alex.o  ./asin.o ./principal.o

cmc:	$(OBJECTS)
	gcc -o cmc $(OBJECTS) -L./lib -I./include $(CC_LINKS_FLAGS)
principal.o: ./src/principal.c
	gcc -c ./src/principal.c -I./include $(CC_OPTIONS)
asin.o:	asin.c
	gcc -c asin.c -I./include $(CC_OPTIONS)
alex.o:	alex.c asin.c
	gcc -c alex.c -I./include $(CC_OPTIONS)
asin.c:	./src/asin.y
	bison -oasin.c -d src/asin.y
	mv asin.h ./include
alex.c:	./src/alex.l
	flex -oalex.c src/alex.l

clean:
	rm -f alex.c asin.c ./include/asin.h asin-yac.output
	rm -f ./*.o *.?~ ./include/*.?~ ./src/*.?~
###############################################################################
