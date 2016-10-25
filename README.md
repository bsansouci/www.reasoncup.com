#ReactJS bindings

To install run `npm install`. To get merlin to work (and prevent atom throwing errors at your because merlin dies), go in the `.merlin` and modify the start of the absolute path after both `FLG -ppx` to be where the project is in your filesystem.

Launch atom: `npm run editor`.

To build once `do.sh`, to run the watcher `node watch`, to clean all build artifacts `clean.sh`.

Here is the dependency graph between files where `src/jsFile.js` is the root.

```
src/jsFile.js -> src/reFile.re -> src/jsFile2Re.re -> src/jsReactMotionDemo.js
                      |
                      V
                 src/reactMotion.re
                      |
                      V
                 react-motion
```

This project contains demos of react components in JS (root file), react components in Reason (`src/reFile.re`), react-motion written in JS but used from Reason (`src/jsFile2Re.re` and `src/jsReactMotionDemo.js`) and finally react-motion written in Reason used from Reason. I think there is also using a Reason component from JS (just to have all permutations).

Here's what happens to JSX:

```
<ReactMotion.Motion arg1=10> 10 </ReactMotion.Motion>
```

becomes

```
React.createElement ReactMotion.Motion.comp (ReactMotion.Motion.props arg1::10) [| 10 |];
```

So the function `comp` inside the module `Motion` is the component constructor and `props` is a function that will desugar into an inline JS object (thanks to Bucklescript The Transpiler™). That gives us free type checking of props (ocaml will type check that you pass in all the required arguments or the right type etc...).

`src/reFile.re` should contain enough examples to get started.

# danny stuff

install less globally
`npm install less less-plugin-autoprefix fswatch -g`

build css
```
fswatch -o src/less/ | xargs -n1 -I{} lessc src/less/app.less --autoprefix="> 5%" --verbose ./app.css
```
