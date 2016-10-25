/*
 * vim: set ft=rust:
 * vim: set ft=reason:
 */

type element;
external getElementById : string => element = "document.getElementById" [@@bs.val];
