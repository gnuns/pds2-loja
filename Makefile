CXX=g++
CXXFLAGS=-std=c++11 -Wall

SRC_PATH=src
TEST_PATH=test
BUILD_PATH=build
BIN_NAME=loja
BIN_PATH=$(BUILD_PATH)/bin

# Procura todos os arquivos .cpp na pasta src
SOURCES=$(shell find $(SRC_PATH) -name '*.cpp')
TESTS=$(shell find $(TEST_PATH) -name '*.test.cpp')
# Define os nomes dos arquivos .o a partir dos .cpp
OBJECTS=$(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)
TESTS_OBJECTS=$(TESTS:$(TEST_PATH)/%.cpp=$(BUILD_PATH)/%.o)
# Define os arquivos .d (dependências usadas nos headers)
DEPS=$(OBJECTS:.o=.d)
TESTS_DEPS=$(TESTS_OBJECTS:.o=.d)

default: all

db:
	rm -rf ./build/data/ && cp -R ./data/ ./build/data

tests: $(OBJECTS) $(TESTS_OBJECTS)
	$(CXX) $(CXXFLAGS) $(TESTS_OBJECTS) $(OBJECTS:build\/main\.o/) \
	$(TEST_PATH)/doctest.h -o $(BIN_PATH)/$(BIN_NAME)-test

run-tests: tests
	$(BIN_PATH)/$(BIN_NAME)-test

run:
	$(BIN_PATH)/$(BIN_NAME)

clean:
	rm -rf $(OBJECTS) $(DEPS) $(TESTS_OBJECTS) $(TESTS_DEPS)

dirs:
	@mkdir -p $(dir $(OBJECTS)) $(BIN_PATH)

all: dirs $(BUILD_PATH)/$(BIN_NAME)

# Creation of the executable
$(BUILD_PATH)/$(BIN_NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(BIN_PATH)/$(BIN_NAME)

-include $(DEPS)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) -MP -MMD -c $< -o $@

$(BUILD_PATH)/%.test.o: $(TEST_PATH)/%.test.cpp
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) -MP -MMD -c $< -o $@


