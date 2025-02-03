const fs = require('fs');

const content = fs.readFileSync(process.argv[2])
const base64ed = content.toString('base64')
const result = `const wasmBase64 = "${base64ed}";\nmodule.exports = { wasmBase64 }\n`
fs.writeFileSync('src/deserializers/javascript/inlineBinary.js', result);
