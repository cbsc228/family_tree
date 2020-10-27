HEADERS = personNode.h familyNode.h 
OBJECTS = Project4.o personNode.o familyNode.o
EXEC = project4


#build executable program
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
#build objective files from source files
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
#clean up the mess
clean:
	rm -i `find ./ -type f -executable`
	rm -i *.o
#run the executable	
run: $(EXEC)
	./$(EXEC)

