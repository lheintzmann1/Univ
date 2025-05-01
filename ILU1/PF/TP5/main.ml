
let rec insertObj o lst =
  match lst with
  | [] -> [(1, o)]
  | (n, obj) :: tl when obj = o -> (n + 1, obj) :: tl
  | hd :: tl -> hd :: insertObj o tl

let rec insert p o lst =
  match lst with
  | [] -> [(p, [1, o])]
  | (idx, objs) :: tl when idx = p -> (idx, insertObj o objs) :: tl
  | hd :: tl -> hd :: insert p o tl

let decompte lst =
  let rec aux acc = function
    | [] -> acc
    | (p, o) :: tl -> aux (insert p o acc) tl
in
aux [] lst

let longueur lst =
  List.fold_left (fun acc (n, _) -> acc + n) 0 lst

let aumoins_indexed n lst =
  List.fold_right 
    (fun (idx, objs) acc -> 
      if longueur objs >= n then idx :: acc else acc) 
    lst 
    []

let aumoins n lst =
  aumoins_indexed n (decompte lst)

  let musee = [
    "Astérix", "bouclier";
    "Astérix", "casque";
    "Astérix", "bouclier";
    "Astérix", "casque";
    "Astérix", "casque";
    "Obélix", "bouclier";
    "Obélix", "casque"
]

(* Test decompte *)
let result = decompte musee;;
(* Should output something like:
   [("Astérix", [(3, "casque"); (2, "bouclier")]); 
    ("Obélix", [(1, "casque"); (1, "bouclier")])] *)

(* Find Gauls with at least 2 trophies *)
let gaulois_avec_2_trophees = aumoins 2 musee;;
(* Should output ["Astérix"] *)


