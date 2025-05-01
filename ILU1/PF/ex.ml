

let estZero_v1 n =
  match n with
  | 0 -> "zero"
  | _ -> "nonZero"

let estZero_v2 n =
    if n != 0 then "nonZero" else "zero"

let voyelle c =
    match c with
    | 'a' | 'e' | 'i' | 'o' | 'u' | 'y' -> true
    | _ -> false

let rang jourDeLaSemaine =
    match jourDeLaSemaine with
    | "lundi" -> 1
    | "mardi" -> 2
    | "mercredi" -> 3
    | "jeudi" -> 4
    | "vendredi" -> 5
    | "samedi" -> 6
    | "dimanche" -> 7
    | _ -> 0

let inf jour1 jour2 =
    match jour1, jour2 with
    | "lundi", "mardi" -> true
    | "mardi", "mercredi" -> true
    | "mercredi", "jeudi" -> true
    | "jeudi", "vendredi" -> true
    | "vendredi", "samedi" -> true
    | "samedi", "dimanche" -> true
    | "dimanche", "lundi" -> true
    | _, _ -> false

let jsem n =
    match n with
    | 1 -> "lundi"
    | 2 -> "mardi"
    | 3 -> "mercredi"
    | 4 -> "jeudi"
    | 5 -> "vendredi"
    | 6 -> "samedi"
    | 7 -> "dimanche"
    | _ -> "jour inconnu"

let jourSucc1 jour =
    match jour with
    | "lundi" -> "mardi"
    | "mardi" -> "mercredi"
    | "mercredi" -> "jeudi"
    | "jeudi" -> "vendredi"
    | "vendredi" -> "samedi"
    | "samedi" -> "dimanche"
    | "dimanche" -> "lundi"
    | _ -> "jour inconnu"

let jourSucc2 jour =
    let rangJour = rang jour in
    if rangJour = 0 then "jour inconnu"
    else jsem ((rangJour mod 7) + 1)

let jourSucc3 jour =
    let rangJour = rang jour in
    if rangJour = 0 then "jour inconnu"
    else jsem (if rangJour = 7 then 1 else rangJour + 1)

let jourPred1 jour =
    match jour with
    | "lundi" -> "dimanche"
    | "mardi" -> "lundi"
    | "mercredi" -> "mardi"
    | "jeudi" -> "mercredi"
    | "vendredi" -> "jeudi"
    | "samedi" -> "vendredi"
    | "dimanche" -> "samedi"
    | _ -> "jour inconnu"

let jourPred2 jour =
    let rangJour = rang jour in
    if rangJour = 0 then "jour inconnu"
    else jsem ((rangJour + 5) mod 7 + 1)

let jourPred3 jour =
    let rangJour = rang jour in
    if rangJour = 0 then "jour inconnu"
    else jsem (if rangJour = 1 then 7 else rangJour - 1)

let bissextile annee =
    let divisible4 = annee mod 4 = 0 in
    let divisible100 = annee mod 100 = 0 in
    let divisible400 = annee mod 400 = 0 in
    divisible4 && (not divisible100 || divisible400)

let nbjour mois annee =
    match mois with
    | 1 | 3 | 5 | 7 | 8 | 10 | 12 -> 31
    | 4 | 6 | 9 | 11 -> 30
    | 2 -> if bissextile annee then 29 else 28
    | _ -> failwith "mois invalide"



