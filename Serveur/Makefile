#############################################################################
# Makefile for building: Serveur
# Generated by qmake (2.01a) (Qt 4.6.3) on: mer. juil. 11 18:10:22 2012
# Project:  Serveur.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Serveur.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DADMIN -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -lmysqlclient -lsfml-graphics -lsfml-network -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		serveur.cpp \
		../Communs/logger.cpp \
		../Communs/Param.cpp \
		../Communs/sha512.cpp \
		../Communs/bdd.cpp \
		../Communs/resultatrequete.cpp \
		../Communs/requetebdd.cpp \
		administrateur.cpp \
		environnement.cpp \
		InterfaceReseau/listeinstruction.cpp \
		InterfaceReseau/listejoueurs.cpp \
		InterfaceReseau/joueur.cpp \
		InterfaceReseau/listefonctionserveur.cpp \
		InterfaceReseau/paramtraitement.cpp \
		InterfaceReseau/infojoueur.cpp \
		InterfaceReseau/Listener/virtuallistener.cpp \
		InterfaceReseau/Traitement/virtualtraitement.cpp 
OBJECTS       = main.o \
		serveur.o \
		logger.o \
		Param.o \
		sha512.o \
		bdd.o \
		resultatrequete.o \
		requetebdd.o \
		administrateur.o \
		environnement.o \
		listeinstruction.o \
		listejoueurs.o \
		joueur.o \
		listefonctionserveur.o \
		paramtraitement.o \
		infojoueur.o \
		virtuallistener.o \
		virtualtraitement.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Serveur.pro
QMAKE_TARGET  = Serveur
DESTDIR       = 
TARGET        = Serveur

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Serveur.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Serveur.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile Serveur.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Serveur1.0.0 || $(MKDIR) .tmp/Serveur1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Serveur1.0.0/ && $(COPY_FILE) --parents serveur.h ../Communs/logger.h ../Communs/Param.h ../Communs/sha512.h ../Communs/bdd.h ../Communs/resultatrequete.h ../Communs/requetebdd.h ../Communs/enumTraitement.h InfoJoueur.h administrateur.h environnement.h InterfaceReseau/listeinstruction.h InterfaceReseau/listejoueurs.h InterfaceReseau/joueur.h InterfaceReseau/listefonctionserveur.h InterfaceReseau/paramtraitement.h InterfaceReseau/infojoueur.h InterfaceReseau/Listener/virtuallistener.h InterfaceReseau/Listener/listener.h InterfaceReseau/Listener/listener.tpp InterfaceReseau/Listener/listeneradmin.h InterfaceReseau/Listener/listenerclient.h InterfaceReseau/Listener/listenerclient.inline InterfaceReseau/Traitement/virtualtraitement.h InterfaceReseau/Traitement/Traitement.h InterfaceReseau/Traitement/Traitement.tpp InterfaceReseau/Traitement/traitementclient.inline InterfaceReseau/Traitement/traitementclient.h InterfaceReseau/Listener/listeneradmin.inline InterfaceReseau/Traitement/traitementadmin.h InterfaceReseau/Traitement/traitementadmin.inline .tmp/Serveur1.0.0/ && $(COPY_FILE) --parents main.cpp serveur.cpp ../Communs/logger.cpp ../Communs/Param.cpp ../Communs/sha512.cpp ../Communs/bdd.cpp ../Communs/resultatrequete.cpp ../Communs/requetebdd.cpp administrateur.cpp environnement.cpp InterfaceReseau/listeinstruction.cpp InterfaceReseau/listejoueurs.cpp InterfaceReseau/joueur.cpp InterfaceReseau/listefonctionserveur.cpp InterfaceReseau/paramtraitement.cpp InterfaceReseau/infojoueur.cpp InterfaceReseau/Listener/virtuallistener.cpp InterfaceReseau/Traitement/virtualtraitement.cpp .tmp/Serveur1.0.0/ && (cd `dirname .tmp/Serveur1.0.0` && $(TAR) Serveur1.0.0.tar Serveur1.0.0 && $(COMPRESS) Serveur1.0.0.tar) && $(MOVE) `dirname .tmp/Serveur1.0.0`/Serveur1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Serveur1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp ../../Console/Console/logger.h \
		../../Console/Console/Param.h \
		InterfaceReseau/Listener/listeneradmin.h \
		InterfaceReseau/Listener/listener.h \
		InterfaceReseau/Listener/virtuallistener.h \
		InterfaceReseau/joueur.h \
		InfoJoueur.h \
		../Communs/requetebdd.h \
		../Communs/bdd.h \
		../Communs/resultatrequete.h \
		InterfaceReseau/infojoueur.h \
		../Communs/enumTraitement.h \
		InterfaceReseau/listeinstruction.h \
		InterfaceReseau/Listener/listener.tpp \
		InterfaceReseau/Traitement/traitementadmin.h \
		InterfaceReseau/Traitement/Traitement.h \
		InterfaceReseau/Traitement/virtualtraitement.h \
		InterfaceReseau/listejoueurs.h \
		InterfaceReseau/paramtraitement.h \
		InterfaceReseau/listefonctionserveur.h \
		../Communs/Param.h \
		../Communs/sha512.h \
		InterfaceReseau/Traitement/Traitement.tpp \
		InterfaceReseau/Traitement/traitementadmin.inline \
		InterfaceReseau/Listener/listeneradmin.inline
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

serveur.o: serveur.cpp serveur.h \
		InterfaceReseau/listeinstruction.h \
		InterfaceReseau/joueur.h \
		InfoJoueur.h \
		InterfaceReseau/listejoueurs.h \
		../Communs/Param.h \
		InterfaceReseau/paramtraitement.h \
		administrateur.h \
		environnement.h \
		../Communs/logger.h \
		../../Console/Console/Param.h \
		InterfaceReseau/Traitement/traitementclient.h \
		InterfaceReseau/Traitement/Traitement.h \
		InterfaceReseau/Traitement/virtualtraitement.h \
		../Communs/enumTraitement.h \
		InterfaceReseau/listefonctionserveur.h \
		../Communs/requetebdd.h \
		../Communs/bdd.h \
		../Communs/resultatrequete.h \
		InterfaceReseau/infojoueur.h \
		../Communs/sha512.h \
		InterfaceReseau/Traitement/Traitement.tpp \
		InterfaceReseau/Traitement/traitementclient.inline \
		InterfaceReseau/Listener/listenerclient.h \
		InterfaceReseau/Listener/listener.h \
		InterfaceReseau/Listener/virtuallistener.h \
		InterfaceReseau/Listener/listener.tpp \
		InterfaceReseau/Listener/listenerclient.inline
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o serveur.o serveur.cpp

logger.o: ../Communs/logger.cpp ../Communs/logger.h \
		../../Console/Console/Param.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o logger.o ../Communs/logger.cpp

Param.o: ../Communs/Param.cpp ../../Console/Console/Param.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Param.o ../Communs/Param.cpp

sha512.o: ../Communs/sha512.cpp ../Communs/sha512.h \
		../../Console/Console/Param.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sha512.o ../Communs/sha512.cpp

bdd.o: ../Communs/bdd.cpp ../Communs/bdd.h \
		../../Console/Console/Param.h \
		../Communs/resultatrequete.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bdd.o ../Communs/bdd.cpp

resultatrequete.o: ../Communs/resultatrequete.cpp ../Communs/resultatrequete.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o resultatrequete.o ../Communs/resultatrequete.cpp

requetebdd.o: ../Communs/requetebdd.cpp ../Communs/requetebdd.h \
		../Communs/bdd.h \
		../../Console/Console/Param.h \
		../Communs/resultatrequete.h \
		InterfaceReseau/infojoueur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o requetebdd.o ../Communs/requetebdd.cpp

administrateur.o: administrateur.cpp administrateur.h \
		environnement.h \
		InfoJoueur.h \
		../Communs/logger.h \
		../../Console/Console/Param.h \
		../Communs/requetebdd.h \
		../Communs/bdd.h \
		../Communs/resultatrequete.h \
		InterfaceReseau/infojoueur.h \
		../Communs/Param.h \
		../Communs/sha512.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o administrateur.o administrateur.cpp

environnement.o: environnement.cpp environnement.h \
		InfoJoueur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o environnement.o environnement.cpp

listeinstruction.o: InterfaceReseau/listeinstruction.cpp InterfaceReseau/listeinstruction.h \
		InterfaceReseau/joueur.h \
		InfoJoueur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o listeinstruction.o InterfaceReseau/listeinstruction.cpp

listejoueurs.o: InterfaceReseau/listejoueurs.cpp InterfaceReseau/listejoueurs.h \
		InterfaceReseau/joueur.h \
		InfoJoueur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o listejoueurs.o InterfaceReseau/listejoueurs.cpp

joueur.o: InterfaceReseau/joueur.cpp InterfaceReseau/joueur.h \
		InfoJoueur.h \
		InterfaceReseau/Listener/virtuallistener.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o joueur.o InterfaceReseau/joueur.cpp

listefonctionserveur.o: InterfaceReseau/listefonctionserveur.cpp InterfaceReseau/listefonctionserveur.h \
		InterfaceReseau/listeinstruction.h \
		InterfaceReseau/joueur.h \
		InfoJoueur.h \
		InterfaceReseau/paramtraitement.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o listefonctionserveur.o InterfaceReseau/listefonctionserveur.cpp

paramtraitement.o: InterfaceReseau/paramtraitement.cpp InterfaceReseau/paramtraitement.h \
		InterfaceReseau/listeinstruction.h \
		InterfaceReseau/joueur.h \
		InfoJoueur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o paramtraitement.o InterfaceReseau/paramtraitement.cpp

infojoueur.o: InterfaceReseau/infojoueur.cpp InterfaceReseau/infojoueur.h \
		../Communs/bdd.h \
		../../Console/Console/Param.h \
		../Communs/resultatrequete.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o infojoueur.o InterfaceReseau/infojoueur.cpp

virtuallistener.o: InterfaceReseau/Listener/virtuallistener.cpp InterfaceReseau/Listener/virtuallistener.h \
		InterfaceReseau/joueur.h \
		InfoJoueur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o virtuallistener.o InterfaceReseau/Listener/virtuallistener.cpp

virtualtraitement.o: InterfaceReseau/Traitement/virtualtraitement.cpp InterfaceReseau/Traitement/virtualtraitement.h \
		InterfaceReseau/listeinstruction.h \
		InterfaceReseau/joueur.h \
		InfoJoueur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o virtualtraitement.o InterfaceReseau/Traitement/virtualtraitement.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

