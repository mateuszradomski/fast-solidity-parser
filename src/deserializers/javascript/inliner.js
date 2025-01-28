const fs = require('fs');
const path = require('path');

const filePath = path.join(__dirname, process.argv[2]);
const content = fs.readFileSync(filePath)
const base64ed = content.toString('base64')
const result = `const wasmBase64 = "${base64ed}";\nmodule.exports = { wasmBase64 }\n`
fs.writeFileSync('src/deserializers/javascript/inlineBinary.js', result);
