
type ('before, 'getValue, 'setValue, 'after) t

val make : ('before -> 'getValue) -> ('before -> 'setValue -> 'after) -> ('before, 'getValue, 'setValue, 'after) t

val get : 'before -> ('before, 'getValue, 'setValue, 'after) t-> 'getValue

val set : 'before -> ('before, 'getValue, 'setValue, 'after) t-> 'setValue -> 'after

val over : 'before -> ('before, 'getValue, 'setValue, 'after) t-> ('getValue -> 'setValue) -> 'after

val dot : ('before, 'getValue, 'setValue, 'after) t 
    -> ('getValue, 'newGetValue, 'newSetValue, 'setValue) t 
    -> ('before, 'newGetValue, 'newSetValue, 'after) t

(* val traversed : ('b, 'a array, 'b array, ) t -> ('o, 'a array, 'a -> 'b) t *)

