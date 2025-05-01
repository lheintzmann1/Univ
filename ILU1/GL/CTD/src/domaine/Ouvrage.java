package domaine;

public class Ouvrage {
	private String titre;
	private String auteur;
	private String editeur;
	private int annee;
	private String isbn;
	private int nbExemplaires = 0;
	private Examplaire lesExemplaires[];
	private static final int NB_MAX_EXEMPLAIRES = 50;
	
	public Ouvrage(String titre, String auteur, String editeur, int annee, String isbn) {
		this.titre = titre;
		this.auteur = auteur;
		this.editeur = editeur;
		this.annee = annee;
		this.isbn = isbn;
	}
	
	public String getEditeur() {
		return editeur;
	}

	public String getTitre() {
		return titre;
	}

	public String getAuteur() {
		return auteur;
	}

	public int getAnnee() {
		return annee;
	}

	public String getIsbn() {
		return isbn;
	}

	public int getNbExemplaires() {
		return nbExemplaires;
	}

	public Examplaire[] getLesExemplaires() {
		return lesExemplaires;
	}

	public static int getNbMaxExemplaires() {
		return NB_MAX_EXEMPLAIRES;
	}
}
