MAKEFILE      = Makefile

CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -isystem /usr/include/libdrm -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/X11R6/lib64 -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 


####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Sources/interface.cpp \
		Sources/main.cpp \
		Sources/entree_sortie.cpp \
		Sources/initialisation_population.cpp \
		Sources/génération.cpp \
		Sources/tinyexpr.c \
		moc_interface.cpp
		
OBJECTS       = interface.o \
		main.o \
		entree_sortie.o \
		initialisation_population.o \
		génération.o \
		tinyexpr.o \
		moc_interface.o
		
TARGET        = Implementation_AG

#first: compile
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(CXX) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	
compile: Makefile $(TARGET)

####### Sub-libraries

compiler_moc_predefs_make_all: moc_predefs.h

moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -Wall -W -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_interface.cpp

moc_interface.cpp: Headers/entree_sortie.h \
		Headers/interface.h \
		Headers/tinyexpr.h \
		Headers/interface.h \
		moc_predefs.h \
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc
		/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/ben/Documents/Cours/S6/projet/ProjetS6/Implementation/Implementation_AG -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7 -I/usr/include/c++/7/backward -I/usr/lib/gcc/x86_64-linux-gnu/7/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include Headers/interface.h -o moc_interface.cpp


####### Compile
main.o:	Sources/main.cpp Headers/interface.h \
		Headers/entree_sortie.h \
		Headers/tinyexpr.h \
		Headers/initialisation_population.h
		$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o Sources/main.cpp
	
interface.o:	Sources/interface.cpp Headers/interface.h \
				Headers/entree_sortie.h \
				Headers/tinyexpr.h
				$(CXX) -c $(CXXFLAGS) $(INCPATH) -o interface.o Sources/interface.cpp

entree_sortie.o:	Sources/entree_sortie.cpp Headers/entree_sortie.h \
					Headers/interface.h \
					Headers/génération.h \
					Headers/tinyexpr.h
					$(CXX) -c $(CXXFLAGS) $(INCPATH) -o entree_sortie.o Sources/entree_sortie.cpp

initialisation_population.o:	Sources/initialisation_population.cpp Headers/initialisation_population.h \
								Headers/tinyexpr.h
								$(CXX) -c $(CXXFLAGS) $(INCPATH) -o initialisation_population.o Sources/initialisation_population.cpp

génération.o:	Sources/génération.cpp Headers/génération.h \
				Headers/entree_sortie.h \
				Headers/initialisation_population.h
				$(CXX) -c $(CXXFLAGS) $(INCPATH) -o génération.o Sources/génération.cpp

tinyexpr.o: Sources/tinyexpr.c Headers/tinyexpr.h
			gcc -c $(CFLAGS) $(INCPATH) -o tinyexpr.o Sources/tinyexpr.c

moc_interface.o: moc_interface.cpp 
			$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_interface.o moc_interface.cpp

		

clean: 
	rm -f *.o
	rm -f moc*.cpp
	rm -f moc*.h

install:  
		sudo apt-get update
		sudo apt-get install qtbase5-dev
		sudo apt-get install texlive-latex-extra
		sudo apt-get install texlive-lang-french
		sudo apt-get install gnuplot

run: 
	./Implementation_AG
	


