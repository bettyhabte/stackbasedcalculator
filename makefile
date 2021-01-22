stackbasedcalculator: infixtopostfix.o calculate.o main.o
	g++ main.o infixtopostfix.o calculate.o -o stackbasedcalculator
infixtopostfix.o: infixtopostfix.cpp infixtopostfix.h
	g++ -c infixtopostfix.cpp
calculate.0: calculate.cpp calculate.h
	g++ -c calculate.cpp
main.o: main.cpp calculate.h infixtopostfix.h
	g++ -c main.cpp
clean:
	rm *.o
	rm stackbasedcalculator
run: stackbasedcalculator
	./stackbasedcalculator