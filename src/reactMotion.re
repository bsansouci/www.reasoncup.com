/*
 * vim: set ft=rust:
 * vim: set ft=reason:
 */
 
external spring : 'a => 'a = "spring" [@@bs.module "react-motion"];

let module Motion = {
  external comp : React.reactElement = "Motion" [@@bs.module "react-motion"];
  external props : style::'a? => unit => 'b = "" [@@bs.obj];
};

let module StaggeredMotion = {
  external comp : React.reactElement = "StaggeredMotion" [@@bs.module "react-motion"];
  external props : defaultStyles::'styleT => style::('styleT => 'styleT)? => unit => 'c = "" [@@bs.obj];
};
