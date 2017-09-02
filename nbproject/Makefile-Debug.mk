#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=clang
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ClientsBox.o \
	${OBJECTDIR}/QMessage.o \
	${OBJECTDIR}/SClient.o \
	${OBJECTDIR}/SParams.o \
	${OBJECTDIR}/SQueue.o \
	${OBJECTDIR}/SocketServer.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pthread
CXXFLAGS=-pthread

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/socket.server.frame

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/socket.server.frame: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/socket.server.frame ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ClientsBox.o: ClientsBox.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/shared -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt/sys -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/alljoyn_c -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/gl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc/windows -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl/wrappers -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/VC/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClientsBox.o ClientsBox.cpp

${OBJECTDIR}/QMessage.o: QMessage.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/shared -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt/sys -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/alljoyn_c -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/gl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc/windows -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl/wrappers -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/VC/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QMessage.o QMessage.cpp

${OBJECTDIR}/SClient.o: SClient.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/shared -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt/sys -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/alljoyn_c -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/gl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc/windows -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl/wrappers -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/VC/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SClient.o SClient.cpp

${OBJECTDIR}/SParams.o: SParams.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/shared -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt/sys -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/alljoyn_c -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/gl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc/windows -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl/wrappers -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/VC/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SParams.o SParams.cpp

${OBJECTDIR}/SQueue.o: SQueue.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/shared -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt/sys -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/alljoyn_c -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/gl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc/windows -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl/wrappers -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/VC/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SQueue.o SQueue.cpp

${OBJECTDIR}/SocketServer.o: SocketServer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/shared -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt/sys -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/alljoyn_c -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/gl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc/windows -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl/wrappers -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/VC/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SocketServer.o SocketServer.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/shared -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/ucrt/sys -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/alljoyn_c -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/gl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/um/qcc/windows -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/SDK/include/winrt/wrl/wrappers -I/D/Program\ Files\ \(x86\)/Microsoft\ Visual\ Studio/2017/Enterprise/SDK/ScopeCppSDK/VC/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
