CC = gcc
CFLAGS = -std=c11

q1: Question1/student.c Question1/tests.c
	$(CC) $(CFLAGS) Question1/student.c Question1/tests.c -o q1

run1: q1
	./q1

q2: Question2/student.c Question2/tests.c
	$(CC) $(CFLAGS) Question2/student.c Question2/tests.c -o q2

run2: q2
	./q2

q3: Question3/student.c Question3/tests.c
	$(CC) $(CFLAGS) Question3/student.c Question3/tests.c -o q3

run3: q3
	./q3

q4: Question4/student.c Question4/tests.c
	$(CC) $(CFLAGS) Question4/student.c Question4/tests.c -o q4

run4: q4
	./q4

q5: Question5/student.c Question5/tests.c
	$(CC) $(CFLAGS) Question5/student.c Question5/tests.c -o q5

run5: q5
	./q5

q7: Question7/student.c
	$(CC) $(CFLAGS) Question7/student.c -o q7

run7: q7
	./q7

clean:
	rm -f q1 q2 q3 q4 q5 q7