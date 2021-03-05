sample_executable: sample.o temperature.o
	g++ -g -o sample sample.o temperature.o
	chmod 755 sample

temperature.o: temperature.cpp temperature.h
	g++ -g -c temperature.cpp 

sample.o: sample.cpp temperature.h
	g++ -g -c sample.cpp    

clean:
	rm -f *.o


