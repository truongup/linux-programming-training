CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
OBJ_DIR := $(CUR_DIR)/obj
SRC_DIR := $(CUR_DIR)/src
INC_DIR := $(CUR_DIR)/inc
SHARED_LIB_DIR := $(CUR_DIR)/shared_lib
STATIC_LIB_DIR := $(CUR_DIR)/static_lib

OBJ_SHARED_NAME := shared_obj
OBJ_STATIC_NAME := static_obj

#Ten goc cua file thu vien
LIB_NAME_HEADER := strutils.h
LIB_NAME_SRC := bstrutils.c

#Ten Lib cua shared va static
LIB_FOR_USE := strutil

# Build Source Main.C thanh file Object 
src_main_build:
	gcc -c -o $(OBJ_DIR)/main.o $(SRC_DIR)/main.c -I $(INC_DIR)


shared_lib_build:
	gcc -c -fPIC $(SRC_DIR)/$(LIB_NAME_SRC) -o $(OBJ_DIR)/shared_lib.o -I $(INC_DIR)
	gcc -shared $(OBJ_DIR)/shared_lib.o -o $(SHARED_LIB_DIR)/lib$(LIB_FOR_USE).so 

static_lib_build:
	gcc -c $(SRC_DIR)/$(LIB_NAME_SRC) -o $(OBJ_DIR)/static_lib.o -I $(INC_DIR)
	ar rcs $(STATIC_LIB_DIR)/lib$(LIB_FOR_USE).a $(OBJ_DIR)/static_lib.o

linking_build:
	gcc $(OBJ_DIR)/main.o -L$(SHARED_LIB_DIR) -l$(LIB_FOR_USE) -o $(BIN_DIR)/main_shared 
	gcc $(OBJ_DIR)/main.o -L$(STATIC_LIB_DIR) -l$(LIB_FOR_USE) -o $(BIN_DIR)/main_static


clean:
	rm -rf $(OBJ_DIR)/main.o
	rm -rf $(OBJ_DIR)/shared_lib.o 
	rm -rf $(SHARED_LIB_DIR)/lib$(LIB_FOR_USE).so
	rm -rf $(OBJ_DIR)/static_lib.o
	rm -rf $(STATIC_LIB_DIR)/lib$(LIB_FOR_USE).a
	rm -rf $(BIN_DIR)/main_shared $(BIN_DIR)/main_static


