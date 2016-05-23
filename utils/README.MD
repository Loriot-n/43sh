Fonctionnement de la moulinette:

Le répertoire doit contenir :
  tests 	=> le fichier décrivant la liste des tests à exécuter
  moul.sh	=> la moulinette
  42sh		=> le shell

Le fichier de tests contient une liste de tests numerotés.
Un test est compris entre 2 balises :
[42]		=> début du test 42
[42-END]	=> fin du test 42

SETUP="script"	=> script qui est exécuté avant de lancer le test
NAME="name"     => nom du test
CLEAN="script"  => script qui est exécuté après l'exécution du test

TESTS=		=> les lignes qui suivent sont un script bash affichant la liste des commandes à envoyer dans le shell


Fonctionnement :
./moul.sh	=> sans paramètres : tous les tests du fichier seront exécuté les uns après les autres + debug pour les tests KO seulement
./moul.sh 42	=> avec un paramètre : seul le test passé en paramètre sera exécuté
./moul.sh -d 42 => mode debug : affichage de l'output du 42sh et du shell de référence
./moul.sh 0     => génération du manifest.json pour Jenkins comprenant l'intégralité des tests

La moulinette lance les tests dans le tcsh, puis dans le 42sh et compare les résultats.

