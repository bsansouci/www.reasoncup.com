/*
 * vim: set ft=rust:
 * vim: set ft=reason:
 */
 
type props =
  Js.t <
    inner : int,
    something : Js.null_undefined string,
    children : Js.null_undefined React.reactElement
  >;

external props : inner::int => something::(Js.null_undefined string)? => unit => 'reactJsProps = "" [@@bs.obj];

type state = Js.t <inner : int>;

let t = Obj.magic;

let comp = React.createClass (
  {
    method getInitialState () :state => {"inner": 0};
    method handleClick _ =>
      React.setState this (fun (state: state) => {"inner": state##inner + 1});
    method handleClick2 _ =>
      React.setState this (fun (state: state) => {"inner": state##inner + 1});
    method render () => {
      /* let state: state = React.getState this; */
      let props: props = React.getProps this;
      switch (Js.Null_undefined.to_opt props##something) {
      | None => print_endline "a"
      | Some b => print_endline b
      };
      React.createElement "div" {"onClick": this##handleClick} [|"hi------->", t props##children|]
    }
  }
  [@bs]
);
