package navire;

import java.util.Arrays;

public class Bateau {
	private String nom;
	private int taille;
	private Element[] elements;

	@Override
	public String toString() {
		return "Bateau [nom=" + nom + ", taille=" + taille + ", elements=" + Arrays.toString(elements) + "]";
	}

	public Bateau(String nom, int taille) {
		this.nom = nom;
		this.taille = taille;
		elements = new Element[taille];
	}
	
	public String getNom() {
		return nom;
	}
	
	public static void main(String[] args) {
		
	}
}
