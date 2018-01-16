[%bs.raw "require('isomorphic-unfetch')"];

open ApolloLinks;

open ApolloInMemoryCache;

/* Create an HTTP Link */
module HttpLink =
  CreateHttpLink(
    {
      let uri = "https://api.graph.cool/simple/v1/PHRESHR";
    }
  );

module InMemoryCache =
  CreateInMemoryCache(
    {
      type dataObject;
      let inMemoryCacheObject = Js.Nullable.undefined;
    }
  );

module Instance =
  ReasonApollo.CreateClient(
    {
      let apolloClient =
        ReasonApollo.createApolloClient(~cache=InMemoryCache.cache, ~link=HttpLink.link, ());
    }
  );