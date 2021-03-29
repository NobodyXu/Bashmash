CXX := $(shell (clang++ -v >/dev/null 2>&1 && echo clang++) || (g++ -v >/dev/null 2>&1 && echo g++))

INCS := -I"bash-loadables" -I"bash-loadables/bash/include"

CFLAGS := -flto -Oz -s -Wno-parentheses -Wno-format-security -fvisibility=hidden 
CFLAGS += -fno-asynchronous-unwind-tables -fno-unwind-tables  -fmerge-all-constants

LDFLAGS := -shared -Wl,-soname,$@ -Wl,-icf=all,--gc-sections -flto -Wl,--plugin-opt=O3 -fuse-ld=lld

SRCS := $(shell find src/ -name '*.cpp')
OBJS := $(SRCS:.cpp=.o)
BASHDEPS := $(addprefix bash-loadables/bash/, $(shell $(MAKE) -f helper.mk))

bashmath: $(OBJS)
	$(CXX) -fPIC $(LDFLAGS) $(LIBS) $(OBJS) -o $@

%.o: %.cpp bash-loadables/bash/bash
	$(CXX) -fPIC -c $(CXXFLAGS) $(CFLAGS) $(INCS) -o $@ $<

bash-loadables/bash/bash: bash-loadables/bash/Makefile $(BASHDEPS)
	$(MAKE) -C bash-loadables/bash

bash-loadables/bash/Makefile: bash-loadables/bash/configure
	cd bash-loadables/bash && ./configure

install: bashmath
	cp bashmath /usr/local/lib/bashmath

clean:
	$(MAKE) -C bash-loadables/bash clean
	rm -rf $(OBJS) bashmath bash-loadables/bash/Makefile

.PHONY: clean
