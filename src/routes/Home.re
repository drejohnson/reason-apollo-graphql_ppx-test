let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) => <div> <Hello message="Hello from home component" /> <QueryEpisodes /> </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));