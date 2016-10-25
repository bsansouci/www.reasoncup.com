/*
 * vim: set ft=rust:
 * vim: set ft=reason:
 */

/* EXPERIMENT thin wrapper around createClass, not the ML way of life */
type intervalId;

external setInterval : (unit => unit) => int => intervalId = "window.setInterval" [@@bs.val];

external clearInterval : intervalId => unit = "window.clearInterval" [@@bs.val];

let module Console = {
  external log : 'anything => unit = "console.log" [@@bs.val];
};

type props = Js.t < children : Js.null_undefined React.reactElement >;

external props : unit => 'reactJsProps = "" [@@bs.obj];

type state = Js.t < name : string >;

/* WTF is this shit */
let module ReactRe = React;

let nav () =>
  <div className="nav">
    <div className="nav-items content">
      <div className="nav-item"> "ReasonCup" </div>
      <div className="nav-item"> "Item" </div>
      <div className="nav-item"> "Thing" </div>
      <div className="nav-item"> "Stuff" </div>
    </div>
  </div>;

let prolog () =>
  <div className="jumbotron">
    (nav ())
    <section className="content">
      <article>
        <h1> "ReasonCup" </h1>
        <p> "A distributed 48-hour programming event for OCaml and ReasonML programmers. Teams of four build web apps that are fun, useful, or just quirky. Entries will be judged are judged by developers in the Recaml community and prizes doled out accordingly." </p>
        <button> "test" </button>
      </article>
    </section>
    <div className="continue"> "v" </div>
  </div>;

let epilog () =>
  <div className="jumbotron">
    <div className="continue"> "v" </div>
    <section className="content">
      <div className="hero-item">
        <h1> "title" </h1>
        <p> "lorem ipsum" </p>
        <button> "test" </button>
      </div>
    </section>
    (nav ())
  </div>;

let segment1 () =>
  <div className="segment">
    <div className="segment1">
      <p className="segment1"> "segment1" </p>
      <p className="segment1"> "segment1" </p>
    </div>
  </div>;

let segment2 () =>
  <div className="segment">
    <div className="segment2">
      <p className="segment2"> "segment2" </p>
      <p className="segment2"> "segment2" </p>
    </div>
  </div>;

let segment3 () =>
  <div className="segment">
    <div className="segment3">
      <p className="segment3"> "segment3" </p>
      <p className="segment3"> "segment3" </p>
    </div>
  </div>;

let comp = React.createClass (
  {
    val displayName = "ReFile";
    method getInitialState () :state => {"name": "HelloWorld"};
    method render () =>
      <div className="page">
        (prolog ())
        (segment1 ())
        (segment2 ())
        (segment3 ())
        (epilog ())
      </div>
  }
  [@bs]
);
/* type props = Js.t < name : string, children : Js.null_undefined React.reactElement >;

   /* unused, this file only used by js */
   external props : name::string => unit => 'reactJsProps = "" [@@bs.obj];

   type state = Js.t < count : int, name : float >;

   let module PropTypes = React.PropTypes;

   let foo = Js.Null_undefined.empty;

   /* let module ReactRe = React; */

   let comp = React.createClass (
     {
       val displayName = "ReFile";
       val propTypes = {
         "name": PropTypes.isRequired PropTypes.string,
         "asd": PropTypes.oneOfType [|PropTypes.string|],
         "asd2": PropTypes.oneOf [|"foo"|]
       };
       val mutable id = None;
       method getInitialState () :state => {"count": 0, "name": 1.};
       method componentDidMount () => {
         Console.log "mounted!";
         this##id#=(Some (setInterval (fun () => print_endline "asd") 1000))
       };
       method componentWillUnmount () =>
         switch this##id {
         | None => ()
         | Some id => clearInterval id
         };
       method handleClick _ =>
         React.setState this (fun (state: state) => {"count": state##count + 1});
       method handleClick2 _ => {
         let state: state = React.getState this;
         React.setState this {"count": state##count + 22}
       };
       method render () => {
         let state: state = React.getState this;
         let props: props = React.getProps this;
         <div onMouseDown=this##handleClick>
           <div> state##count </div>
           <JsFile2Re name="clickmetoseemagic"> state##count </JsFile2Re>
           <ReactMotion.Motion
             style={
                     "x": ReactMotion.spring (
                       if (state##count mod 2 == 0) {
                         400
                       } else {
                         0
                       }
                     )
                   }>
             (
               fun style =>
                 <div className="demo0">
                   <div
                     className="demo0-block"
                     style={
                             "WebkitTransform": "translate3d(" ^ string_of_float style##x ^ "px, 0, 0)",
                             "transform": "translate3d(" ^ string_of_float style##x ^ "px, 0, 0)"
                           }
                   />
                 </div>
             )
           </ReactMotion.Motion>
           <ReFile2 inner=1 something=(Js.Null_undefined.return "duckyou")>
             state##name
             state##count
             props##children
           </ReFile2>
           <ReFile2 inner=1 something=(Js.Null_undefined.return "asd")>
             state##name
             state##count
             props##children
           </ReFile2>
           <ReFile2 inner=1> state##name state##count </ReFile2>
           <ReFile2 inner=1 something=foo />
           <div> props##name </div>
           [|<div key=1> (props##name ^ "hello") </div>, <div key=2> props##name </div>|]
         </div>
       }
     }
     [@bs]
   ); */
