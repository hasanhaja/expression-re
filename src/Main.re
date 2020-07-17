let expression = "2 + 2 * 4";

/**
 * [2 + 2]" -> [+ 2 2]
 *  [2 + 2 * 4] -> [2 + [2 * 4]] -> [+ 2 [* 2 4]] -flat-> [+ * 2 4 2] -> [+ 8 2] -> [10]
 * An evaluatable expression has one operator and many subexpressions. If the expression has no operators, it considered to be in a completed state.
 */

/**
 * @function This function tokenizes the based on the space between elements.
 * TODO Handle expressions without spaces.
 */
let tokenize = expression => {
  expression |> Js.String.split(" ");
};

/**
 * TODO We'll need to support floats later
 */
type token =
  | Value(int)
  | Add
  | Multiply;

let matchToken = token => {
  switch (token) {
  | "+" => Add
  | "*" => Multiply
  | _ => token->Belt.Int.fromString->Belt.Option.getExn->Value
  };
};

let parseTokens = tokens => {
  tokens->Belt.Array.map(token => matchToken(token));
};

let evaluate = expression => {
  10;
};

// evaluate(expression) |> Js.log;
tokenize(expression) |> parseTokens |> Js.log;
