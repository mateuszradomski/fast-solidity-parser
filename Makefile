parser.wasm: src/parser.c src/tokenize.c src/utils.c
	clang --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined -Wl,-z,stack-size=8388608 -O0 -o web/parser.wasm src/parser.c -I./
