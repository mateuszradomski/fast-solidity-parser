CC = clang
TARGET = parser.wasm
SRC = src/engine/wasmMain.c src/engine/parser.c src/engine/tokenize.c src/engine/utils.c src/engine/binaryIface.c
INCLUDES = -I./
WASM_FLAGS = -DWASM --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,-z,stack-size=8388608 -msimd128 -mbulk-memory -mmultivalue
LINUX_FLAGS = -DLINUX
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2 -DNDEBUG

.PHONY: all debug release

debug: $(SRC)
	$(CC) $(WASM_FLAGS) $(DEBUG_FLAGS) -o src/deserializers/javascript/$(TARGET) src/engine/wasmMain.c $(INCLUDES)
	node src/deserializers/javascript/inliner.js parser.wasm

release: $(SRC)
	$(CC) $(WASM_FLAGS) $(RELEASE_FLAGS) -o src/deserializers/javascript/$(TARGET) src/engine/wasmMain.c $(INCLUDES)
	node src/deserializers/javascript/inliner.js parser.wasm

linux: $(SRC)
	$(CC) $(LINUX_FLAGS) $(DEBUG_FLAGS) -o build/parser src/engine/linuxMain.c $(INCLUDES)
