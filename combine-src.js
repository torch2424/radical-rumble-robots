// Script to do replacements on {{}} comments pointing to files to include

const fs = require('fs');

let src = fs.readFileSync('./src/main.c', 'utf8');

const includes = src.match(/\/\/\s*{{.*}}.*/gm);

includes.forEach(include => {

  // Grab the contents of the include
  const includePath = include.substring(
    include.indexOf("{{") + 2,
    include.indexOf("}}")
  ).trim();

  const includeSrc = fs.readFileSync(includePath, 'utf8');

  src = src.replace(include, includeSrc);
});

fs.writeFileSync('./dist/main.c', src);
