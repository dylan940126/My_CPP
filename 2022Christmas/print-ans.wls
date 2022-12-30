#!/usr/bin/env wolframscript

(* Wolfram Script *)
(* Created by the Wolfram Language Plugin for IntelliJ, see http://wlplugin.halirutan.de/ *)
(* :Author: suen3 *)
(* :Date: 2022-12-29 *)

Close[inp];
inp = OpenRead["./ans.txt"];
For[i = 0, True, i++,
  arr = {};
  For[j = 0, j < 7, j++,
    in = Read[inp, {Number, Number, Number, Number, Number, Number, Number}];
    AppendTo[arr, in];];
  If[in == EndOfFile, Break[], Null];
  out = ArrayPlot[arr,
    ColorRules -> {0 -> Gray, 1 -> Red, 2 -> Orange, 3 -> Yellow,
      4 -> Green, 5 -> Blue, 6 -> Brown, 7 -> Magenta, 8 -> Cyan},
    Mesh -> True];
  Export["./jpgs/out" <> ToString[i] <> ".png", out];
  Print["Finish " <> ToString[i]]
]