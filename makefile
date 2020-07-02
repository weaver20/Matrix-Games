C = g++
EXEA = partAexe
EXEB = partBexe
EXEC = partCexe
COMP_FLAG = -std=c++11 -Wall -pedantic-errors -Werror -g
DEBUG_FLAG = -DNDEBUG
AUX_FLAG = ~mtm/public/1920b/ex3/Auxiliaries.cpp
EX3_FLAG = -I ~mtm/public/1920b/ex3/

$(EXEA):
	$(CC) $(COMP_FLAG) $(DEBUG_FLAG) PartA/*.cpp $(AUX_FLAG) -IPartA $(EX3_FLAG)  -o $(EXEA)

$(EXEB):
	$(CC) $(COMP_FLAG) $(DEBUG_FLAG) $(AUX_FLAG) -IPartB $(EX3_FLAG) PartB/*.cpp -o $(EXEB)

$(EXEC):
	$(CC) $(COMP_FLAG) $(DEBUG_FLAG) -IPartC $(EX3_FLAG) PartC/*.cpp -o $(EXEC)


candra:
	make clean
	make $(EXEA)
	valgrind --leak-check=full ./partAexe

candrb:
	make clean
	make $(EXEB)
	valgrind --leak-check=full ./partBexe

candrc:
	make clean
	make $(EXEC)
	valgrind --leak-check=full ./partCexe

clean:
	rm -f $(EXEA) $(EXEB) $(EXEC)
