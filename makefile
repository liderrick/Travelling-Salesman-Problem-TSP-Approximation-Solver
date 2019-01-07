#Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

#Project executable output file
PROJ = solver

#Object files
OBJS = main.o christofides.o city.o

#Source files
SRCS = main.cpp christofides.cpp city.cpp

#Header files
HEADERS = christofides.hpp city.hpp

#Compile project executable from object files
${PROJ}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROJ}

#Compile object files from source files
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#Remove project executable and object files
clean:
	rm ${PROJ} ${OBJS}

#Citation:
#Format of this makefile based off of: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4