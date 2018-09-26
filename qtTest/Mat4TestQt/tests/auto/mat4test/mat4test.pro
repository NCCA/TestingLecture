include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_mat4test.h

SOURCES +=     main.cpp
NGLPATH=$$(NGLDIR)
isEmpty(NGLPATH){ # note brace must be here
  message("including $HOME/NGL")
  include($(HOME)/NGL/UseNGL.pri)
}
else{ # note brace must be here
  message("Using custom NGL location")
  include($(NGLDIR)/UseNGL.pri)
}
