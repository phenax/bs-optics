open TestFramework
/*open Utils*/
open TestUtils

describe("Lens.get", ({test, _}) => {
  test("should get value with lens (identity lens)", ({expect, _}) => {
    let value = "yoyo"->Lens.get(stringLens);
    expect.string(value).toEqual("yoyo");
  });

  test("should get value with lens (record)", ({expect, _}) => {
    let value = dummyPost->Lens.get(Post.title);
    expect.string(value).toEqual("Yolo mofo");
  });
});

describe("Lens.set", ({test, _}) => {
  test("should set value with lens (identity lens)", ({expect, _}) => {
    let value = "foobar"->Lens.set(stringLens, "newval");
    expect.string(value).toEqual("foobarnewval");
  });

  test("should set value with lens (record)", ({expect, _}) => {
    let value = dummyPost->Lens.set(Post.title, "Hello world");
    expect.value(value).toEqual({ ...dummyPost, title: "Hello world" });
  });
});

describe("Lens.over", ({test, _}) => {
  test("should update value with lens (identity lens)", ({expect, _}) => {
    let value = "foobar"->Lens.over(stringLens, x => x ++ "::1");
    expect.string(value).toEqual("foobarfoobar::1");
  });

  test("should update value with lens (record)", ({expect, _}) => {
    let value = dummyPost->Lens.over(Post.title, x => x ++ "::1");
    expect.value(value).toEqual({ ...dummyPost, title: "Yolo mofo::1" });
  });
});

describe("Lens.dot", ({test, _}) => {
  let firstCommentText = Post.firstComment->Lens.dot(Comment.text);

  test("should allow getting nested values", ({expect, _}) => {
    let value = dummyPost->Lens.get(firstCommentText);
    expect.string(value).toEqual("duck my sick");
  });

  test("should allow setting nested values", ({expect, _}) => {
    let value = dummyPost->Lens.set(firstCommentText, "changed to this");
    expect.value(value.comments[0]).toEqual({
      ...value.comments[0],
      text: "changed to this",
    });
  });
});


