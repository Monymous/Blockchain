cmake_minimum_required (VERSION 3.8)

set(SOURCES
	main.cpp
	crypto/sha256.cpp
)

set(HEADERS
	crypto/sha256.h	
)

add_executable(test1 ${SOURCES})