type dom;

type element;

[@bs.val] external window : 'a = "window";

[@bs.val] external dom : dom = "document";

[@bs.scope "window"] [@bs.val] external window_location : string = "location";

[@bs.scope ("window", "location")] [@bs.val] external window_location_pathname : string =
  "pathname";

[@bs.send] external getElementById : (dom, string) => element = "getElementById";

[@bs.val] external requireAssetURI : string => string = "require";

[@bs.val] external import : string => Js.Promise.t('a) = "";

[@bs.val] external nodeEnv : string = "process.env.NODE_ENV";

[@bs.val] external browserEnv : bool = "process.browser";

[@bs.val] external parseInt : (string, int) => int = "";

[@bs.val] external hot : bool = "module.hot";

[@bs.val] external accept : unit => unit = "module.hot.accept";

let parseInt_ = (int, string) => parseInt(string, int);

let isPROD = nodeEnv === "production";

let isDEV = nodeEnv !== "production";

let isBrowser = browserEnv;

let text = ReasonReact.stringToElement;