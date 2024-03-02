(* Generated by re2c *)
(* re2ocaml $INPUT -o $OUTPUT -i *)

type state = {
    str: string;
    mutable cur: int;
}


let rec yy0 (st : state) : bool =
	let yych = st.str.[st.cur] in
	st.cur <- st.cur + 1;
	match yych with
		| '1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9' -> (yy2 [@tailcall]) st
		| _ -> (yy1 [@tailcall]) st

and yy1 (st : state) : bool =
	false

and yy2 (st : state) : bool =
	let yych = st.str.[st.cur] in
	match yych with
		| '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9' ->
			st.cur <- st.cur + 1;
			(yy2 [@tailcall]) st
		| _ -> (yy3 [@tailcall]) st

and yy3 (st : state) : bool =
	true

and lex (st : state) : bool =
	(yy0 [@tailcall]) st



let main () =
    let st = {str = "1234\x00"; cur = 0}
    in if not (lex st) then raise (Failure "error")

let _ = main ()
