CXX = g++
CXXFLAGS = -g3 -Wall -Wextra

SOURCES = $(shell ls *.cpp)
SOURCES += $(shell ls */*.cpp)
#OBJECTS = $(SOURCES:%.cpp=%.o)
OBJECTS = $(subst .cpp,.o,$(SOURCES))
TARGET = Memento
#VPATH = ./framework

all: $(TARGET)
	@echo "TARGET = $(TARGET)" 

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.PHONY:
clean:
	$(RM) $(TARGET) a.out core *.o */*.o
	@echo "clean OK!"
