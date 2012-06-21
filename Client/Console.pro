SOURCES += main.cpp \
    ../Communs/logger.cpp \
    ../Communs/Param.cpp \
    ../Communs/sha512.cpp
HEADERS += ../Communs/logger.h \
        ../Communs/Param.h \
        ../Communs/sha512.h
LIBS += -lmysqlclient \
    -lsfml-graphics \
    -lsfml-network
DEFINES += ADMIN
