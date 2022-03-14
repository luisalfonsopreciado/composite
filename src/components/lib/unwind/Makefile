# Required variables used to drive the compilation process. It is OK
# for many of these to be empty.
#
# The library names associated with .a files output that are linked
# (via, for example, -lunwind) into dependents. This list should be
# "unwind" for output files such as libunwind.a.
LIBRARY_OUTPUT = unwind unwind-ptrace
# The .o files that are mandatorily linked into dependents. This is
# rarely used, and only when normal .a linking rules will avoid
# linking some necessary objects. This list is of names (for example,
# unwind) which will generate unwind.lib.o. Do NOT include the list of .o
# files here. Please note that using this list is *very rare* and
# should only be used when the .a support above is not appropriate.
OBJECT_OUTPUT =
# The path within this directory that holds the .h files for
# dependents to compile with (./ by default). Will be fed into the -I
# compiler arguments.
INCLUDE_PATHS = libunwind/include
# The interfaces this component is dependent on for compilation (this
# is a list of directory names in interface/)
INTERFACE_DEPENDENCIES =
# The library dependencies this component is reliant on for
# compilation/linking (this is a list of directory names in lib/)
LIBRARY_DEPENDENCIES = component crt posix
# Note: Both the interface and library dependencies should be
# *minimal*. That is to say that removing a dependency should cause
# the build to fail. The build system does not validate this
# minimality; that's on you!

# There are two different *types* of Makefiles for libraries.
# 1. Those that are Composite-specific, and simply need an easy way to
#    compile and itegrate their code.
# 2. Those that aim to integrate external libraries into
#    Composite. These focus on "driving" the build process of the
#    external library, then pulling out the resulting files and
#    directories. These need to be flexible as all libraries are
#    different.

# Type 1, Composite library: This is the default Makefile for
# libraries written for composite. Get rid of this if you require a
# custom Makefile (e.g. if you use an existing
# (non-composite-specific) library. An example of this is `kernel`.
# include Makefile.lib

## Type 2, external library: If you need to specialize the Makefile
## for an external library, you can add the external code as a
## subdirectory, and drive its compilation, and integration with the
## system using a specialized Makefile. The Makefile must generate
## lib$(LIBRARY_OUTPUT).a and $(OBJECT_OUTPUT).lib.o, and have all of
## the necessary include paths in $(INCLUDE_PATHS).
##
## To access the Composite Makefile definitions, use the following. An
## example of a Makefile written in this way is in `ps/`.
#
# include Makefile.src Makefile.comp Makefile.dependencies
# .PHONY: all clean init distclean
## Fill these out with your implementation
# all:
# clean:
#
## Default rules:
# init: clean all
# distclean: clean

# Generate absolute paths
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

UNWDIR=libunwind/
UNWBIN=$(mkfile_dir)/libunwind/bin/
UNWLIB=$(UNWBIN)lib/

include Makefile.src Makefile.comp Makefile.dependencies

.PHONY: all clean init distclean armv7a_init i386_init x86_64_init
all:
	$(info Building unwind library...)
	make $(PLATFORM)_init
	cp $(UNWLIB)*.a .

clean:
	make -C $(UNWDIR) distclean
	rm -rf $(UNWBIN)
	rm -rf *.a

armv7a_init:
	$(info Building libunwind for arm...)
	cd $(UNWDIR); autoreconf -i; ./configure; make; make clean; make install prefix=$(UNWBIN); cd ..

i386_init:
	$(info Building libunwind for i386...)
	cd $(UNWDIR); autoreconf -i; ./configure; make; make clean; make install prefix=$(UNWBIN); cd ..

x86_64_init:
	$(info Building libunwind for x86_64)
	cd $(UNWDIR); autoreconf -i; ./configure; make; make clean; make install prefix=$(UNWBIN); cd ..
