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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/mysql/src/access_method_factory.o \
	${OBJECTDIR}/mysql/src/tcp_driver.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/mysql/src/row_of_fields.o \
	${OBJECTDIR}/mysql/src/utilities.o \
	${OBJECTDIR}/mysql/src/binlog_event.o \
	${OBJECTDIR}/mysql/src/binary_log.o \
	${OBJECTDIR}/mysql/src/basic_content_handler.o \
	${OBJECTDIR}/mysql/src/protocol.o \
	${OBJECTDIR}/mysql/src/basic_transaction_parser.o \
	${OBJECTDIR}/mysql/src/file_driver.o \
	${OBJECTDIR}/mysql/src/value.o \
	${OBJECTDIR}/mysql/src/resultset_iterator.o \
	${OBJECTDIR}/mysql/src/field_iterator.o \
	${OBJECTDIR}/mysql/src/binlog_driver.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rhenium

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rhenium: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rhenium ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/mysql/src/access_method_factory.o: mysql/src/access_method_factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/access_method_factory.o mysql/src/access_method_factory.cpp

${OBJECTDIR}/mysql/src/tcp_driver.o: mysql/src/tcp_driver.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/tcp_driver.o mysql/src/tcp_driver.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/mysql/src/row_of_fields.o: mysql/src/row_of_fields.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/row_of_fields.o mysql/src/row_of_fields.cpp

${OBJECTDIR}/mysql/src/utilities.o: mysql/src/utilities.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/utilities.o mysql/src/utilities.cpp

${OBJECTDIR}/mysql/src/binlog_event.o: mysql/src/binlog_event.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/binlog_event.o mysql/src/binlog_event.cpp

${OBJECTDIR}/mysql/src/binary_log.o: mysql/src/binary_log.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/binary_log.o mysql/src/binary_log.cpp

${OBJECTDIR}/mysql/src/basic_content_handler.o: mysql/src/basic_content_handler.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/basic_content_handler.o mysql/src/basic_content_handler.cpp

${OBJECTDIR}/mysql/src/protocol.o: mysql/src/protocol.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/protocol.o mysql/src/protocol.cpp

${OBJECTDIR}/mysql/src/basic_transaction_parser.o: mysql/src/basic_transaction_parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/basic_transaction_parser.o mysql/src/basic_transaction_parser.cpp

${OBJECTDIR}/mysql/src/file_driver.o: mysql/src/file_driver.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/file_driver.o mysql/src/file_driver.cpp

${OBJECTDIR}/mysql/src/value.o: mysql/src/value.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/value.o mysql/src/value.cpp

${OBJECTDIR}/mysql/src/resultset_iterator.o: mysql/src/resultset_iterator.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/resultset_iterator.o mysql/src/resultset_iterator.cpp

${OBJECTDIR}/mysql/src/field_iterator.o: mysql/src/field_iterator.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/field_iterator.o mysql/src/field_iterator.cpp

${OBJECTDIR}/mysql/src/binlog_driver.o: mysql/src/binlog_driver.cpp 
	${MKDIR} -p ${OBJECTDIR}/mysql/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/mysql/src/binlog_driver.o mysql/src/binlog_driver.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/rhenium

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
