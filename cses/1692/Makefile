PROBLEM_NAME := 1692
# +--------------------+
# |                    |
# |   GENERAL CONFIG   |
# |                    |
# +--------------------+

DEBUG := true
LANG := cpp

ifeq ($(LANG),cpp)
TARGET := $(PROBLEM_NAME)
EXECUTE := ./$(TARGET)
CLEAN_TARGETS := $(TARGET)
else ifeq ($(LANG),python)
TARGET := $(PROBLEM_NAME).py
EXECUTE := python3 ./$(TARGET)
CLEAN_TARGETS :=
else
$(error "Unknown language; please set TARGET, EXECUTE, and CLEAN_TARGETS manually")
endif

CXX := g++-13
CXXFLAGS := -std=c++17

PRECOMPILE_HEADERS := bits/stdc++.h
#PRECOMPILE_HEADERS := bits/extc++.h


# +-------------------+
# |                   |
# |   GENERAL RULES   |
# |                   |
# +-------------------+

all: $(TARGET)
.PHONY: all

clean:
	-rm -rf $(CLEAN_TARGETS)
.PHONY: clean

veryclean:
	-rm -rf $(CLEAN_TARGETS) *.res
.PHONY: veryclean

rebuild: clean all
.PHONY: rebuild

# +---------------------+
# |                     |
# |   C++ COMPILATION   |
# |                     |
# +---------------------+

ifeq ($(DEBUG),true)
CXXFLAGS += $(DEBUG_CXXFLAGS)
endif

PCH := .precompiled_headers
CLEAN_TARGETS += $(PCH)

# +-----------------------+
# |                       |
# |   RUNNING / TESTING   |
# |                       |
# +-----------------------+

export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB

run: $(TARGET)
	\time $(EXECUTE)
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif
.PHONY: run

%.res: $(TARGET) %.in
	\time $(EXECUTE) < $*.in > $*.res
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif
.PRECIOUS: %.res

%.out: % # Cancel the builtin rule

__test_%: %.res %.out
	diff $*.res $*.out
.PHONY: __test_%

CASES := $(sort $(basename $(wildcard *.in)))
TESTS := $(sort $(basename $(wildcard *.out)))

runs: $(patsubst %,%.res,$(CASES))
.PHONY: run

solve: runs
.PHONY: solve

test: $(patsubst %,__test_%,$(TESTS))
.PHONY: test