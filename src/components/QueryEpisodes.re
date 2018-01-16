module AllEpisodesQuery = [%graphql
  {|
  query getEpisodes($first: Int) {
    allEpisodes(first: $first) {
      id
      title
    }
  }
|}
];

module Query = Client.Instance.Query;

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) => {
    let allEpisodesQuery = AllEpisodesQuery.make(~first=3, ());
    <Query query=allEpisodesQuery>
      (
        (response, parse) =>
          switch response {
          | Loading => <div> (Utils.text("Loading")) </div>
          | Failed(error) => <div> (Utils.text(error)) </div>
          | Loaded(result) =>
            let episodes = parse(result)##allEpisodes;
            <div>
              (
                ReasonReact.arrayToElement(
                  Array.map(
                    (episode) => <div key=episode##id> (Utils.text(episode##title)) </div>,
                    episodes
                  )
                )
              )
            </div>
          }
      )
    </Query>
  }
};