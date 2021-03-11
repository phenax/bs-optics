open Utils;;

type ('before, 'getValue, 'setValue, 'after) t = (('before -> 'getValue) * ('before -> 'setValue -> 'after))

let make get set = (get, set)

let get obj  (get,_) = get obj
let set obj (_, set) value = set obj value

let over obj lens fn = set obj lens << fn << get obj $ lens

let dot l1 l2 = make
    (fun o -> get (get o l1) l2)
    (fun o v -> over o l1 $ fun o -> set o l2 v)

(* let traversed l = make
    (fun o -> get o l)
    (fun o fn -> over o l $ Array.map fn) *)
