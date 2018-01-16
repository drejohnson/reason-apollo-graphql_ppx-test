let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: (_self) => <div> <Hello message="Hello from about component" /> </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));