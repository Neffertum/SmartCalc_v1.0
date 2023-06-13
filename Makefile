CC = gcc -Wall -Werror -Wextra -std=c11
FILES_C = polish.c polish.h stack.c stack.h support.c
FILES_CPP = ./QtCalc/mainwindow.cpp ./QtCalc/mainwindow.h ./QtCalc/mainwindow.ui ./QtCalc/qcustomplot.cpp ./QtCalc/qcustomplot.h
BUILD_FOLDER = build
P_NAME = QtCalc
T_NAME = $(P_NAME)-build-realese-v1.tar.gz
TEST_SOURSE = ./test/polish.o ./test/support.o ./test/stack.o
TEST_FLAGS = -lcheck -lm -lpthread -lsubunit -lrt -fprofile-arcs $(shell pkg-config --cflags --libs check)

all: clean gcov_report install dvi dist
.PHONY : all

install: uninstall ./QtCalc/main.cpp $(FILES_C) $(FILES_CPP)
		if [ ! -f "build/$(P_NAME)" ]; then \
				cd QtCalc/ && qmake QtCalc.pro && make; \
				if ! [ -d "./../build" ]; then \
						mkdir ./../build; \
				fi; \
				cp $(P_NAME) ./../build/; \
		fi
.PHONY : install

run:
		./build/$(P_NAME)
.PHONY : run

dvi:
		cd doxygen && doxygen Doxyfile
		xdg-open doxygen/html/index.html 2> /dev/null
.PHONY : dvi

dist:
		rm -rf $(BUILD_FOLDER)/$(T_NAME)
		touch $(BUILD_FOLDER)/$(T_NAME)
		tar --exclude=$(BUILD_FOLDER)/$(T_NAME) -zcvf $(BUILD_FOLDER)/$(T_NAME) $(BUILD_FOLDER)

.PHONY : dist

test: clean_files
		@mkdir ./test
		@$(CC) -c --coverage polish.c -o ./test/polish.o
		@$(CC) -c --coverage stack.c -o ./test/stack.o
		@$(CC) -c --coverage support.c -o ./test/support.o
		@$(CC) test.c $(TEST_SOURSE) $(TEST_FLAGS) -o ./test/my_test
		@./test/my_test
		@mv test.gcda ./test/
.PHONY : test

gcov_report: test ./test/my_test
		@gcov -b -l -p -c ./test/*.gcno
		@gcovr -g -k -r . --html --html-details -o ./test/report.html
		@mv *.gcov ./test
		@xdg-open ./test/report.html 2> /dev/null
.PHONY : gcov_report

style:
		clang-format -style=google -n *.c* *.h* QtCalc/*.c* QtCalc/*.h*
.PHONY : style

rebuild: uninstall install
.PHONY : rebuild

clean: uninstall clean_files
.PHONY : clean

clean_files:
		rm -rf *.o
		rm -rf ./doxygen/html
		rm -rf ./test
		rm -rf *.gcno *.gcda
		rm -rf my_test
		rm -rf *.gcov
.PHONY : clean_files
		

uninstall:
		rm -rf build/$(T_NAME)
		rm -rf build/$(P_NAME)
		rm -rf ./QtCalc/$(P_NAME)
		rm -rf $(BUILD_FOLDER)
		rm -rf ./QtCalc/QtCalc.pro.user
		rm -rf ./QtCalc/.qmake.stash
		rm -rf ./QtCalc/*.o
		rm -rf ./QtCalc/.qmake.stash
		rm -rf ./QtCalc/Makefile
		rm -rf ./QtCalc/moc_*
		rm -rf ./QtCalc/ui_mainwindow.h
		rm -rf *.gz
.PHONY : uninstall


my:
		rm -rf my.o
		$(CC) my_test.c $(FILES_C) -lm -o my.o
		./my.o
.PHONY : my
