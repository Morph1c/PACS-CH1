all:
	g++ -c optimizer.cpp -fPIC
	g++ -shared optimizer.o -o liboptimizer.so
	g++ test.cpp -o test -Wl,-rpath = /home/andrea/PACS/pacs-ch1/PACS-CH1/src/liboptimizer.so

clean:
	rm optimizer.o liboptimizer.so 
