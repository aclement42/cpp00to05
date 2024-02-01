les cast partent tous d'une la conversion: permetde transformer les bits d'une valeurvers le codage d'une autre valeur/d'un auttre type
afin de pouvoir convertir cette valeur 

type de conversion particuliere : la convesion indentitaire -->les bits apres conversion n'ont pas ete reorga
==== ca s'apelle une reinterpretation!

les reinterpretations permettent de pouvoir travailler avec des ypes d'adresses plus generiques, pluprecis
Il existe des types de reinterpretation particuluers : 
*UPCAST DOWNCAST , permettent de naviguer dans une hierarchie verticale de classe
*possible de reinterpreter un type sur le qualifer de type, pour pouvoir ajouter le mot de clef CONST

toutes ces actions propse 5 cast: LEQUEL CHOISIR


-------------------------------------------------------------------------
CAST                | CONV | REINT  | UPCAST |   DOWNCAST|   TYPE QUAL |
********************|******|********|********|***********|*************|*
implicit            |YES   |        | YES    |           |             |  //fonctionne dans des contexte de conversions et d'UPcast
static_cast         |YES   |        | YES    | YES       |             |  //fonctionne dans la conversion de valeurs simples, et UP/DOWNcast ou nous savons d'ou nous venons ET ou nous allons. permet d'empecer entre des classes qui ne sont pas du meme arbre d'heritage       
dynamic_cast        |      |        | YES    | YES       |             |  //fonctionne pdt l'exec, permet RTTI ; il faut que la classe concernee est au moins une fonction membre virtuelle : Permet verifie si le transfere d'un etage alautre une hierarchie de classe est realiste ,si je veux down dune mere vers une fille mais que jsp en avance si le type reel de la mere est bien la fille en question    
const_cast          |      |        |        |           | YES         |  //seul qui permet de faire des reinterpretations de qualifer de types; CAST A PEU UTILISER , uniquement erreur de design !
reinterpret_cast    |      | YES    | YES    | YES       |             |  //le plus libre, permet de faire des reintepretations, down/upcast sans aucun check (elephat dans souris avec consequences qui sen suivent!!)      
-------------------------------------------------------------------------
Legacy C cast       | YES  | YES    | YES    | YES       | YES         |  //on sait jamais ce que le cast c utilise donc JAMAIS A UTILISER
-------------------------------------------------------------------------

-------------------------------------------------------------------------
CAST                | Semantic cast | Reliable at run    | Tested at run |*est ce quils ont une verif semantic ? *une fois prgm compiler est ce prgm bien se derouler?  *est il tester au run time?
********************|***************|********************|***************|
implicit            |YES            | YES                |               |  
static_cast         |YES            |                    |               |          
dynamic_cast        |YES            | YES                | YES           |          
const_cast          |               |                    |               |  
reinterpret_cast    |               |                    |               |         
-------------------------------------------------------------------------
Legacy C cast       |               |                    |             |
-------------------------------------------------------------------------