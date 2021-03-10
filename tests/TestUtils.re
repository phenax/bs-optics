open Utils

module Comment = {
  type t = {
    id: int,
    text: string,
    comments: array(t),
  }

  let id = Lens.make(o => o.id, (o, n) => { ...o, id: n })
  let text = Lens.make(o => o.text, (o, n) => { ...o, text: n })
  let comments = Lens.make(o => o.comments, (o, n) => { ...o, comments: n })
}

module Post = {
  type t = {
    title: string,
    comments: array(Comment.t),
    tags: list(string),
  }

  let title = Lens.make(o => o.title, (o, n) => { ...o, title: n })
  let comments = Lens.make(o => o.comments, (o, n) => { ...o, comments: n })
  let tags = Lens.make(o => o.tags, (o, n) => { ...o, tags: n })

  // TODO: Temporary test helper. Remove after Array Prism is done
  let firstComment = Lens.make(o => o.comments[0], (o, c) => {
    ...o,
    comments: Belt.Array.concat([|c|], o.comments->Js.Array.sliceFrom(1, _)),
  })
}

let dummyPost: Post.t = {
  title: "Yolo mofo",
  comments: [|
    { id: 1, text: "duck my sick", comments: [||] },
    { id: 2, text: "fothermucka", comments: [||] },
    { id: 3, text: "sullbhit", comments: [||] },
  |],
  tags: ["hello", "world", "foo", "bar"],
}

let stringLens: Lens.t(string, string) = Lens.make(id, (o, k) => o ++ k)

