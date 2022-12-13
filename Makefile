.DEFAULT_GOAL := all

#quando adicionar uma nova dependencia não esqueça de atualizar aqui!
OBJECTS=build/sistema.o build/executor.o build/automovel.o build/concessionaria.o build/veiculo.o build/caminhao.o build/moto.o

build/sistema.o: src/sistema.cpp include/sistema.h
	g++ -Iinclude src/sistema.cpp -c -o build/sistema.o

build/executor.o: src/executor.cpp include/executor.h 
	g++ -Iinclude src/executor.cpp -c -o build/executor.o

build/automovel.o: src/automovel.cpp include/automovel.h 
	g++ -Iinclude src/automovel.cpp -c -o build/automovel.o

build/concessionaria.o: src/concessionaria.cpp include/concessionaria.h 
	g++ -Iinclude src/concessionaria.cpp -c -o build/concessionaria.o

build/veiculo.o: src/veiculo.cpp include/veiculo.h 
	g++ -Iinclude src/veiculo.cpp -c -o build/veiculo.o

build/caminhao.o: src/caminhao.cpp include/caminhao.h 
	g++ -Iinclude src/caminhao.cpp -c -o build/caminhao.o

build/moto.o: src/moto.cpp include/moto.h 
	g++ -Iinclude src/moto.cpp -c -o build/moto.o

#para adicionar novas regras apenas siga o formato
#build/concessionaria.o: src/concessionaria.cpp include/concessionaria.h
#	g++ -Iinclude src/concessionaria.cpp -c

objects: $(OBJECTS)

programa: objects src/programa.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/programa.cpp -o build/programa

clean:
	rm build/*.o build/programa

all: programa

run:
	./build/programa

teste:
	./build/programa < ./tests/test1.txt