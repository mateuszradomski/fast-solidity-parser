parser.wasm: src/parser.c src/tokenize.c src/utils.c
	clang --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -o web/parser.wasm src/parser.c -I./
