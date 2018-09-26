TARGET=gtest1
QT+=gui opengl core
SOURCES+=main.cpp       str2double.cpp
HEADERS+=str2double.h
LIBS+=-L/usr/local/lib -lgtest -lpthread
INCLUDEPATH+=/usr/local/include
macx:CONFIG-=app_bundle
CONFIG+=c++1z

cache()
