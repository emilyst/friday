TARGET    = weekend

SRCDIR    = src
INCDIR    = inc
BUILDDIR  = .build
TARGETDIR = bin
SRCEXT    = c
OBJEXT    = o

INC      += -I$(INCDIR) -I/usr/local/include

CFLAGS   += -Og -ggdb
CFLAGS   += -std=c11
CFLAGS   += -MMD
CFLAGS   += -D_FORTIFY_SOURCE -D_GNU_SOURCE
CFLAGS   += -fms-extensions -Wno-microsoft-anon-tag
CFLAGS   += -Wall -Werror -Wextra -Wpedantic -pedantic-errors
CFLAGS   += -Wundef -Wuninitialized -Wno-unused
CFLAGS   += -Wswitch -Wswitch-default -Wswitch-enum
CFLAGS   += -Wmissing-noreturn
CFLAGS   += -Wvla -Wdouble-promotion -Wpointer-sign -Wsign-compare -Wsign-conversion
CFLAGS   += -Wstrict-prototypes -Wredundant-decls
CFLAGS   += -fstack-protector -Wstack-protector -Wvarargs
CFLAGS   += -fstrict-aliasing

LDFLAGS  += -L/usr/local/lib -lm

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CFLAGS += $(shell pkg-config --cflags libbsd)
    LDFLAGS += $(shell pkg-config --libs libbsd)
endif

SOURCES  = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS  = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) -c -o $@ $< $(INC) $(CFLAGS) $(TARGET_ARCH)

$(TARGETDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CC) -o $@ $^ $(LDFLAGS) $(LOADLIBES) $(LDLIBS) $(TARGET_ARCH)

include $(wildcard $(OBJECTS:.o=.d))

all: $(TARGETDIR)/$(TARGET)

clean:
	rm -rf $(OBJECTS) $(OBJECTS:.o=.d) $(TARGET)
	rm -rf $(BUILDDIR) $(TARGETDIR)

.PHONY: clean all
