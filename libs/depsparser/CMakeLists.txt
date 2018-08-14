set (LIB_SRCS 
		depsfilerepoparser.cpp 
		depsfilerepoparser.h 
		parsererrorlistener.cpp 
		parsererrorlistener.h 
		visitordeps.cpp 
		visitordeps.h 
	)
 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/generated   ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/antlr/runtime/Cpp/runtime/src ) 

IF(GENERATE_DEPSPARSER)
add_custom_command(  
    OUTPUT  
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}BaseListener.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}BaseVisitor.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}Lexer.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}BaseListener.cpp      
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}Listener.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}Parser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}Visitor.cpp 
  
    COMMAND "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_DIR} -Dlanguage=Cpp -listener -visitor  -package ${PACKAGE_LANGNAME} -o ${CMAKE_CURRENT_SOURCE_DIR}/generated ${GRAMMAR_SRCS}
)  

endif(GENERATE_DEPSPARSER)

set(ANTLRBASE_SRC    
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}BaseListener.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}BaseVisitor.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}Lexer.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}BaseListener.cpp      
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}Listener.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}Parser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/${grammarfname}Visitor.cpp 
	)
 
add_library(depsparser STATIC ${LIB_SRCS} ${ANTLRBASE_SRC})

if(GENERATE_DEPSPARSER)
add_custom_command(TARGET depsparser PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/generated)
endif(GENERATE_DEPSPARSER)
