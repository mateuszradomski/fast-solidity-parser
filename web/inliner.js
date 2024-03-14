const fs = require('fs');
const path = require('path');

// Replace 'path/to/your/file.bin' with the actual file path
const filePath = path.join(__dirname, process.argv[2]);

fs.readFile(filePath, (err, data) => {
    if (err) throw err;
    
    // Convert data to an array of byte values
    const uint8Array = new Uint8Array(data);
    // const output = new Uint16Array(uint8Array.buffer);
    const output = uint8Array

    const wordArray = [...output];
    // Convert the byte array to a string representation for use in JS
    const jsArrayString = JSON.stringify(wordArray);
    
    const result = `const myArray = ${jsArrayString};\nmodule.exports = { myArray }\n`
    fs.writeFileSync('web/inlineBinary.js', result);
});
