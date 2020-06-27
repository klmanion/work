## src Makefile.am

if DEBUG
AM_CXXFLAGS = -g -O0
AM_CPPFLAGS = -DDEBUG
else
AM_CXXFLAGS = -O3
AM_CPPFLAGS = -DNDEBUG
endif

AM_LDFLAGS = -lncurses

bin_PROGRAMS = work
work_SOURCES = main.cpp task.cpp model.cpp delegate.cpp \
	       mode.cpp modes/normal.cpp \
	       view.cpp views/taskview.cpp \
	       controller.cpp controllers/taskcontroller.cpp

