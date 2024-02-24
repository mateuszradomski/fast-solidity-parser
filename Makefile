parser.wasm: src/wasmMain.c src/parser.c src/tokenize.c src/utils.c src/jsonIface.c src/binaryIface.c
	clang --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,-z,stack-size=8388608 -g -o web/parser.wasm src/wasmMain.c -I./
