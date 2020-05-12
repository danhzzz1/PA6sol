# Programming Assignment 6: Fast String Searching
In this Programming Assignment, you will be assessing your understanding of data structures commonly used to perform fast string searches.

## Part 0: Weekly Reflection Survey (5 points)
Complete this weekly reflection survey:  https://forms.gle/zZVZKoBFnyEjpiB9A

## Part 1: Aho-Corasick Automaton (30 points)
Imagine we have a database *D* containing *m* strings, where each string is of length *k*, and we have a long query sequence *Q* of length *n*, where *n* >> *k*. Our computational problem is the following: For every string *w* in *D*, does *w* appear as a substring of *Q*, and if so, at what position(s) of *Q*? Our database does not change very frequently (if ever), but our query changes frequently. We can preprocess the database by constructing an Aho-Corasick Automaton, which will enable a rapid scan of *Q* through *D*.

### Task 1a: Create ``1a.txt`` (5 points)
Imagine we construct an Aho-Corasick Automaton from the following collection of words in the alphabet {A–Z}:

```
A
AG
C
CAA
GAG
GC
GCA
```

How many **nodes** will the resulting automaton have? Create a file called ``1a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single non-negative integer).

### Task 1b: Create ``1b.txt`` (5 points)
How many **failure links** will the automaton in Task 1a have? Create a file called ``1b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single non-negative integer).

### Task 1c: Create ``1c.txt`` (5 points)
How many **dictionary links** will the automaton in Task 1a have? Create a file called ``1c.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single non-negative integer).

### Task 1d: Create ``1d.txt`` (5 points)
Imagine we construct an Aho-Corasick Automaton from the following collection of words  in the alphabet {A–Z, a–z, 0–9}:

```
TheFastAndTheFurious
2Fast2Furious
TheFastAndTheFuriousTokyoDrift
FastAndFurious
FastFive
FastAndFurious6
Furious7
TheFateOfTheFurious
FastAndFuriousPresentsHobbsAndShaw
F9
```

How many **nodes** will the resulting automaton have? Create a file called ``1d.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single non-negative integer).

### Task 1e: Create ``1e.txt`` (5 points)
How many **failure links** will the automaton in Task 1d have? Create a file called ``1e.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single non-negative integer).

### Task 1f: Create ``1f.txt`` (5 points)
How many **dictionary links** will the automaton in Task 1d have? Create a file called ``1f.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing your answer (a single non-negative integer).

## Part 2: Suffix Arrays (35 points)
What if we flipped the roles? Instead of having a *database* that is a collection of many short strings and a *query* that is a single long string, what if I have a *query* that is a collection of many short strings and a *database* that is a single long string? We can preprocess our database string by constructing a Suffix Array, which will enable rapid searches of short query sequences.

### Task 2a: Create ``2a.txt`` (5 points)
Create a file called ``2a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the Suffix Array of the string **``GCATCGC``** as space-delimited 0-based indices. For example, if the Suffix Array were the array ``[5,4,3,2,1,0]``, your file would contain the following:

```
5 4 3 2 1 0
```

### Task 2b: Create ``2b.txt`` (5 points)
Create a file called ``2b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the Suffix Array of the string **``CACAGATTACACACA``** as space-delimited 0-based indices. For example, if the Suffix Array were the array ``[5,4,3,2,1,0]``, your file would contain the following:

```
5 4 3 2 1 0
```

### Task 2c: Edit [``SuffixArray.cpp``](SuffixArray.cpp) (25 points)
In this repository, there is a file called [``SuffixArray.cpp``](SuffixArray.cpp) that contains initial steps towards implementing a Suffix Array. Function headers (with usage details) are included in [``SuffixArray.h``](SuffixArray.h). Your task is to fill in the missing code.

We have provided a tester program, [``SuffixArrayTest``](SuffixArrayTest.cpp), that will help you test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -g -O0 -std=c++11 -o SuffixArrayTest SuffixArrayTest.cpp SuffixArray.cpp
```

When run from the command line, it will ask the user to input a string, and it will print the Suffix Array of the user-inputted string. You can assume the string will be in the alphabet {A–Z}. You can run the tester program as follows:

```
$ g++ -Wall -pedantic -g -O0 -std=c++11 -o SuffixArrayTest SuffixArrayTest.cpp SuffixArray.cpp
$ ./SuffixArrayTest
Enter a string: NIEMA
4 2 1 3 0
```

## Part 3: Burrows-Wheeler Transform (35 points)
Suffix Arrays allow us to preprocess a long database string to perform pretty fast searches of short strings, but what if we want our searches to be even *faster*? We can preprocess our database string by constructing the Burrows-Wheeler Transform, which will enable even faster searches of short query sequences.

### Task 3a: Create ``3a.txt`` (5 points)
Create a file called ``3a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the Burrows-Wheeler Transform of the string **``NIEMAMOSHIRI$``** (which already includes the end-of-string symbol, ``$``).

### Task 3b: Create ``3b.txt`` (5 points)
Create a file called ``3b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the original string whose Burrows-Wheeler Transform is **``ABB$AILA``**. Be sure to include the end-of-string symbol in your answer.

### Task 3c: Edit [``BWT.cpp``](BWT.cpp) (25 points)
In this repository, there is a file called [``BWT.cpp``](BWT.cpp) that contains initial steps towards implementing the Burrows-Wheeler Transform. Function headers (with usage details) are included in [``BWT.h``](BWT.h). Your task is to fill in the missing code.

We have provided a tester program, [``BWTTest``](BWTTest.cpp), that will help you test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -g -O0 -std=c++11 -o BWTTest BWTTest.cpp BWT.cpp
```

When run from the command line, it will ask the user to input a string (including end-of-string symbol, ``$``), and it will print the Burrows-Wheeler Transform of the user-inputted string. You can assume the string will be in the alphabet {A–Z}, and the end-of-string symbol will be ``$``. You can run the tester program as follows:

```
$ g++ -Wall -pedantic -g -O0 -std=c++11 -o BWTTest BWTTest.cpp BWT.cpp
$ ./BWTTest
Enter a string: NIEMA$
AMINE$
```


## Academic Integrity
This Programming Assignment (PA) must be completed 100% independently! You may only discuss the PA with the Tutors, TAs, and Instructors. You are free to use resources from the internet, but you are not allowed to blatantly copy-and-paste code. If you ever find yourself highlighting a code snippet, copying, and pasting into your PA, you are likely violating the Academic Integrity Policy. If you have any concerns or doubts regarding what you are about to do, *please* be sure to post on Piazza first to ask us if it is okay.

## Grading (100 points total)
* **Part 0: Weekly Reflection Survey**
    * 5 points for submitting the weekly reflection survey (extra credit)
    * 0 points for not submitting the weekly reflection survey
* **Part 1: Aho-Corasick Automaton**
    * 5 points for a correct ``1a.txt`` (0 points for incorrect)
    * 5 points for a correct ``1b.txt`` (0 points for incorrect)
    * 5 points for a correct ``1c.txt`` (0 points for incorrect)
    * 5 points for a correct ``1d.txt`` (0 points for incorrect)
    * 5 points for a correct ``1e.txt`` (0 points for incorrect)
    * 5 points for a correct ``1f.txt`` (0 points for incorrect)
* **Part 2: Suffix Arrays**
    * 5 points for a correct ``2a.txt`` (0 points for incorrect)
    * 5 points for a correct ``2b.txt`` (0 points for incorrect)
    * 25 points for a correct ``SuffixArray.cpp`` (partial credit for number of random tests correct)
* **Part 3: Burrows-Wheeler Transform**
    * 5 points for a correct ``3a.txt`` (0 points for incorrect)
    * 5 points for a correct ``3b.txt`` (0 points for incorrect)
    * 25 points for a correct ``BWT.cpp`` (partial credit for number of random tests correct)
