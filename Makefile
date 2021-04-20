all:
	gcc -o quick-sort quick-sort.c
	gcc -o quick-find quick-find.c
clean:
	rm quick-sort quick-find
