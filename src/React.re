/*
 * vim: set ft=rust:
 * vim: set ft=reason:
 */
 
type reactClass;

/* TODO: type classSpec (can't right now bc 'reactElement) */
/* TODO: (chenglou) api 2, how about `method private`, or is it much learning overhead? (Same output) */
external createClass : 'classSpec => reactClass = "createClass" [@@bs.val] [@@bs.module "react"];

/* TODO: (chenglou) api 2, type children (string, number, etc.) */
type reactElement;

external createElement : 'form => 'props => array 'children => reactElement = "createElement" [@@bs.splice] [@@bs.val] [@@bs.module
                                                                    "react"
                                                                    ];

external getState : 'this => 'reactJsState = "state" [@@bs.get];

external setState : 'this => 'state => unit = "setState" [@@bs.send];

external getProps : 'this => 'reactJsProps = "props" [@@bs.get];

/* TODO: (chenglou) api 2, @IwanKaramazow */
/* TODO: (chenglou) type event */
/* this avoids needing to type partial state in setState */
/* external getReactState : 'this => 'reactJsState = "state" [@@bs.get];
   external getMLState : 'this => 'mlState = "mlState" [@@bs.get];
   let get_state this => getMLState (getReactState this);
   external setState : 'this => 'state => unit = "setState" [@@bs.send];
   external makeJsState : mlState::'a => 'jsState = "" [@@bs.obj];
   let set_state this state => setState this (makeJsState mlState::state); */
let module PropTypes = {
  type propType;
  external isRequired : propType => propType = "isRequired" [@@bs.get];
  external string : propType = "React.PropTypes.string" [@@bs.val];
  external bool : propType = "React.PropTypes.bool" [@@bs.val];
  external any : propType = "React.PropTypes.any" [@@bs.val];
  external oneOfType : array propType => propType = "React.PropTypes.oneOfType" [@@bs.val];
  external oneOf : array string => propType = "React.PropTypes.oneOf" [@@bs.val];
  external element : propType = "React.PropTypes.element" [@@bs.val];
  external func : propType = "React.PropTypes.func" [@@bs.val];
  external objectOf : propType => propType = "React.PropTypes.objectOf" [@@bs.val];
  external arrayOf : propType => propType = "React.PropTypes.arrayOf" [@@bs.val];
  external instanceOf : propType => propType = "React.PropTypes.instanceOf" [@@bs.val];
  external shape : Js.t 'shape => propType = "React.PropTypes.shape" [@@bs.val];
};
