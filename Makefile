# use g++ with C++11 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=SuffixArrayTest BWTTest

all: $(OUTFILES)

SuffixArrayTest: SuffixArrayTest.cpp SuffixArray.cpp SuffixArray.h
	$(CXX) $(CXXFLAGS) -o SuffixArrayTest SuffixArrayTest.cpp SuffixArray.cpp

BWTTest: BWTTest.cpp BWT.cpp BWT.h
	$(CXX) $(CXXFLAGS) -o BWTTest BWTTest.cpp BWT.cpp

clean:
	$(RM) $(OUTFILES) *.o
