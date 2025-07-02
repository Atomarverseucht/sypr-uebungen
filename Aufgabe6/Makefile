SUBDIRS := ./lib ./bin

.PHONY: all clean $(SUBDIRS)
LIBTYPE ?= a

all: $(SUBDIRS)

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean $(MFLAGS) LIBTYPE=$(LIBTYPE); \
	done

$(SUBDIRS):
	$(MAKE) all $(MFLAGS) -C $@ LIBTYPE=$(LIBTYPE)