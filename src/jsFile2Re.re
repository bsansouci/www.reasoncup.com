/*
 * vim: set ft=rust:
 * vim: set ft=reason:
 */
 
external comp : React.reactElement = "./jsReactMotionDemo" [@@bs.module];

external props : name::string? => unit => 'b = "" [@@bs.obj];
