let component = ReasonReact.statelessComponent("NotFound");

let make = (_children) => {
  ...component,
  render: (_self) => <div> <Hello message="Page not found" /> </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));