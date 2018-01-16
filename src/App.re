type state = ReasonReact.reactElement;

type action =
  | ChangeRoute(ReasonReact.reactElement);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: () => <Home />,
  reducer: (action, state) =>
    switch action {
    | ChangeRoute(component) => ReasonReact.Update(component)
    },
  subscriptions: ({send}) => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(
          (url) => {
            let newRoute =
              switch url.path {
              | [] => <Home />
              | ["about"] => <About />
              | _ => <NotFound />
              };
            send(ChangeRoute(newRoute))
          }
        ),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: ({state}) => <div> state </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));