CC = gcc
CFLAGS = -Wall -Wextra -g -fPIC -I./lib

OBJS = lib/add.o lib/subtract.o lib/multiply.o lib/divide.o

all: calc_static calc_shared calc_dynamic

lib/%.o: lib/%.c lib/calc.h
	$(CC) $(CFLAGS) -c $< -o $@

lib/libcalc.a: $(OBJS)
	ar rcs $@ $^

lib/libcalc.so: $(OBJS)
	$(CC) -shared -o $@ $^

calc_static: main.c lib/libcalc.a
	$(CC) $(CFLAGS) main.c ./lib/libcalc.a -o $@

calc_shared: main.c lib/libcalc.so
	$(CC) $(CFLAGS) main.c -L./lib -lcalc -Wl,-rpath,'$$ORIGIN/lib' -o $@

calc_dynamic: dynamic_main.c lib/libcalc.so
	$(CC) $(CFLAGS) dynamic_main.c -ldl -o $@

test: all
	./calc_static
	./calc_shared
	./calc_dynamic

clean:
	rm -f $(OBJS) lib/libcalc.a lib/libcalc.so calc_static calc_shared calc_dynamic

.PHONY: all test clean
