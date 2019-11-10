##
## EPITECH PROJECT, 2019
## COMPILATION
## File description:
## Makefile
##

NAMELIB		= libmy.a
DIRLIB		=./lib/
DIRLIBMY		=./lib/my/
DIRTEST		=./tests/*.c
DIRMAIN		=./main_dos/*.c
COMPIL		= gcc *.c -L $(DIRLIB) $(DIRMAIN) -lmy -o $(EXEC)
COMPIL_TEST		= gcc *.c -g3 -L $(DIRLIB) $(DIRTEST) --coverage -lcriterion -lmy -o $(EXEC_TEST)
EXEC		= bsq
EXEC_TEST		= tests_bsq
RUN_TESTS	=	./$(EXEC_TEST)

COVERAGE	=	gcovr --exclude tests/
COVERAGE_BRANCH		=	gcovr --exclude tests/ -b

all	: make compilation compilation_test tests clean test_clean

make:
		cd $(DIRLIBMY) && make

compilation:
		$(COMPIL)

compilation_test:
		$(COMPIL_TEST)

run_test:
		$(RUN_TESTS)
		$(COVERAGE)
		$(COVERAGE_BRANCH)

tests:
		$(COVERAGE)
		$(COVERAGE_BRANCH)

clean:
		rm -f *.o

test_clean:
		rm -f *.gcda rm -f *.gcno

fclean: clean test_clean
		rm -f $(EXEC) $(EXEC_TEST) $(DIRLIB)$(NAMELIB)

re: fclean all

tests_run: make compilation compilation_test run_test clean test_clean