SUBDIRS := ./lib ./bin

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean $(MFLAGS); \
	done

$(SUBDIRS):
	$(MAKE) all $(MFLAGS) -C $@