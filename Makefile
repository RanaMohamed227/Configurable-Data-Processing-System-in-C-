
# ---------- Makefile ---------------------------------------------------
# Simple build for the Processor / Configuration demo
# ----------------------------------------------------------------------

# toolchain
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Iinc      # C++17 + warnings + header path
LDFLAGS  :=                            # add -lstdc++fs if you use gcc 8.*

# folders and target names
SRCDIR   := src
INCDIR   := inc
BUILDDIR := build
BINDIR   := bin
TARGET   := $(BINDIR)/app              # final executable

# auto-discover sources / objects
SRC      := $(wildcard $(SRCDIR)/*.cpp)
OBJ      := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))

# ----------------------------------------------------------------------
# default goal
all: $(TARGET)

# link step ------------------------------------------------------------

$(TARGET): $(OBJ) | $(BINDIR)
	$(CXX) $(OBJ) $(LDFLAGS) -o $@
# compile step ---------------------------------------------------------
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# helper dirs ----------------------------------------------------------
$(BUILDDIR) $(BINDIR):
	mkdir -p $@

# clean ---------------------------------------------------------------
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all clean

