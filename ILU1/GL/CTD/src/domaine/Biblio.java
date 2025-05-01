package domaine;

public class Biblio {
	private int nbOuvrages = 0;
	private Ouvrage ouvrages[];
	
	public Biblio(int nbMaxOuvrages) {
		this.ouvrages = new Ouvrage[nbMaxOuvrages];
	}

	public int getNbOuvrages() {
		return nbOuvrages;
	}

	public Ouvrage[] getOuvrages() {
		return ouvrages;
	}
}
