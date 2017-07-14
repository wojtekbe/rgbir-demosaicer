CXXFLAGS=`pkg-config --cflags opencv`
LDFLAGS=`pkg-config --libs opencv`

demosaicer: demosaicer.cpp
	$(CXX) $< $(CXXFLAGS) $(LDFLAGS) -o $@

clean:
	rm -rf demosaicer *.o
