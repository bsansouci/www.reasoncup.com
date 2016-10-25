#!/usr/bin/env zsh

rm -rf _build
mkdir _build
rm -rf src/**/*.cm*

set -e

./node_modules/ocaml/bin/ocamldep -ppx ./node_modules/reason/reactjs_jsx_ppx.native -ppx ./node_modules/bs-platform/bin/bsppx.exe -pp ./node_modules/reason/refmt_impl.native -sort -ml-synonym .re src/**/*.re \
| sed "s/src\//-impl src\//g" \
| xargs ./node_modules/bs-platform/bin/bsc.exe -ppx ./node_modules/reason/reactjs_jsx_ppx.native -bin-annot -pp ./node_modules/reason/refmt_impl.native -I src/ -I src/nested/

foo=$(./node_modules/.bin/babel --plugins transform-react-createelement-to-jsx ./src/reFile.js \
| ./node_modules/.bin/esformatter --plugins esformatter-jsx --config eslintConfig.json)
echo "$foo" > ./src/reFile.js

foo=$(./node_modules/.bin/babel --plugins transform-react-createelement-to-jsx ./src/nested/reFile2.js \
| ./node_modules/.bin/esformatter --plugins esformatter-jsx --config eslintConfig.json)
echo "$foo" > ./src/nested/reFile2.js

# ./node_modules/.bin/jscodeshift -t ./node_modules/react-codemod/transforms/class.js src/**/*.js

./node_modules/.bin/webpack
