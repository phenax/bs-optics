
type ('o,'v) t = (('o -> 'v)* ('o -> 'v -> 'o))

val make : ('o -> 'v) -> ('o -> 'v -> 'o) -> ('o,'v) t

val get : 'a -> ('a,'b) t -> 'b

val set : 'a -> ('a,'b) t -> 'b -> 'a

val over : 'a -> ('a,'b) t -> ('b -> 'b) -> 'a

val dot : ('o,'a) t -> ('a,'b) t -> ('o,'b) t

