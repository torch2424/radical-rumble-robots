// Script to do replacements on {{}} comments pointing to files to include

const fs = require('fs');
const ggbgfx = require("ggbgfx");

const buildTask = async () => {

  let src = fs.readFileSync('./src/main.c', 'utf8');

  // Replace all includes
  const includes = src.match(/\/\/\s*{{.*}}.*/gm);

  for(let i = 0; i < includes.length; i++) {
    const include = includes[i];

    // Grab the contents of the include
    const includePath = include.substring(
      include.indexOf("{{") + 2,
      include.indexOf("}}")
    ).trim();
    const includeType = include.substring(
      include.indexOf("<") + 2,
      include.indexOf(">")
    ).trim();
    const includeName = include.substring(
      include.indexOf("[") + 2,
      include.indexOf("]")
    ).trim();

    let includeSrc = '';
    if (includePath.endsWith('.c')) {
      fs.readFileSync(includePath, 'utf8');
    } else if (includePath.endsWith('.png')) {
      if (type === 'sprite') {
        const response = await ggbgfx.imageToTilesString(includePath);
        includeSrc = ``
      }
    } else {
      throw new Error(`Cannot handle this file type: ${includePath}`);
    }

    src = src.replace(include, includeSrc);

  }

  fs.writeFileSync('./dist/main.c', src);
};
buildTask();
