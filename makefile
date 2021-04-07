CXX := g++
CFLAGS := -std=c++11 -Wall -g
SHDIR := ./_include
OBJS = src/main.cpp src/FileCompress.cpp

compress: $(OBJS)
	@$(CXX) -o $@ $(CFLAGS) $(OBJS)

#$(OBJS) : %.o: %.c
#	@$(CXX) -c $(CFLAGS) $< -o $@

.PHONY: run
run:
	./compress

.PHONY: clean
clean:
	@rm -f *.o compress
	@echo Done cleaning