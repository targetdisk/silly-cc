UNAME = $(shell uname)
STRIP ?= strip
CLANG ?= $(shell which clang)
CLANG++ ?= $(shell which clang++)

CFLAGS ?= -Wall
ifeq ($(UNAME),Linux)
	OPEN=xdg-open
endif
ifeq ($(detected_OS),Darwin)
	OPEN=open
endif

pub-css:
	-[ ! -e pub.css ] && wget https://github.com/manuelp/pandoc-stylesheet/raw/acac36b976966f76544176161ba826d519b6f40c/pub.css

README: pub-css # Requires Pandoc to be installed
	pandoc README.md -s -c pub.css -o README.html
	$(OPEN) README.html

silly-cc: silly-cc.c
	$(CC) $(CFLAGS) -DCLANG=$(CLANG) -o $@ $<

silly-cxx: silly-cc.c
	$(CC) $(CFLAGS) -DCLANG=$(CLANG++) -o $@ $<

strip: silly-cc
	$(STRIP) $^

clean:
	rm silly-cc
