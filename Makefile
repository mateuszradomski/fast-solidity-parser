CC = clang
TARGET = parser.wasm
SRC = src/engine/wasmMain.c src/engine/parser.c src/engine/tokenize.c src/engine/utils.c src/engine/serializer.c
INCLUDES = -I./
WASM_FLAGS = -DWASM --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,-z,stack-size=8388608 -msimd128 -mbulk-memory -mmultivalue
LINUX_FLAGS = -DLINUX
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2 -Wl,-s

.PHONY: all debug release

wasm: $(SRC)
	$(CC) $(WASM_FLAGS) $(DEBUG_FLAGS) -o src/deserializers/javascript/$(TARGET) src/engine/wasmMain.c $(INCLUDES)
	node src/deserializers/javascript/inliner.js parser.wasm

wasm_release: $(SRC)
	$(CC) $(WASM_FLAGS) $(RELEASE_FLAGS) -o src/deserializers/javascript/$(TARGET) src/engine/wasmMain.c $(INCLUDES)
	wasm-opt -O4 --enable-simd --enable-bulk-memory-opt --enable-multivalue --enable-bulk-memory --enable-mutable-globals --enable-nontrapping-float-to-int --enable-sign-ext src/deserializers/javascript/parser.wasm -o src/deserializers/javascript/optimized.wasm
	node src/deserializers/javascript/inliner.js src/deserializers/javascript/optimized.wasm
	rm src/deserializers/javascript/*.wasm

linux: $(SRC)
	$(CC) $(LINUX_FLAGS) $(DEBUG_FLAGS) -lm -o build/parser src/engine/linuxMain.c $(INCLUDES)

linux_release: $(SRC)
	$(CC) $(LINUX_FLAGS) $(RELEASE_FLAGS) -lm -g -o build/parser src/engine/linuxMain.c $(INCLUDES)
