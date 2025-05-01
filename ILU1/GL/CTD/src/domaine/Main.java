package domaine;

public class Main {
	public static void main(String[] args) {
		Biblio biblio = new Biblio(50);
		Ouvrage ouvrage = new Ouvrage("Beginning Software Engineering", "Rod Stephens", "wrox", 2015, "918");
		Examplaire examplaire = new Examplaire("C_BSE_1");
	}
}
