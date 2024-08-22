RUBY=$(shell which ruby)

all:
ifeq ($(RUBY),)
	$(error is ruby installed?)
endif
	$(RUBY) gen.rb
	@echo done!
