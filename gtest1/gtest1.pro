TARGET=gtest1
CONFIG-=qt
SOURCES+=*.cpp
HEADERS+=*.h
LIBS+=-L/public/devel/lib -L/usr/local/lib -lgtest -lpthread
INCLUDEPATH+=/public/devel/include
INCLUDEPATH+=/usr/local/include
macx:CONFIG-=app_bundle
CONFIG+=c++11

