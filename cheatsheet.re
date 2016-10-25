/* cheat sheet */

/* reason -> js */

/* string */
let mapsToJsString = "asd";

/* number */
let mapsToNumber = 1;
let mapsToNumberToo = 1.;

/* array */
let mapsToJsArray = [|1, 2|];
let alsoMapsToJsArray = (1, "foo");

/* object */
/* shape specification optional */
type obj = <hi: string>;

let mapsToJsObj: Js.t obj = [%bs.obj {hi: "a"}];

/* object too */
external alsoMapsToJsObj : b::int? => def::string? => unit => _ = "" [@@bs.obj];
let foo = alsoMapsToJsObj b::1 ();

/* boolean */
/* github.com/bloomberg/bucklescript/blob/0212ef6a4d1b9f1c90cc86f1852cd3eb82489df1/jscomp/runtime/js.ml#L51 */
Js.true_;
Js.false_;

/* nullable */
Js.Null.empty;
/* more conversions in github.com/bloomberg/bucklescript/blob/0212ef6a4d1b9f1c90cc86f1852cd3eb82489df1/jscomp/runtime/js_primitive.mli */

/* what's [%bs] */

/* write some functions inline, some values,
let null = [%bs.raw "null"]
[%%bs.raw "let a = null"]
^ like that

%bs.raw (doesn't parse and sanitize, and no guarantee or ordering, so don't abuse ur power) */

/* js -> reason */


/* string */
/* "the external js side has a string, I'll type it as such" */
/* foo.jsStringInFooModule */
external jsStringInFooModule: string = "jsStringInFooModule" [@@bs.module "foo"];
external jsString: string = "jsStringVariable" [@@bs.val];

/* number */
external jsNumberAsOCamlInt: int = "jsNumber1" [@@bs.module "foo"];
external jsNumberAsOCamlFloat: float = "jsNumber2Variable" [@@bs.val];

/* array */
/* respect the conversion don't type it as list. It'll blow up somewhere else. */
external arr : array int = "someJsArray" [@@bs.val];
/* at this point, you probably get that for js -> reason, we can insert arbitrary js value/reference A and
   type it as B, as long as we make sure that, in the other direction, BS indeed compiles something of type B
   to A. Here, an ocaml array [|1, 2|] indeed compiles to [1, 2]. Another way to think about this is: "is
   there an array of int that compiles to [1, 2]?" */

/* object */
/* shape specification optional. Also, see comment above. */
type greeting = <hi: int>;
external obj: Js.t greeting = "someJsObj" [@@bs.val];
external setHi : Js.t greeting => int => unit = "hi" [@@bs.set];
external getHi : Js.t greeting => int = "hi" [@@bs.get];
setHi obj 2;
getHi obj;

/* boolean */
/* github.com/bloomberg/bucklescript/blob/0212ef6a4d1b9f1c90cc86f1852cd3eb82489df1/jscomp/runtime/js.ml#L51 */
Js.to_bool jsBooleanValue

/* nullable */
Js.Null.empty;













/* examples */
/* type string from js, concat to string
type js array as array, then convert to list
convert list to js array by going through array */

/* let asd = None; */
/* let a = [%bs.obj {hi: "a"}]; */

/* let foo asd => {
  asd#hi ^ "ad";
}; */

/* foo a; */
