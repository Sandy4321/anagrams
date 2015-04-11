all: anagrams.bin

anagrams.bin: anagrams.cpp
	g++ -std=c++11 -O2 anagrams.cpp -o $@

clean:
	rm anagrams.bin
