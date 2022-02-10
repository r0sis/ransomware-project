/**
* Cete fonction est une fonction de modification ou remplissage de chaine de caractère de certaines valeures.
* PARAMETRES: 
*	      param_1: un entier non signé qui va servir de valeur de boucle et de paramètre de mise a jour du contenu du deuxième paramètre.
*	      param_2: une chaine de caractères dont le contenu va être modifier tout au long de la fonction.
* RETOURNE: rien
**/
void FUN_00401758(uint param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  // On teste la conformité des paramètres avant toute chose
  // Si le paramètre d'entré 1 est a 0 on met 0 comme contenu du deuxième
  if (param_1 == 0) {
    *param_2 = '0';
  }
  
  else {
    pcVar2 = param_2; // On fait une copie du contenu du paramètre 2 pour le manipuler sans risque
    if ((int)param_1 < 0) { // Si le paramètre 1 est sup à 0
    	// On met à jour le contenu des paramètres et de la copie du paramètre 2
      *param_2 = '-'; // On change le premier caractère
      param_1 = -param_1; // On passe sa valeur en négatif
      param_2 = param_2 + 1; // On lui donne l'adresse suivante
      pcVar2 = param_2; // On met à jour la copie
    }
    // Boucle sur la valeur du paramètre 1 visant à remplir les cases du paramètre 2
    while (param_1 != 0) {
      *param_2 = (char)param_1 + (char)(param_1 / 10) * -10 + '0'; // A vérifier
      param_2 = param_2 + 1;
      param_1 = param_1 / 10;
    }
    for (; pcVar2 < param_2; pcVar2 = pcVar2 + 1) {
      param_2 = param_2 + -1; // On met à jour l'adresse du paramètre 2
      cVar1 = *param_2; // On copie le premier caractère du paramètre 2
      *param_2 = *pcVar2; // On copie le premier caractère de la copie dans la première case du paramètre 2
      *pcVar2 = cVar1; // On met a jour le premier caractère de la copie avec celui précédemment sauvegardé
    }
  }
  return;
}
