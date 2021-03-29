# Use conditional include to suppress error when ./configure isn't called on bash-loadables/bash/
-include bash-loadables/bash/Makefile

print_sources:
	@/bin/echo $(SOURCES)

.PHONY: print_sources

.DEFAULT_GOAL := print_sources
