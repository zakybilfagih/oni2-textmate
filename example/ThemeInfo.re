type themeLocation = {
  name: string,
  path: string,
};

module StringMap =
  Map.Make({
    type t = string;
    let compare = String.compare;
  });
type t = StringMap.t(string);

let initial = StringMap.empty;

let getThemePathFromName = (v: t, scope: string) => {
  StringMap.find_opt(scope, v);
};

let ofThemeLocations = (locations: list(themeLocation)) => {
  List.fold_left(
    (prev, curr) => {StringMap.add(curr.name, curr.path, prev)},
    StringMap.empty,
    locations,
  );
};
