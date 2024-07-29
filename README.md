# Lire ou ne pas lire, telle est la question
## Comparer la longueur de titres de livres
Les employés de la bibliothèque, constamment entourés de livres, n’ont jamais le temps de lire tous les livres qu’ils souhaiteraient. Chacun a donc mis au point son propre algorithme de sélection, et l’un d’entre eux a choisi un système basé sur la longueur des titres des livres !
Sur une étagère sont alignés tous les livres qui l’intéressent. Chaque mois, cette personne commence par lire le premier livre présent sur l’étagère, puis le second et ainsi de suite jusqu’à la fin. Seulement, elle ne lira un livre que si son titre est strictement plus long que ceux de tous les livres qu’elle a lus pendant le mois. Si ce n’est pas le cas, elle enlève le livre de l’étagère, sans le lire.
Étant donnée une liste de titres de livres possibles pour le mois suivant, donnés dans l’ordre où ils apparaissent dans l’étagère, vous devez déterminer lesquels elle va lire.

### CONSTRAINTS
Chaque titre de livre contiendra au plus 1000 caractères.
### INPUT
Sur la première ligne, un entier nbLivres, le nombre total de livres.
Les nbLivres lignes suivantes contiennent chacune un titre de livre.

### OUTPUT
La liste des titres respectant la règle donnée dans l’énoncé.

### EXAMPLE

input:
6
Les Facheux
Le Malade imaginaire
Les Femmes savantes
Les Fourberies de Scapin
L'Avare
Le Bourgeois gentilhomme

output:
Les Facheux
Le Malade imaginaire
Les Fourberies de Scapin
## Explication du démarche de code 

* On demande à l'utilisateur de saisir le nombre total de livres, et on le stocke dans nbLivres.
* getchar() est utilisé pour consommer le caractère de nouvelle ligne restant dans le buffer après l'appel à scanf. Cela évite des problèmes lors de la lecture des lignes de texte suivantes avec fgets.
* Ttitre est un tableau de caractères qui stockera temporairement le titre du livre en cours de lecture. La taille maximale d'un titre est 1000 caractères, donc nous utilisons une taille de 1001 pour inclure le caractère nul de fin de chaîne ('\0).
* max_length est une variable qui stocke la longueur du titre le plus long qui a été lu jusqu'à présent.
* Tlus est un tableau à deux dimensions pour stocker les titres des livres lus.
* lus_count est un compteur pour garder une trace du nombre de livres lus.
* On lit chaque titre de livre avec fgets et on stocke le titre dans Ttitre.
* strcspn(Ttitre, "\n") trouve la position du caractère de nouvelle ligne ('\n') dans Ttitre, et nous le remplaçons par le caractère nul ('\0') pour enlever la nouvelle ligne de la fin du titre.
* strlen(Ttitre) calcule la longueur du titre actuel.
* Enfin, on affiche tous les titres stockés dans Tlus en utilisant une boucle pour parcourir le tableau jusqu'à lus_count.

Si la longueur du titre actuel est plus grande que max_length, on copie ce titre dans le tableau Tlus à l'index lus_count et on incrémente lus_count. On met également à jour max_length avec la nouvelle longueur.
Supposons que l'entrée soit la suivante :
6
Les Facheux
Le Malade imaginaire
Les Femmes savantes
Les Fourberies de Scapin
L'Avare
Le Bourgeois gentilhomme
Initialisation :

nbLivres = 6
max_length = 0
lus_count = 0
Étapes de la boucle :

Titre : "Les Facheux"
Longueur = 10
10 > 0 → Ajouté à Tlus
max_length = 10
lus_count = 1
Titre : "Le Malade imaginaire"
Longueur = 20
20 > 10 → Ajouté à Tlus
max_length = 20
lus_count = 2
Titre : "Les Femmes savantes"
Longueur = 19
19 <= 20 → Non ajouté
Titre : "Les Fourberies de Scapin"
Longueur = 23
23 > 20 → Ajouté à Tlus
max_length = 23
lus_count = 3
Titre : "L'Avare"
Longueur = 7
7 <= 23 → Non ajouté
Titre : "Le Bourgeois gentilhomme"
Longueur = 24
24 > 23 → Ajouté à Tlus
max_length = 24
lus_count = 4
Affichage final :

"Les Facheux"
"Le Malade imaginaire"
"Les Fourberies de Scapin"
"Le Bourgeois gentilhomme"

### But du Code
Le but de ce programme est de déterminer quels titres de livres seront lus par un employé de bibliothèque, en fonction de la longueur des titres. L'employé lira un livre uniquement si son titre est strictement plus long que tous les titres des livres qu'il a déjà lus ce mois-ci.