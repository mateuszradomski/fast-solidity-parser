CC = clang
TARGET = parser.wasm
SRC = src/wasmMain.c src/parser.c src/tokenize.c src/utils.c src/jsonIface.c src/binaryIface.c
INCLUDES = -I./
WASM_FLAGS = -DWASM --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,-z,stack-size=8388608
LINUX_FLAGS = -DLINUX
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2 -DNDEBUG -msimd128

.PHONY: all debug release

debug: $(SRC)
	$(CC) $(WASM_FLAGS) $(DEBUG_FLAGS) -o web/$(TARGET) src/wasmMain.c $(INCLUDES)

release: $(SRC)
	$(CC) $(WASM_FLAGS) $(RELEASE_FLAGS) -o web/$(TARGET) src/wasmMain.c $(INCLUDES)

linux: $(SRC)
	$(CC) $(LINUX_FLAGS) $(DEBUG_FLAGS) -o build/parser src/linuxMain.c $(INCLUDES)
