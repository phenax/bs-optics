let ($) f x = f x

let (<<) f g x = f (g x)

let (++) s1 s2 = String.concat s1 [""; s2]

let id x = x

