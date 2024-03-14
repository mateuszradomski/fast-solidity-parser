#!/bin/bash
make debug && node web/test.js single $1 && difft myAST.json antlrAST.json
